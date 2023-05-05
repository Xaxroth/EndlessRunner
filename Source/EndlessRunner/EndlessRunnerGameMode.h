// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EndlessRunnerGameMode.generated.h"

UCLASS(minimalapi)
class AEndlessRunnerGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AEndlessRunnerGameMode();

	int32 PlayerHealth = 3;
	int32 PlayerScore = 0;

	float ScrollingSpeed = 500.f;

	bool InvincibilityFrames;
	float InvincibilityDuration = 3.f;

private:
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		TSubclassOf<AActor> InitialTile;

public:
	void LoseHealth(float value);

	void GameOver();

	void IncreaseScore(float value);

	void IncreaseScrollingSpeed(float value);

public:
	UFUNCTION(BlueprintCallable)
		void GiveInvincibilityFrames(float Duration);

	void ReloadLevel();

private:
	FTimerHandle TimerHandle_Destroy;
	void MakeVulnerable();

};



