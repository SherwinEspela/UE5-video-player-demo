// Copyright 2024 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "VPDemoPlayerController.generated.h"

class UEnhancedInputComponent;
class UInputAction;
class UInputMappingContext;
class AVideoPlayerActor;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class VIDEOPLAYER_API AVPDemoPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "User Input")
	UInputMappingContext* InputMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "User Input")
	UInputAction* IAPlay;

	UPROPERTY(EditDefaultsOnly, Category = "User Input")
	UInputAction* IAPause;

	UPROPERTY(EditDefaultsOnly, Category = "User Input")
	UInputAction* IARewind;

	UPROPERTY(EditDefaultsOnly, Category = "User Input")
	UInputAction* IALoop;

private:
	void Play();
	void Pause();
	void Rewind();
	void ToggleLoop();

private:
	UEnhancedInputComponent* EnhancedInputComponent;
	AVideoPlayerActor* VideoPlayerActor;
};
