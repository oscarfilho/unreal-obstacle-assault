// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	FVector TargetLocation = FVector(-400.0f, 0.0f, 330.0f);
	
	UPROPERTY(EditAnywhere)
	FVector PlatformVelocity = FVector(-100.0f, 0.0f, 0.0f);
	
	bool IsGoing = true;
	
	enum MyStates{
		STARTED,
		RUNNING,
		ENDED
	};

	MyStates myStates = MyStates::STARTED;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);
};
