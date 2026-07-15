// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/Weapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "Interface/WeaponInterface.h"


// Sets default values
AWeapon::AWeapon()
{
	bReplicates = true;
	bNetUseOwnerRelevancy = true;

	PrimaryActorTick.bCanEverTick = false;//weapon does not need to run every frame 
	Mesh1P=CreateDefaultSubobject<USkeletalMeshComponent>("SkeletalMesh");
	
	Mesh1P->VisibilityBasedAnimTickOption=EVisibilityBasedAnimTickOption::OnlyTickPoseWhenRendered;
	//update mesh animation only when being rendered |gotta see without this how it'll be 
	Mesh1P->bReceivesDecals = false;//dont project bullet holes onto Mesh1P
	Mesh1P->CastShadow = false;	
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetHiddenInGame(false);
	SetRootComponent(Mesh1P);
	
	Mesh3P=CreateDefaultSubobject<USkeletalMeshComponent>("Mesh3P");
	Mesh3P->VisibilityBasedAnimTickOption=EVisibilityBasedAnimTickOption::OnlyTickPoseWhenRendered;
	Mesh3P->bReceivesDecals = false;
	Mesh3P->CastShadow = false;
	Mesh3P->SetOwnerNoSee(true);
	Mesh3P->SetHiddenInGame(false);
	Mesh3P->SetupAttachment(Mesh1P);
}

void AWeapon::OnRep_Instigator()
{
	Super::OnRep_Instigator();
	AttachToOwingPawn();
}

USkeletalMeshComponent* AWeapon::GetMesh1P() const
{
	return Mesh1P;
}

USkeletalMeshComponent* AWeapon::GetMesh3P() const
{
	return Mesh3P;
}

void AWeapon::AttachToOwingPawn() const
{
	APawn* OwningPawn=GetInstigator();
	if (!(IsValid(OwningPawn)) || !OwningPawn->Implements<UWeaponInterface>())return;
	
	const FName AttachPoint = IWeaponInterface::Execute_GetWeaponAttachmentPoint(OwningPawn, WeaponType);
	if (AttachPoint.IsNone())
	{
		return;
	}

	USkeletalMeshComponent* PawnMesh1P = IWeaponInterface::Execute_GetMesh1P(OwningPawn);
	USkeletalMeshComponent* PawnMesh3P = IWeaponInterface::Execute_GetMesh3P(OwningPawn);
	if (!IsValid(PawnMesh1P) || !IsValid(PawnMesh3P))
	{
		return;
	}

	Mesh1P->AttachToComponent(PawnMesh1P, FAttachmentTransformRules::KeepRelativeTransform, AttachPoint);
	Mesh3P->AttachToComponent(PawnMesh3P, FAttachmentTransformRules::KeepRelativeTransform, AttachPoint);
	
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

