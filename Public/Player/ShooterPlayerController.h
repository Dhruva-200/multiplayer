// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShooterPlayerController.generated.h"
class UInputAction;
class UInputMappingContext;
struct FInputActionValue;
class UAnimMontage;
/**
 * 
 */
UCLASS()
//class USetupInputComponents; DONT NOT DECLARE AFTER YOU CLASS NIGA OKAY 

class FPS_API AShooterPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AShooterPlayerController();
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
private:
	UPROPERTY(EditAnywhere,Category="FPS|Input")
	const UInputMappingContext* ShooterIMC;
	
	UPROPERTY(EditAnywhere,Category="FPS|Input")
	TObjectPtr<UInputAction> LookAction;
	
	UPROPERTY(EditAnywhere,Category="FPS|Input")
	TObjectPtr<UInputAction> MoveAction;
	
	UPROPERTY(EditAnywhere,Category="FPS|Input")
	TObjectPtr<UInputAction> JumpAction;
	
	UPROPERTY(EditAnywhere,Category="FPS|Input")
	TObjectPtr<UInputAction> CrouchAction;
	
	UPROPERTY(EditAnywhere, Category="FPS|Input")
	TObjectPtr<UInputAction> SlideAction;
	
	
	void Input_Crouch();
	void Input_Jump();
	void Input_Move(const FInputActionValue& Handle);
	void Input_Look(const FInputActionValue& Handle);
	void Input_Slide();
	
	//Animations
	UPROPERTY(EditAnywhere,Category="FPS|Input")
	TObjectPtr<UAnimMontage> CrouchAnimMontage;
};
