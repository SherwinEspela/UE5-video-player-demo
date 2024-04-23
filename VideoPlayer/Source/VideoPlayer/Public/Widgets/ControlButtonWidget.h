// Copyright 2024 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CustomEnums.h"
#include "ControlButtonWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FButtonClickedSignature, EButtonMode, ButtonMode);

class UTextBlock;
class UButton;

/**
 * 
 */
UCLASS()
class VIDEOPLAYER_API UControlButtonWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	FButtonClickedSignature OnButtonClicked;

protected:
	void NativeConstruct() override;

	UFUNCTION(BlueprintImplementableEvent)
	void PlayButtonAnimation();

protected:
	UPROPERTY(meta = (BindWidget))
	UButton* Button;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* TextTitle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText TitleValue;

	UPROPERTY(EditAnywhere)
	EButtonMode ButtonMode;

private:
	UFUNCTION()
	void HandleButtonClicked();
};
