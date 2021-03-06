// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankPlayerController.h"
#include "BattleTank.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{

		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank"));

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possesing: %s"), *(ControlledTank->GetName()));
	}
}



void ATankPlayerController :: Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );
    AimTowardsCrosshair();
	//UE_LOG(LogTemp, Warning, TEXT("PlayerController ticking"));
}




ATank* ATankPlayerController::GetControlledTank() const 

{

	return Cast<ATank>(GetPawn());
}


void ATankPlayerController::AimTowardsCrosshair() 
{

	if (!GetControlledTank()) { return; }

	FVector OutHitLocation;//out parameter 

	if (GetSightRayHitLocation(OutHitLocation)) // Has side effect, is going to line trace
	
	{
	
	UE_LOG(LogTemp, Warning, TEXT("OutHitLocation: %s"), *OutHitLocation.ToString());
	
	//if it hits the landscape
	//TODO tell controlled tank to ain at this point
	}	
}

//get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{

	OutHitLocation = FVector(1.0);
	return true;

}