// Copyright 2024 Sherwin Espela. All rights reserved.


#include "Widgets/ControlButtonWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"

void UControlButtonWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Button->OnClicked.AddDynamic(this, &UControlButtonWidget::HandleButtonClicked);
}

void UControlButtonWidget::HandleButtonClicked()
{
	OnButtonClicked.Broadcast(ButtonMode);
	PlayButtonAnimation();
}
