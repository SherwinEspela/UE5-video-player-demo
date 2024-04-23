// Copyright 2024 Sherwin Espela. All rights reserved.


#include "Widgets/VideoPlayerUserWidget.h"
#include "Widgets/ControlButtonWidget.h"
#include "Components/Button.h"
#include "Components/Image.h"

void UVideoPlayerUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ButtonPlay->OnButtonClicked.AddDynamic(this, &UVideoPlayerUserWidget::HandleButtonClicked);
	ButtonPause->OnButtonClicked.AddDynamic(this, &UVideoPlayerUserWidget::HandleButtonClicked);
	ButtonRewind->OnButtonClicked.AddDynamic(this, &UVideoPlayerUserWidget::HandleButtonClicked);
	ButtonToggleLoop->OnButtonClicked.AddDynamic(this, &UVideoPlayerUserWidget::HandleButtonClicked);
}

void UVideoPlayerUserWidget::DisplayLoopIndicator(bool ShouldDisplay)
{
	PlayLoopIndicatorAnimation(ShouldDisplay);
}

void UVideoPlayerUserWidget::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	PlayDisplayControlPanelAnimation();
}

void UVideoPlayerUserWidget::NativeOnMouseLeave(const FPointerEvent& InMouseEvent)
{
	PlayDisplayControlPanelAnimation(false);
}

void UVideoPlayerUserWidget::HandleButtonClicked(EButtonMode ButtonMode)
{
	OnControlButtonClicked.Broadcast(ButtonMode);
}
