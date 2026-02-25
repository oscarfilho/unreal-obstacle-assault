// Fill out your copyright notice in the Description page of Project Settings.
#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void TestFunction(float MyFloatParam, int MyIntParam) {
	UE_LOG(LogTemp, Display, TEXT("HELLO WORLD! Test Function called. MyFloat: %.2f, MyIntParam: %3d"), MyFloatParam, MyIntParam);
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Display, TEXT("HELLO WORLD! Begin Play."));
	TargetLocation.X = -2500.0f;

	startLocation = GetActorLocation();

	TestFunction(300.05f, 500);
}

void AMovingPlatform::MovePlatform(float DeltaTime) {
	FVector currentLocation = GetActorLocation();
	SetActorLocation(currentLocation + (PlatformVelocity * DeltaTime));

	distanceMoved = FVector::Dist(startLocation, currentLocation);

	if (distanceMoved >= moveDistance) {
		float overshootDistance = distanceMoved - moveDistance;
		FString actorName = GetName();
		UE_LOG(LogTemp, Warning, TEXT("%s Overshoot Distance by: %.5f"), *actorName, overshootDistance);

		FVector moveDirection = PlatformVelocity.GetSafeNormal();
		FVector newStartLocation = startLocation + moveDirection * moveDistance;
		SetActorLocation(newStartLocation);
		startLocation = newStartLocation;

		PlatformVelocity = -PlatformVelocity;
		
	}
}

void AMovingPlatform::ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor) {
	UE_LOG(LogTemp, Display, TEXT("HELLO WORLD! Actor Begin Overlap."));
	PlatformVelocity = -PlatformVelocity;
}

// Rotates the platform
void AMovingPlatform::RotatePlatform(float DeltaTime) {
	//SetActorRotation(GetActorRotation() + FRotator(0.0f, 0.0f, 50.0f * DeltaTime));
	//UE_LOG(LogTemp, Display, TEXT("Rotating Platform..."));
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	elapsedTime += DeltaTime;

	this->MovePlatform(DeltaTime);
	//this->RotatePlatform(DeltaTime);

	if (elapsedTime > 1.0f) {
		UE_LOG(LogTemp, Display, TEXT("DeltaTime: %.2f. Elapsed Time: %.2f seconds"), DeltaTime, elapsedTime);
		elapsedTime = 0.0f;
	}

	//UE_LOG(LogTemp, Display, TEXT("Tick DeltaTime: %.6f"), DeltaTime);
}

