// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/Weapon.h"


// Sets default values
AWeapon::AWeapon()
{
	
	PrimaryActorTick.bCanEverTick = false;//weapon does not need to run every frame 
	Mesh1P=CreateDefaultSubobject<USkeletalMeshComponent>("SkeletalMesh");
	
	Mesh1P->VisibilityBasedAnimTickOption=EVisibilityBasedAnimTickOption::OnlyTickPoseWhenRendered;
	//update mesh animation only when being rendered |gotta see without this how it'll be 
	Mesh1P->bReceivesDecals = false;//dont project bullet holes onto Mesh1P
	Mesh1P->CastShadow = false;
	Mesh1P->SetHiddenInGame(true);
	SetRootComponent(Mesh1P);
	
	Mesh3P=CreateDefaultSubobject<USkeletalMeshComponent>("Mesh3P");
	Mesh3P->VisibilityBasedAnimTickOption=EVisibilityBasedAnimTickOption::OnlyTickPoseWhenRendered;
	Mesh3P->bReceivesDecals = false;
	Mesh3P->CastShadow = true;
	Mesh3P->SetHiddenInGame(true);
	Mesh3P->SetupAttachment(Mesh1P);
}

USkeletalMeshComponent* AWeapon::GetMesh1P() const
{
	return Mesh1P;
}

USkeletalMeshComponent* AWeapon::GetMesh3P() const
{
	return Mesh3P;
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}



