// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAiController.h"
#include "Tank.h"

ATank* ATankAiController::GetControlledTank()
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAiController::GetPlayerTank() const
{
	auto playerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	if (!playerTank) return nullptr;

	return Cast<ATank>(playerTank);

}

void ATankAiController::BeginPlay()
{
	Super::BeginPlay();

	auto aiTank = GetControlledTank();
	auto playerTank = GetPlayerTank();

	if (aiTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI Tank possessed: %s"), *(aiTank->GetName()));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI Tank not possessed."));
	}

	if (playerTank) {
		UE_LOG(LogTemp, Warning, TEXT("Player Tank targeted: %s"), *(playerTank->GetName()));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Player Tank not targeted."));
	}
}

void ATankAiController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (GetPlayerTank()) {
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}
