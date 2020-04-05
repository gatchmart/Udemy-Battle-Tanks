// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankMovementComponent.h"
#include "Projectile.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>("AimingComponent");
}

void ATank::AimAt(FVector hitLocation)
{
	TankAimingComponent->AimAt(hitLocation, LaunchSpeed);
}

void ATank::SetBarrelReference(UTankBarrel* barrelToSet)
{
	TankAimingComponent->SetBarrelReference(barrelToSet);
	Barrel = barrelToSet;
}

void ATank::SetTurretReference(UTankTurret* turretToSet)
{
	TankAimingComponent->SetTurretReference(turretToSet);
}

void ATank::Fire()
{
	bool isReloaded = (FPlatformTime::Seconds() - lastFireTime) > ReloadTimeInSeconds;

	if (Barrel && isReloaded) {

		FVector socketLocation = Barrel->GetSocketLocation(FName("Projectile"));
		auto projectile = GetWorld()->SpawnActor<AProjectile>(
			Projectile,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);

		projectile->LaunchProjectile(LaunchSpeed);

		lastFireTime = FPlatformTime::Seconds();
	}
}

