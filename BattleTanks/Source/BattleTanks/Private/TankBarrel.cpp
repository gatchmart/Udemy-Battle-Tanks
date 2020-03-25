// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"

void UTankBarrel::Elevate(float relativeSpeed)
{
	relativeSpeed = FMath::Clamp<float>(relativeSpeed, -1, 1);
	auto elevationChange = relativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto rawNewElevation = RelativeRotation.Pitch + elevationChange;
	auto clampedNewElevation = FMath::Clamp<float>(rawNewElevation, MinBarrelElevation, MaxBarrelElevation);

	SetRelativeRotation(FRotator(clampedNewElevation, 0, 0));
}
