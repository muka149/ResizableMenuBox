// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CanvasPanel.h"
#include "SResizableMenuBox.h"
#include "ResizableMenuBox.generated.h"

/**
 * 
 */

UCLASS()
class MENUUI_API UResizableMenuBox : public UCanvasPanel
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = "Menu Settings")
	ESplitType SplitType;

	UPROPERTY(EditAnywhere, Category = "Menu Settings")
	TArray<float> SplitRatio;
	
	void ReleaseSlateResources(bool bReleaseChildren) override;

protected:
	void OnSlotAdded(UPanelSlot* InSlot) override;
	virtual void OnSlotRemoved(UPanelSlot* Slot) override;
	void SynchronizeProperties() override;
	TSharedRef<SWidget> RebuildWidget() override;

private:
	float LerpValue(const float ratio, const float min_val, const float max_val);
	bool ResizeMenu(const FGuid ID, const FAnchors Anchors);

	TMap<FGuid, TTuple<UCanvasPanelSlot*, UCanvasPanelSlot*>> SplitWidgetsMap;
	TSharedPtr<SResizableMenuBox> MyMenuBox;
};
