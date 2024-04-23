// Copyright 2024 Sherwin Espela. All rights reserved.


#include "Actors/VideoPlayerActor.h"
#include "Widgets/VideoPlayerUserWidget.h"
#include "MediaPlayer.h"
#include "MediaSoundComponent.h"
#include "MediaSource.h"

AVideoPlayerActor::AVideoPlayerActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Tags.Add(ACTOR_TAG_VIDEOPLAYER);
	MediaSoundComponent = CreateDefaultSubobject<UMediaSoundComponent>(TEXT("MediaSoundComponent"));
}

void AVideoPlayerActor::BeginPlay()
{
	Super::BeginPlay();
	
	UWorld* World = GetWorld();
	if (VideoPlayerWidgetClass)
	{
		VideoPlayerWidget = CreateWidget<UVideoPlayerUserWidget>(World, VideoPlayerWidgetClass);
		if (VideoPlayerWidget && MediaPlayer && MediaSource)
		{
			VideoPlayerWidget->AddToViewport();
			MediaPlayer->OpenSource(MediaSource);
			MediaPlayer->SetLooping(false);
			VideoPlayerWidget->OnControlButtonClicked.AddDynamic(this, &AVideoPlayerActor::HandleControlButtonClicked);
		}
	}
}

void AVideoPlayerActor::HandleControlButtonClicked(EButtonMode ButtonMode)
{
	switch (ButtonMode)
	{
	case EButtonMode::EBM_Play:
		Play();
		break;
	case EButtonMode::EBM_Pause:
		Pause();
		break;
	case EButtonMode::EBM_Rewind:
		Rewind();
		break;
	case EButtonMode::EBM_Loop:
		ToggleLoop();
		break;
	default:
		break;
	}
}

void AVideoPlayerActor::Play()
{
	if (MediaPlayer && !MediaPlayer->IsPlaying()) MediaPlayer->Play();
}

void AVideoPlayerActor::Pause()
{
	if (MediaPlayer && !MediaPlayer->IsPaused()) {
		MediaPlayer->Pause();
	}
}

void AVideoPlayerActor::Rewind()
{
	if (MediaPlayer)
	{
		MediaPlayer->Rewind();
	}
}

void AVideoPlayerActor::ToggleLoop()
{
	if (MediaPlayer)
	{
		MediaPlayer->SetLooping(!MediaPlayer->IsLooping());
		VideoPlayerWidget->DisplayLoopIndicator(MediaPlayer->IsLooping());
	}
}
