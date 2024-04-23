// Copyright 2024 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EButtonMode : uint8
{
	EBM_Play	UMETA(DisplayName = "Play"),
	EBM_Pause	UMETA(DisplayName = "Pause"),
	EBM_Rewind	UMETA(DisplayName = "Rewind"),
	EBM_Loop	UMETA(DisplayName = "Loop")
};
