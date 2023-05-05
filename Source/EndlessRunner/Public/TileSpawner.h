// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "TileSpawner.generated.h"

UCLASS()
class ENDLESSRUNNER_API ATileSpawner : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATileSpawner();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UBoxComponent* CollisionComponent;

	UPROPERTY(EditAnywhere, Category = "Spawning")
		TArray<TSubclassOf<AActor>> ActorsToSpawn;

	UPROPERTY(EditAnywhere, Category = "Spawning")
		int32 SpawnOffset = 10000;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SpawnFloorTile();

public:
	UFUNCTION()
		void OnOverlap(class AActor* OverlappedActor, class AActor* OtherActor);
};
