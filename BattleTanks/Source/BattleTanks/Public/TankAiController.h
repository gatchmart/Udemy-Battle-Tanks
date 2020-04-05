// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAiController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankAiController : public AAIController
{
	GENERATED_BODY()

private:
	virtual void BeginPlay() override;
	void Tick(float DeltaSeconds) override;

	ATank* controlledTank = nullptr;
	ATank* playerTank = nullptr;

	UPROPERTY(EditAnywhere)
	float acceptanceRadius = 300;
	
};
