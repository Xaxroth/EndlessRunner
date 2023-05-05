// Copyright Epic Games, Inc. All Rights Reserved.

#include "EndlessRunnerGameMode.h"
#include "EndlessRunnerCharacter.h"
#include "TileSpawner.h"
#include "UObject/ConstructorHelpers.h"

AEndlessRunnerGameMode::AEndlessRunnerGameMode()
{
    // set default pawn class to our Blueprinted character
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
    if (PlayerPawnBPClass.Class != NULL)
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
    }
}

void AEndlessRunnerGameMode::IncreaseScore(float value)
{
    PlayerScore += value;
}

void AEndlessRunnerGameMode::IncreaseScrollingSpeed(float value)
{
    ScrollingSpeed += value;
}

void AEndlessRunnerGameMode::LoseHealth(float value)
{
    if (InvincibilityFrames == false)
    {
        PlayerHealth -= value;

        GiveInvincibilityFrames(InvincibilityDuration);

        if (PlayerHealth > 0)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("lost life"));
        }
        else
        {
            // PLAYER DIES
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("PLAYER DIES"));
            ReloadLevel();
        }
    }
    else
    {
        return;
    }
}

void AEndlessRunnerGameMode::GiveInvincibilityFrames(float Duration)
{
    InvincibilityFrames = true;
    GetWorldTimerManager().SetTimer(TimerHandle_Destroy, this, &AEndlessRunnerGameMode::MakeVulnerable, Duration, false);
}

void AEndlessRunnerGameMode::MakeVulnerable()
{
    InvincibilityFrames = false;
}

void AEndlessRunnerGameMode::ReloadLevel()
{
    // Get the current level's name
    FString CurrentLevelName = UGameplayStatics::GetCurrentLevelName(GetWorld(), true);

    // Open the current level
    UGameplayStatics::OpenLevel(GetWorld(), FName(*CurrentLevelName), true);
}
