// Copyright 2024 Sherwin Espela. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CustomEnums.h"
#include "VideoPlayerActor.generated.h"

#define ACTOR_TAG_VIDEOPLAYER FName("VideoPlayer")

class UVideoPlayerUserWidget;
class UMediaPlayer;
class UMediaSoundComponent;
class UMediaSource;

UCLASS()
class VIDEOPLAYER_API AVideoPlayerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AVideoPlayerActor();

	void Play();
	void Pause();
	void Rewind();
	void ToggleLoop();

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere, Category = "Video Player")
	TSubclassOf<UVideoPlayerUserWidget>  VideoPlayerWidgetClass;

	UPROPERTY(EditAnywhere, Category = "Video Player")
	UMediaPlayer* MediaPlayer;

	UPROPERTY(EditAnywhere, Category = "Video Player")
	UMediaSoundComponent* MediaSoundComponent;

	UPROPERTY(EditAnywhere, Category = "Video Player")
	UMediaSource* MediaSource;

	UPROPERTY(BlueprintReadOnly)
	UVideoPlayerUserWidget* VideoPlayerWidget;

private:
	UFUNCTION()
	void HandleControlButtonClicked(EButtonMode ButtonMode);
};
