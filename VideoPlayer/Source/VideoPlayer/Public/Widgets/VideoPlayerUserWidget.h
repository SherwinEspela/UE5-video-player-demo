// Copyright 2024 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CustomEnums.h"
#include "VideoPlayerUserWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FControlButtonClickedSignature, EButtonMode, ButtonMode);

class UControlButtonWidget;
class UTextBlock;
class UImage;

/**
 * 
 */
UCLASS()
class VIDEOPLAYER_API UVideoPlayerUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	FControlButtonClickedSignature OnControlButtonClicked;

	void DisplayLoopIndicator(bool ShouldDisplay);

	virtual void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnMouseLeave(const FPointerEvent& InMouseEvent) override;

protected:
	void NativeConstruct() override;

	UFUNCTION(BlueprintImplementableEvent)
	void PlayLoopIndicatorAnimation(bool ShouldDisplay = true);

	UFUNCTION(BlueprintImplementableEvent)
	void PlayDisplayControlPanelAnimation(bool ShouldDisplay = true);

protected:
	UPROPERTY(meta = (BindWidget))
	UControlButtonWidget* ButtonPlay;

	UPROPERTY(meta = (BindWidget))
	UControlButtonWidget* ButtonPause;

	UPROPERTY(meta = (BindWidget))
	UControlButtonWidget* ButtonRewind;

	UPROPERTY(meta = (BindWidget))
	UControlButtonWidget* ButtonToggleLoop;

private:
	UFUNCTION()
	void HandleButtonClicked(EButtonMode ButtonMode);

};
