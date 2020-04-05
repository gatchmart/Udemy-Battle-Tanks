// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	void Elevate(float relativeSpeed);

private:

	UPROPERTY(EditDefaultsOnly, Category=Setup)
	float MaxDegreesPerSecond = 10.0;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxBarrelElevation = 40.0;
	
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MinBarrelElevation = 0.0;


};
