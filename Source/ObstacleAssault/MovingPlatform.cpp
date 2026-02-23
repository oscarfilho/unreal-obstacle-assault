// Fill out your copyright notice in the Description page of Project Settings.
#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Display, TEXT("HELLO WORLD! Begin Play."));
	TargetLocation.X = -2500.0f;
	//TargetLocation = FVector(-2500.0f, 0.0f, 0.0f);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector DesiredVelocity = FVector(-MoveSpeed, 0.0f, 0.0f) * DeltaTime;

	//FVector DesiredVelocity = TargetLocation * DeltaTime;
	SetActorLocation(GetActorLocation() + DesiredVelocity);

	UE_LOG(LogTemp, Display, TEXT("Tick DeltaTime: %.6f"), DeltaTime);
}

