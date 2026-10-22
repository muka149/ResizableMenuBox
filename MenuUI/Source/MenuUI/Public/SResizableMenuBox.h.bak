// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/Layout/SConstraintCanvas.h"

/**
 * 
 */
#define SPLITTER_HALF_THICKNESS  0.003f

DECLARE_DELEGATE_RetVal_TwoParams(bool, FOnSplitterMoved, FGuid, FAnchors)

UENUM(BlueprintType)
enum class ESplitType : uint8
{
	Horizontal        UMETA(DisplayName = "Horizontal"),
	Vertical		  UMETA(DisplayName = "Vertiacal"),
};

struct FSplitter
{
	TSharedPtr<SBox> Box;	
	FVector2D CanvasSize;
	FAnchors Anchors;
	FGuid ID;
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

	TSharedPtr<SConstraintCanvas> CanvasPanel;
	TArray<FSplitter> SplitterArr;
	ESplitType SplitType;
	FSplitter ActiveSplitter;
	FOnSplitterMoved OnSplitterMoved;
};
