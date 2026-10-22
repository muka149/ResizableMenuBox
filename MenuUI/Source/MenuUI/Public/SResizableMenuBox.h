// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/Layout/SConstraintCanvas.h"

/**
 * 
 */

DECLARE_DELEGATE_TwoParams(FOnSplitterMoved, FGuid&, float)

UENUM(BlueprintType)
enum class ESplitType : uint8
{
	Horizontal        UMETA(DisplayName = "Horizontal"),
	Vertical		  UMETA(DisplayName = "Vertiacal"),
};

struct FSplitter
{
	TSharedPtr<SBox> box;	
	FGuid id;
	SConstraintCanvas::FSlot* slot;
	float offset_val;
};

class MENUUI_API SResizableMenuBox : public SConstraintCanvas
{
public:
	SLATE_BEGIN_ARGS(SResizableMenuBox)
	{}
	SLATE_ARGUMENT(ESplitType, SplitType)
	SLATE_EVENT(FOnSplitterMoved, OnSplitterMoved)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	void AddSplitter(const FAnchors& Anchors, const FGuid& ID);

protected:
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent);
	virtual FReply OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FCursorReply OnCursorQuery(const FGeometry& MyGeometry, const FPointerEvent& CursorEvent) const;
	
private:
	const FSplitter* FindFocusedSplitter(const FVector2D CursorPos) const;
	int32 GetActiveSplitterIdx() const;
	TPair<float, float> GetNeighborOffsetVal(int32 idx);

	TSharedPtr<SConstraintCanvas> CanvasPanel;
	TArray<FSplitter> splitter_array_;
	ESplitType split_type_;
	FSplitter active_splitter_;
	FOnSplitterMoved on_splitter_move_;

	FVector2D start_mouse_pos_ = FVector2D(0);
	FVector2D split_size_   = FVector2D(0);

	inline static constexpr float kSplitterThickness = 5.f;
};
