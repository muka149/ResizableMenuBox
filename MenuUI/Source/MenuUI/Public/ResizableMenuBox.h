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
	
	void ReleaseSlateResources(bool should_release_children) override;

protected:
	void OnSlotAdded(UPanelSlot* in_slot) override;
	virtual void OnSlotRemoved(UPanelSlot* slot) override;
	void SynchronizeProperties() override;
	TSharedRef<SWidget> RebuildWidget() override;

private:
	float LerpValue(const float ratio, const float min_val, const float max_val);
	void ResizeMenu(FGuid& id, float offset_val);

	TMap<FGuid, TTuple<UCanvasPanelSlot*, UCanvasPanelSlot*>> split_widget_map_;
	TSharedPtr<SResizableMenuBox> my_menu_box_;
};
