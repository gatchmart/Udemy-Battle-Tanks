// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "Tank.h"

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
}

void ATankPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation;

	if (GetSightRayHitLocation(HitLocation)) {		
		GetControlledTank()->AimAt(HitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &outHitLocation) const
{
	outHitLocation = FVector(1.0);

	int32 viewportSizeX, viewportSizeY;
	GetViewportSize(viewportSizeX, viewportSizeY);
	FVector2D screenLocation = FVector2D(CrossHairXLocation * viewportSizeX, CrossHairYLocation * viewportSizeY);

	FVector lookDirection;

	if (GetLookDirection(screenLocation, lookDirection)) {
		GetLookVectorHitLocation(lookDirection, outHitLocation);

		return true;
	}

	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D screenLocation, FVector& lookDirection) const
{
	FVector worldLocation;
	return DeprojectScreenPositionToWorld(screenLocation.X, screenLocation.Y, worldLocation, lookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector lookDirection, FVector& hitLocation) const
{
	FHitResult hitResult;
	auto startLocation = PlayerCameraManager->GetCameraLocation();
	FVector endLocation = startLocation + lookDirection * LineTraceRange;

	if (GetWorld()->LineTraceSingleByChannel(hitResult, startLocation, endLocation, ECollisionChannel::ECC_Visibility)) {
		hitLocation = hitResult.Location;
		return true;
	}
	
	return false;
}
