// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ShooterPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
//#include "InputActionValue.h"

AShooterPlayerController::AShooterPlayerController()//why same-telling complier implementation of that constructor
{//this actor is allowed to participate in replication 
	//servver -> tells client about this actor , 
	//if false the client may never know actor existed 
	bReplicates = true;//updating into all machines remotly 
	//bReplicates is from AActor,has spawn ,enemies ect 
}

void AShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();//super is Parent class ie-> APlayerController. 
	//even if you skip this the code will run but NOTHING IS INITIALIZED OF PARENT!!! 
	UEnhancedInputLocalPlayerSubsystem* Subsystem =	ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	//UObejct -> REFLECTION SYSTEM 
	//localplayer-whos playing the game | GetSubSystem() -do you have enhcace input system 
	if (IsValid(Subsystem))
	{
		Subsystem->AddMappingContext(ShooterIMC,0);//use this set of controls
	}
}

void AShooterPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* ShooterInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	ShooterInputComponent->BindAction(MoveAction,ETriggerEvent::Triggered,this,&ThisClass::Input_Move);
	ShooterInputComponent->BindAction(LookAction,ETriggerEvent::Triggered,this,&ThisClass::Input_Look);
	ShooterInputComponent->BindAction(JumpAction,ETriggerEvent::Started,this,&ThisClass::Input_Jump);
	ShooterInputComponent->BindAction(CrouchAction,ETriggerEvent::Started,this,&ThisClass::Input_Crouch);
	ShooterInputComponent->BindAction(SlideAction,ETriggerEvent::Started,this,&ThisClass::Input_Slide);

}

void AShooterPlayerController::Input_Crouch()
{
	if (!IsValid(GetCharacter())) return;
	if (UCharacterMovementComponent* CMC = GetCharacter()->GetCharacterMovement(); IsValid(CMC))
	{
		CMC->bWantsToCrouch = !CMC->bWantsToCrouch;
	}
}

void AShooterPlayerController::Input_Jump()
{
	if (!IsValid(GetCharacter())) return;
	UCharacterMovementComponent* CMC = GetCharacter()->GetCharacterMovement(); 
	if (!IsValid(CMC)) return;
	if (CMC->bWantsToCrouch)
	{
		CMC->bWantsToCrouch = false;
	}
	else
	{
		GetCharacter()->Jump();
	}
}

void AShooterPlayerController::Input_Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation= GetControlRotation();
	const FRotator YawRotation(0.f,Rotation.Yaw,0.f);
	
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	
	if (APawn* ControlledPawn= GetPawn())
	{
		ControlledPawn->AddMovementInput(ForwardDirection,InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection,InputAxisVector.X);
	}
}

void AShooterPlayerController::Input_Look(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	AddYawInput(InputAxisVector.X);
	AddPitchInput(InputAxisVector.Y);
	
}

void AShooterPlayerController::Input_Slide()
{
	ACharacter* PlayerCharacter = GetCharacter();

	if (!IsValid(PlayerCharacter))
	{
		return;
	}

	UCharacterMovementComponent* CMC =
		PlayerCharacter->GetCharacterMovement();

	if (!IsValid(CMC))
	{
		return;
	}

	CMC->bWantsToCrouch = true;

	PlayerCharacter->LaunchCharacter(
		PlayerCharacter->GetActorForwardVector() * 1500.f,
		false,
		false
	);
	if (IsValid(CrouchAnimMontage))
	{
		PlayerCharacter->PlayAnimMontage(CrouchAnimMontage);
	}
	
}
