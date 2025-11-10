// Fill out your copyright notice in the Description page of Project Settings.


#include "SResizableMenuBox.h"
#include "SlateOptMacros.h"

//bool SResizableMenuBox::bIsResizeing = false;

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="InArgs"></param>
void SResizableMenuBox::Construct(const FArguments& InArgs)
{
	SplitType = InArgs._SplitType;
	OnSplitterMoved = InArgs._OnSplitterMoved;
}

/// <summary>
/// スプリッターの追加
/// </summary>
/// <param name="Anchors"></param>
/// <param name="ID"></param>
void SResizableMenuBox::AddSplitter(const FAnchors& Anchors , const FGuid& ID)
{
	TSharedPtr<SBox> splitter_box = SNew(SBox)[SNew(SImage).ColorAndOpacity(FLinearColor::Black)];

	this->AddSlot()
		.Anchors(Anchors)
		[
			splitter_box.ToSharedRef()
		];

	FSplitter splitter;
	splitter.Box = splitter_box;
	splitter.Anchors = Anchors;
	splitter.ID = ID;

	SplitterArr.Add(splitter);
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
	if (splitter_ptr)
	{
		ActiveSplitter = *splitter_ptr;
		ActiveSplitter.CanvasSize = this->GetTickSpaceGeometry().GetLocalSize();
		
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
	auto splitter_box = ActiveSplitter.Box;
	if (splitter_box.IsValid())
	{
		if (HasMouseCapture())
		{
			const FVector2D mouse_pos = MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition());
			const FVector2D delta = mouse_pos / ActiveSplitter.CanvasSize;

			FAnchors new_anchors;
			if (SplitType == ESplitType::Horizontal){
				 new_anchors = FAnchors(delta.X - SPLITTER_HALF_THICKNESS, 0.0f, delta.X + SPLITTER_HALF_THICKNESS, 1.f);
			}
			else{
				new_anchors = FAnchors(0.0f, delta.Y - SPLITTER_HALF_THICKNESS, 1.0f, delta.Y + SPLITTER_HALF_THICKNESS);
			}
			
			if (OnSplitterMoved.IsBound())
			{
				const bool b_can_split = OnSplitterMoved.Execute(ActiveSplitter.ID, new_anchors);
				if (b_can_split)
				{
					this->RemoveSlot(splitter_box.ToSharedRef());
					this->AddSlot()
						.Anchors(new_anchors)
						[
							splitter_box.ToSharedRef()
						];
				}
			}
		}
	}

	return FReply::Handled();
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
	if (splitter_ptr)
	{
		if (SplitType == ESplitType::Vertical){
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
	for (const FSplitter& splitter : SplitterArr)
	{
		if (splitter.Box.IsValid())
		{
			auto box_rect = splitter.Box->GetTickSpaceGeometry().GetRenderBoundingRect();

			if (box_rect.ContainsPoint(CursorPos)) {
				return &splitter;
			}
		}
	}

	return nullptr;
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
