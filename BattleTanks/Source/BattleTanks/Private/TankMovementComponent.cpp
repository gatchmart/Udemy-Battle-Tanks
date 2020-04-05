// Fill out your copyright notice in the Description page of Project Settings.


#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialize(UTankTrack* leftTrack, UTankTrack* rightTrack)
{
	LeftTrack = leftTrack;
	RightTrack = rightTrack;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurn(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto aiForwardIntention = MoveVelocity.GetSafeNormal();
	auto tankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto dotProduct = FVector::DotProduct(tankForward, aiForwardIntention);

	IntendMoveForward(dotProduct);
}




