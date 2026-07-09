// Fill out your copyright notice in the Description page of Project Settings.


#include "Charecter/ShooterCharacter.h"

#include "EnhancedInputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Combact/CombactComponent.h"
// Sets default values
AShooterCharacter::AShooterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength = 0.f;
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->bEnableCameraLag = true;
	//this looks so neat btw what the fuck 
	SpringArm->CameraLagSpeed = 10.f;

	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>("FirstPersonCamera");
	FirstPersonCameraComponent->SetupAttachment(SpringArm);
	FirstPersonCameraComponent->bUsePawnControlRotation = false;

	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>("Mesh1P");
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bOnlyOwnerSee = true;
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->bOwnerNoSee = false;
	Mesh1P->bReceivesDecals = false;//only set to ture if there is blood or somethin
	Mesh1P->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::OnlyTickPoseWhenRendered;
	// only tick when rendered , so when chreacter off screen dosent use cpu meoery dayum 
	Mesh1P->PrimaryComponentTick.TickGroup = TG_PrePhysics;
	//update the mesh before physics so that the physics can use the updated pose for collision detection 

	GetMesh()->bOnlyOwnerSee = false;
	GetMesh()->bOwnerNoSee = true;
	GetMesh()->bReceivesDecals = true;
	
	Combact = CreateDefaultSubobject<UCombactComponent>("Combact");
	Combact->SetIsReplicated(true);
	
}

// Called when the game starts or when spawned
void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Hello World!"));
	}
	
}

// Called every frame
void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	UEnhancedInputComponent* ShooterInputComponent= CastChecked<UEnhancedInputComponent>(PlayerInputComponent);
	ShooterInputComponent->BindAction(CycleWeapon,ETriggerEvent::Started,this,&ThisClass::Input_Cycle_Weapon);
	ShooterInputComponent->BindAction(ReloadWeapon,ETriggerEvent::Started,this,&ThisClass::Input_Reload_Weapon);
	ShooterInputComponent->BindAction(FireWeapon,ETriggerEvent::Started,this,&ThisClass::Input_Fire_Weapon_Pressed);
	ShooterInputComponent->BindAction(FireWeapon,ETriggerEvent::Completed,this,&ThisClass::Input_Fire_Weapon_Released);
	ShooterInputComponent->BindAction(AimWeapon,ETriggerEvent::Started,this,&ThisClass::Input_Aim_Weapon_Pressed);
	ShooterInputComponent->BindAction(AimWeapon,ETriggerEvent::Completed,this,&ThisClass::Input_Aim_Weapon_Released);

}

void AShooterCharacter::Input_Cycle_Weapon()
{
	Combact->Initiate_CycleWeapon();
}

void AShooterCharacter::Input_Reload_Weapon()
{
	Combact->Initiate_Reload();
}

void AShooterCharacter::Input_Fire_Weapon_Pressed()
{
	Combact->Initiate_FireWeapon_Pressed();
}

void AShooterCharacter::Input_Fire_Weapon_Released()
{
	Combact->Initiate_FireWeapon_Released();
}

void AShooterCharacter::Input_Aim_Weapon_Pressed()
{
	Combact->Initiate_Aim_Pressed();
}

void AShooterCharacter::Input_Aim_Weapon_Released()
{
	Combact->Initiate_Aim_Released();
}

