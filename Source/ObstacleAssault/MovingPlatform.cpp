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

	TestFunction(300.05f, 500);
}

void AMovingPlatform::MovePlatform(float DeltaTime) {
	SetActorLocation(GetActorLocation() + (PlatformVelocity * DeltaTime));
}

// Rotates the platform
void AMovingPlatform::RotatePlatform(float DeltaTime) {
	SetActorRotation(GetActorRotation() + FRotator(0.0f, 0.0f, 50.0f * DeltaTime));
	UE_LOG(LogTemp, Display, TEXT("Rotating Platform..."));
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	this->MovePlatform(DeltaTime);
	this->RotatePlatform(DeltaTime);

	//UE_LOG(LogTemp, Display, TEXT("Tick DeltaTime: %.6f"), DeltaTime);
}

