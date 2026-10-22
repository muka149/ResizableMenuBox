// Fill out your copyright notice in the Description page of Project Settings.


#include "ResizableMenuBox.h"
#include "Components/CanvasPanelSlot.h"

/// <summary>
/// スロット追加
/// </summary>
/// <param name="in_slot">スロット</param>
void UResizableMenuBox::OnSlotAdded(UPanelSlot* in_slot)
{
	// Add the child to the live canvas if it already exists
	if (my_menu_box_.IsValid()){
		CastChecked<UCanvasPanelSlot>(in_slot)->BuildSlot(my_menu_box_.ToSharedRef());
	}
}

/// <summary>
/// スロット削除
/// </summary>
/// <param name="in_slot">スロット</param>
void UResizableMenuBox::OnSlotRemoved(UPanelSlot* in_slot)
{
	// Remove the widget from the live slot if it exists.
	if (my_menu_box_.IsValid() && in_slot->Content){

		TSharedPtr<SWidget> widget = in_slot->Content->GetCachedWidget();
		if (widget.IsValid()){
			my_menu_box_->RemoveSlot(widget.ToSharedRef());
		}
	}
}

/// <summary>
/// リビルド
/// </summary>
/// <returns>スレート</returns>
TSharedRef<SWidget> UResizableMenuBox::RebuildWidget()
{
	my_menu_box_ = SNew(SResizableMenuBox)
		.SplitType(SplitType)
		.OnSplitterMoved(BIND_UOBJECT_DELEGATE(FOnSplitterMoved, ResizeMenu));

	for (UPanelSlot* panel_slot : Slots){

		if (UCanvasPanelSlot* typed_slot = Cast<UCanvasPanelSlot>(panel_slot)){
			typed_slot->Parent = this;
			typed_slot->BuildSlot(my_menu_box_.ToSharedRef());
		}
	}

	return my_menu_box_.ToSharedRef();
}

/// <summary>
/// スレート解放
/// </summary>
/// <param name="should_release_children">子の解放判断</param>
void UResizableMenuBox::ReleaseSlateResources(bool should_release_children)
{
	Super::ReleaseSlateResources(should_release_children);
	my_menu_box_.Reset();
}

/// <summary>
/// エディタ上でのプロパティ内容反映
/// </summary>
void UResizableMenuBox::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	if (my_menu_box_.IsValid()){

		int32 slot_num = Slots.Num();

		for (int32 i = 0; auto& panel_slot : Slots){

			int32 split_num = SplitRatio.Num();
			if (split_num < slot_num - 1){
				SplitRatio.Add(0.5f);
			}
			else if (split_num > slot_num - 1){
				SplitRatio.RemoveAt(split_num - 1);
			}

			auto canvas_slot = Cast<UCanvasPanelSlot>(panel_slot);
			if (canvas_slot){

				float min = i == 0 ? 0.f : static_cast<float>(i) / slot_num;
				float max = (i + static_cast<float>(1)) / slot_num;

				if (SplitType == ESplitType::Horizontal){
					canvas_slot->SetAnchors(FAnchors(min, 0.f, max, 1.f));
					canvas_slot->SetOffsets(FMargin(0.f));
				}
				else{
					canvas_slot->SetAnchors(FAnchors(0.f, min, 1.f, max));
					canvas_slot->SetOffsets(FMargin(0.f));
				}
			}

			++i;
		}
	}

	for (int32 i = 0; auto& elem : SplitRatio){

		auto canvas_slot_1 = Cast<UCanvasPanelSlot>(Slots[i]);
		auto canvas_slot_2 = Cast<UCanvasPanelSlot>(Slots[i + 1]);

		FAnchors anchors_1 = canvas_slot_1->GetAnchors();
		FAnchors anchors_2 = canvas_slot_2->GetAnchors();

		FAnchors splitter_anchors = FAnchors(0.0f);

		if (SplitType == ESplitType::Horizontal){

			float learp_anchors = LerpValue(elem, anchors_1.Minimum.X, anchors_2.Maximum.X);
			anchors_1.Maximum.X = learp_anchors;
			anchors_2.Minimum.X = learp_anchors;
			splitter_anchors = FAnchors(learp_anchors, 0.f, learp_anchors, 1.f);
		}
		else{

			float learp_anchors = LerpValue(elem, anchors_1.Minimum.Y, anchors_2.Maximum.Y);
			anchors_1.Maximum.Y = learp_anchors;
			anchors_2.Minimum.Y = learp_anchors;
			splitter_anchors = FAnchors(0.f, learp_anchors, 1.f, learp_anchors);
		}
		
		canvas_slot_1->SetAnchors(anchors_1);
		canvas_slot_2->SetAnchors(anchors_2);
		canvas_slot_1->SetOffsets(0.f);
		canvas_slot_2->SetOffsets(0.f);


		const FGuid id = FGuid::NewGuid();
		my_menu_box_->AddSplitter(splitter_anchors, id);
		split_widget_map_.Add(id, MakeTuple(canvas_slot_1, canvas_slot_2));

		++i;
	}
}

/// <summary>
/// 線形補間
/// </summary>
/// <param name="ratio"></param>
/// <param name="min_val"></param>
/// <param name="max_val"></param>
/// <returns></returns>
float UResizableMenuBox::LerpValue(const float ratio, const float min_val, const float max_val)
{
	return min_val + ratio * (max_val - min_val);
}

/// <summary>
/// メニューのリサイズ
/// </summary>
/// <param name="id">ID</param>
/// <param name="offset_val">オフセット値</param>
void UResizableMenuBox::ResizeMenu(FGuid& id, float offset_val)
{
	auto slot_tupple = split_widget_map_.FindRef(id);
	auto canvas_slot_1 = slot_tupple.Key;
	auto canvas_slot_2 = slot_tupple.Value;

	if (canvas_slot_1 && canvas_slot_2){

		FMargin offsets_1 = canvas_slot_1->GetOffsets();
		FMargin offsets_2 = canvas_slot_2->GetOffsets();

		if (SplitType == ESplitType::Horizontal){

			offsets_1.Right = -offset_val;
			offsets_2.Left = offset_val;
		}
		else {

			offsets_1.Bottom = -offset_val;
			offsets_2.Top	 =  offset_val;
		}

		canvas_slot_1->SetOffsets(offsets_1);
		canvas_slot_2->SetOffsets(offsets_2);
	}
}