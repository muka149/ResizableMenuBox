// Fill out your copyright notice in the Description page of Project Settings.


#include "ResizableMenuBox.h"
#include "Components/CanvasPanelSlot.h"

/// <summary>
/// スロット追加
/// </summary>
/// <param name="InSlot"></param>
void UResizableMenuBox::OnSlotAdded(UPanelSlot* InSlot)
{
	// Add the child to the live canvas if it already exists
	if (MyMenuBox.IsValid())
	{
		CastChecked<UCanvasPanelSlot>(InSlot)->BuildSlot(MyMenuBox.ToSharedRef());
	}
}

/// <summary>
/// スロット削除
/// </summary>
/// <param name="InSlot"></param>
void UResizableMenuBox::OnSlotRemoved(UPanelSlot* InSlot)
{
	// Remove the widget from the live slot if it exists.
	if (MyMenuBox.IsValid() && InSlot->Content)
	{
		TSharedPtr<SWidget> Widget = InSlot->Content->GetCachedWidget();
		if (Widget.IsValid()){
			MyMenuBox->RemoveSlot(Widget.ToSharedRef());
		}
	}
}

/// <summary>
/// リビルド
/// </summary>
/// <returns></returns>
TSharedRef<SWidget> UResizableMenuBox::RebuildWidget()
{
	MyMenuBox = SNew(SResizableMenuBox)
		.SplitType(SplitType)
		.OnSplitterMoved(BIND_UOBJECT_DELEGATE(FOnSplitterMoved, ResizeMenu));

	for (UPanelSlot* panel_slot : Slots)
	{
		if (UCanvasPanelSlot* typed_slot = Cast<UCanvasPanelSlot>(panel_slot))
		{
			typed_slot->Parent = this;
			typed_slot->BuildSlot(MyMenuBox.ToSharedRef());
		}
	}

	return MyMenuBox.ToSharedRef();
}

/// <summary>
/// スレート解放
/// </summary>
/// <param name="bReleaseChildren"></param>
void UResizableMenuBox::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);

	MyMenuBox.Reset();
}

/// <summary>
/// エディタ上でのプロパティ内容反映
/// </summary>
void UResizableMenuBox::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	if (MyMenuBox.IsValid())
	{
		int32 slot_num = Slots.Num();

		for (int32 i = 0; auto& panel_slot : Slots)
		{
			int32 split_num = SplitRatio.Num();
			if (split_num < slot_num - 1)
			{
				SplitRatio.Add(0.5f);
			}
			else if (split_num > slot_num - 1)
			{
				SplitRatio.RemoveAt(split_num - 1);
			}

			auto canvas_slot = Cast<UCanvasPanelSlot>(panel_slot);
			if (canvas_slot)
			{
				float min = i == 0 ? 0.f : static_cast<float>(i) / slot_num;
				float max = (i + static_cast<float>(1)) / slot_num;

				if (SplitType == ESplitType::Horizontal)
				{
					canvas_slot->SetAnchors(FAnchors(min, 0.f, max, 1.f));
					canvas_slot->SetOffsets(FMargin(0.f));
				}
				else
				{
					canvas_slot->SetAnchors(FAnchors(0.f, min, 1.f, max));
					canvas_slot->SetOffsets(FMargin(0.f));
				}
			}

			++i;
		}
	}

	for (int32 i = 0; auto& elem : SplitRatio)
	{
		auto canvas_slot_1 = Cast<UCanvasPanelSlot>(Slots[i]);
		auto canvas_slot_2 = Cast<UCanvasPanelSlot>(Slots[i + 1]);

		FAnchors anchors_1 = canvas_slot_1->GetAnchors();
		FAnchors anchors_2 = canvas_slot_2->GetAnchors();

		FAnchors splitter_anchors = FAnchors(0.0f);

		if (SplitType == ESplitType::Horizontal)
		{
			float learp_anchors = LerpValue(elem, anchors_1.Minimum.X, anchors_2.Maximum.X);

			anchors_1.Maximum.X = learp_anchors;
			anchors_2.Minimum.X = learp_anchors;

			splitter_anchors = FAnchors(learp_anchors - SPLITTER_HALF_THICKNESS, 0.f, learp_anchors + SPLITTER_HALF_THICKNESS, 1.f);
		}
		else
		{
			float learp_anchors = LerpValue(elem, anchors_1.Minimum.Y, anchors_2.Maximum.Y);

			anchors_1.Maximum.Y = learp_anchors;
			anchors_2.Minimum.Y = learp_anchors;

			splitter_anchors = FAnchors(0.f, learp_anchors - SPLITTER_HALF_THICKNESS, 1.f, learp_anchors + SPLITTER_HALF_THICKNESS);
		}
		
		canvas_slot_1->SetAnchors(anchors_1);
		canvas_slot_2->SetAnchors(anchors_2);
		canvas_slot_1->SetOffsets(0.f);
		canvas_slot_2->SetOffsets(0.f);

		const FGuid id = FGuid::NewGuid();
		MyMenuBox->AddSplitter(splitter_anchors, id);
		SplitWidgetsMap.Add(id, MakeTuple(canvas_slot_1, canvas_slot_2));

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
/// <param name="ID"></param>
/// <param name="Anchors"></param>
/// <returns></returns>
bool UResizableMenuBox::ResizeMenu(const FGuid ID, const FAnchors Anchors)
{
	auto slot_tupple =  SplitWidgetsMap.FindRef(ID);
	auto canvas_slot_1 = slot_tupple.Key;
	auto canvas_slot_2 = slot_tupple.Value;

	if (canvas_slot_1 && canvas_slot_2)
	{
		FAnchors anchors_1 = canvas_slot_1->GetAnchors();
		FAnchors anchors_2 = canvas_slot_2->GetAnchors();

		
		if (SplitType == ESplitType::Horizontal)
		{
			if (anchors_2.Maximum.X <= Anchors.Maximum.X || anchors_1.Minimum.X >= Anchors.Minimum.X){
				return false;
			}

			anchors_1.Maximum.X = Anchors.Minimum.X;
			anchors_2.Minimum.X = Anchors.Maximum.X;
		}
		else
		{
			if (anchors_2.Maximum.Y <= Anchors.Maximum.Y || anchors_1.Minimum.Y >= Anchors.Minimum.Y) {
				return false;
			}

			anchors_1.Maximum.Y = Anchors.Minimum.Y;
			anchors_2.Minimum.Y = Anchors.Maximum.Y;
		}
		
		canvas_slot_1->SetAnchors(anchors_1);
		canvas_slot_2->SetAnchors(anchors_2);
		canvas_slot_1->SetOffsets(0.f);
		canvas_slot_2->SetOffsets(0.f);
	}

	return true;
}