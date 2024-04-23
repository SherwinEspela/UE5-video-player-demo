// Copyright 2024 Sherwin Espela. All rights reserved.


#include "PlayerController/VPDemoPlayerController.h"
#include "Actors/VideoPlayerActor.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Kismet/GameplayStatics.h"

void AVPDemoPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* PlayerSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	PlayerSubsystem->AddMappingContext(InputMappingContext, 0);

	TArray<AActor*> VideoPlayerActors;
	UGameplayStatics::GetAllActorsWithTag(this, FName(ACTOR_TAG_VIDEOPLAYER), VideoPlayerActors);
	if (!VideoPlayerActors.IsEmpty()) VideoPlayerActor = CastChecked<AVideoPlayerActor>(VideoPlayerActors[0]);

	bShowMouseCursor = true;
}

void AVPDemoPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(IAPlay, ETriggerEvent::Triggered, this, &AVPDemoPlayerController::Play);
	EnhancedInputComponent->BindAction(IAPause, ETriggerEvent::Triggered, this, &AVPDemoPlayerController::Pause);
	EnhancedInputComponent->BindAction(IARewind, ETriggerEvent::Triggered, this, &AVPDemoPlayerController::Rewind);
	EnhancedInputComponent->BindAction(IALoop, ETriggerEvent::Triggered, this, &AVPDemoPlayerController::ToggleLoop);
}

void AVPDemoPlayerController::Play()
{
	if (VideoPlayerActor) VideoPlayerActor->Play();
}

void AVPDemoPlayerController::Pause()
{
	if (VideoPlayerActor) VideoPlayerActor->Pause();
}

void AVPDemoPlayerController::Rewind()
{
	if (VideoPlayerActor)
	{
		VideoPlayerActor->Rewind();
	}
}

void AVPDemoPlayerController::ToggleLoop()
{
	if (VideoPlayerActor)
	{
		VideoPlayerActor->ToggleLoop();
	}
}
