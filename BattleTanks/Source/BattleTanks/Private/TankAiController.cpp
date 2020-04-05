// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAiController.h"
#include "Tank.h"

void ATankAiController::BeginPlay()
{
	Super::BeginPlay();

	playerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	controlledTank = Cast<ATank>(GetPawn());

	checkf(playerTank != nullptr, TEXT("AI Controller could not get the player's tank"));
	checkf(controlledTank != nullptr, TEXT("AI Controller could not get the controlled tank"));
}

void ATankAiController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	MoveToActor(playerTank, acceptanceRadius);

	controlledTank->AimAt(playerTank->GetActorLocation());
	controlledTank->Fire();
}
