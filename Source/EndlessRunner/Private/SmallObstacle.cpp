// Fill out your copyright notice in the Description page of Project Settings.


#include "SmallObstacle.h"

// Sets default values
ASmallObstacle::ASmallObstacle()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComponent"));
    RootComponent = CollisionComponent;

    CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    CollisionComponent->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);
    CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
    CollisionComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

}

// Called when the game starts or when spawned
void ASmallObstacle::BeginPlay()
{
    Super::BeginPlay();

    OnActorBeginOverlap.AddDynamic(this, &ASmallObstacle::OnOverlap);
}

// Called every frame
void ASmallObstacle::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ASmallObstacle::SlowDownPlayer()
{
    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);

    if (PlayerPawn)
    {
        AEndlessRunnerCharacter* PlayerCharacter = Cast<AEndlessRunnerCharacter>(PlayerPawn);
    }
}

void ASmallObstacle::OnOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
    if (OtherActor != this && OtherActor != GetOwner())
    {
        AEndlessRunnerGameMode* GameMode = Cast<AEndlessRunnerGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
        if (GameMode != nullptr)
        {
            GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("OBSTACLE TYPE: %d"), ObstacleType));

            switch (ObstacleType)
            {
            case 0:
                break;
            case 1:
                GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("INCREASE SCORE!"));
                GameMode->IncreaseScore(200);
                Destroy();
                break;
            case 2:
                GameMode->LoseHealth(1);
                SlowDownPlayer();
                break;
            case 3:
                GameMode->LoseHealth(3);
                SlowDownPlayer();
                break;
            }
        }
    }
}

