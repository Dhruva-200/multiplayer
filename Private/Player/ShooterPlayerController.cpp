// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ShooterPlayerController.h"

#include "EnhancedInputSubsystems.h"

AShooterPlayerController::AShooterPlayerController()
{
	bReplicates = true;//updating into all machines remotly 
}

void AShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UEnhancedInputLocalPlayerSubsystem* Subsystem =	ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (IsValid(Subsystem))
	{
		Subsystem->AddMappingContext(ShooterIMC,0);
	}
}

void AShooterPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
}

void AShooterPlayerController::Input_Crouch()
{
}

void AShooterPlayerController::Input_Jump()
{
}

void AShooterPlayerController::Input_Move(const FInputActionValue& Handle)
{
}

void AShooterPlayerController::Input_Look(const FInputActionValue& Handle)
{
}
