// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "../EndlessRunnerGameMode.h"
#include "../EndlessRunnerCharacter.h"
#include "Engine/World.h"
#include "SmallObstacle.generated.h"

UCLASS()
class ENDLESSRUNNER_API ASmallObstacle : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASmallObstacle();

	UPROPERTY(EditAnywhere, Category = "Obstacle Type")
		int32 ObstacleType = 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UBoxComponent* CollisionComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SlowDownPlayer();

public:
	UFUNCTION()
		void OnOverlap(class AActor* OverlappedActor, class AActor* OtherActor);
};
