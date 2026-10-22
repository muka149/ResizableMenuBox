// Fill out your copyright notice in the Description page of Project Settings.


#include "SResizableMenuBox.h"
#include "SlateOptMacros.h"

// 最小領域
static constexpr float kLimitSpace = 10.f;

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="InArgs"></param>
void SResizableMenuBox::Construct(const FArguments& InArgs)
{
	split_type_ = InArgs._SplitType;
	on_splitter_move_ = InArgs._OnSplitterMoved;
}

/// <summary>
/// スプリッターの追加
/// </summary>
/// <param name="anhors"></param>
/// <param name="id"></param>
void SResizableMenuBox::AddSplitter(const FAnchors& anchors , const FGuid& id)
{
	TSharedPtr<SBox> splitter_box = SNew(SBox)[SNew(SImage).ColorAndOpacity(FLinearColor::Black)];

	FMargin offset = split_type_ == ESplitType::Horizontal ? 
		FMargin(0.f, 0.f, kSplitterThickness, 0.f) : 
		FMargin(0.f, 0.f, 0.f, kSplitterThickness);

	FSplitter splitter;

	this->AddSlot()
		.Anchors(anchors)
		.Offset(offset)
		.Alignment(FVector2D(0.5f))
		.Expose(splitter.slot)
		[
			splitter_box.ToSharedRef()
		];

	splitter.box = splitter_box;
	splitter.id = id;
	splitter.offset_val = 0.f;

	splitter_array_.Add(splitter);
}

/// <summary>
/// マウス押下時の処理
/// </summary>
/// <param name="MyGeometry"></param>
/// <param name="MouseEvent"></param>
/// <returns></returns>
FReply SResizableMenuBox::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	auto splitter_ptr = FindFocusedSplitter(MouseEvent.GetScreenSpacePosition());
	if (splitter_ptr){

		active_splitter_ = *splitter_ptr;
		start_mouse_pos_ = active_splitter_.box->GetTickSpaceGeometry().AbsoluteToLocal(MouseEvent.GetScreenSpacePosition());
		split_size_ = MyGeometry.GetLocalSize() / (splitter_array_.Num() + 1);

		return FReply::Handled().CaptureMouse(SharedThis(this));
	}

	return FReply::Unhandled();
}

/// <summary>
/// マウス移動時の処理
/// </summary>
/// <param name="MyGeometry"></param>
/// <param name="MouseEvent"></param>
/// <returns></returns>
FReply SResizableMenuBox::OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (active_splitter_.slot){
		if (HasMouseCapture()){

			FVector2D crr_mouse_pos = active_splitter_.box->GetTickSpaceGeometry().AbsoluteToLocal(MouseEvent.GetScreenSpacePosition());
			FVector2D mouse_delta = crr_mouse_pos - start_mouse_pos_;
			FMargin offsets = active_splitter_.slot->GetOffset();

			const bool kIsHorizontal = split_type_ == ESplitType::Horizontal;
			float& offset_val = kIsHorizontal ? offsets.Left : offsets.Top;
			const float kDelta = kIsHorizontal ? mouse_delta.X : mouse_delta.Y;
			const float kSplitSize = kIsHorizontal ? split_size_.X : split_size_.Y;

			// Offset更新・範囲制限
			offset_val += kDelta;
			const int32 kIdx = GetActiveSplitterIdx();
			auto neighbor_offset_val = GetNeighborOffsetVal(kIdx);
			offset_val = FMath::Clamp(offset_val, -kSplitSize + neighbor_offset_val.Key + kLimitSpace, kSplitSize + neighbor_offset_val.Value - kLimitSpace);
			splitter_array_[kIdx].offset_val = offset_val;

			// Delegate通知
			on_splitter_move_.Execute(active_splitter_.id, offset_val);
			active_splitter_.slot->SetOffset(offsets);
	
			return FReply::Handled();
		}
	}

	return FReply::Unhandled();
}

/// <summary>
/// アクティブなスプリッターのインデックスを取得
/// </summary>
/// <returns>インデックス</returns>
int32 SResizableMenuBox::GetActiveSplitterIdx() const
{
	// Index探索
	FGuid target_id = active_splitter_.id;
	const int32 kIdx = splitter_array_.IndexOfByPredicate(
		[&target_id](const FSplitter& item) {
			return item.id == target_id;
		}
	);

	return kIdx;
}

/// <summary>
/// 隣り合うスプリッターのオフセット値を取得
/// </summary>
/// <param name="idx">インデックス</param>
/// <returns>オフセットのタプル</returns>
TPair<float, float> SResizableMenuBox::GetNeighborOffsetVal(int32 idx)
{
	TPair<float, float> neighbor_offset_val = { 0.f,0.f };

	if (idx != INDEX_NONE) {

		if (splitter_array_.IsValidIndex(idx - 1)) {
			neighbor_offset_val.Key = splitter_array_[idx - 1].offset_val;
		}

		if (splitter_array_.IsValidIndex(idx + 1)) {
			neighbor_offset_val.Value = splitter_array_[idx + 1].offset_val;
		}
	}

	return neighbor_offset_val;
}

/// <summary>
/// マウスを離した際の処理
/// </summary>
/// <param name="MyGeometry"></param>
/// <param name="MouseEvent"></param>
/// <returns></returns>
FReply SResizableMenuBox::OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{	
	return FReply::Handled().ReleaseMouseCapture();
}

/// <summary>
/// カーソルのアイコン表示処理
/// </summary>
/// <param name="MyGeometry"></param>
/// <param name="CursorEvent"></param>
/// <returns></returns>
FCursorReply SResizableMenuBox::OnCursorQuery(const FGeometry& MyGeometry, const FPointerEvent& CursorEvent) const
{
	auto splitter_ptr = FindFocusedSplitter(CursorEvent.GetScreenSpacePosition());
	if (splitter_ptr){

		if (split_type_ == ESplitType::Vertical){
			return FCursorReply::Cursor(EMouseCursor::ResizeUpDown);
		}
		else{
			return FCursorReply::Cursor(EMouseCursor::ResizeLeftRight);
		}
	}

	return FCursorReply::Unhandled();
}

/// <summary>
/// 現在押されているスプリッターを探す処理
/// </summary>
/// <param name="CursorPos"></param>
/// <returns></returns>
const FSplitter* SResizableMenuBox::FindFocusedSplitter(const FVector2D CursorPos) const
{
	for (const FSplitter& splitter : splitter_array_){
		if (splitter.box.IsValid()){

			auto box_rect = splitter.box->GetTickSpaceGeometry().GetRenderBoundingRect();
			if (box_rect.ContainsPoint(CursorPos)) {
				return &splitter;
			}
		}
	}

	return nullptr;
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
