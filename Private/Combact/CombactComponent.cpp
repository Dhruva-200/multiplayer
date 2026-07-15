// Fill out your copyright notice in the Description page of Project Settings.


#include "Combact/CombactComponent.h"

#include "Charecter/ShooterCharacter.h"
#include "Weapon/Weapon.h"


UCombactComponent::UCombactComponent()
{
	
	PrimaryComponentTick.bCanEverTick = true;

}

void UCombactComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                      FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UCombactComponent::Initiate_CycleWeapon()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Green,TEXT("NIGA MONEYY NIGA MOENY"),false );
	}
}

void UCombactComponent::Initiate_FireWeapon_Pressed()
{	
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Green,TEXT("NIGA MONEYY NIGA MOENY"),false );
	}
}

void UCombactComponent::Initiate_FireWeapon_Released()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Green,TEXT("NIGA MONEYY NIGA MOENY"),false );
	}
}

void UCombactComponent::Initiate_Reload()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Green,TEXT("NIGA MONEYY NIGA MOENY"),false );
	}
}

void UCombactComponent::Initiate_Aim_Pressed()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Green,TEXT("NIGA MONEYY NIGA MOENY"),false );
	}
}

void UCombactComponent::Initiate_Aim_Released()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Green,TEXT("NIGA MONEYY NIGA MOENY"),false );
	}
	
}

void UCombactComponent::SpawnInventory()
{
	if (AWeapon* NewWeapon = SpawnWeapon(DefaultWeaponn))
	if (IsValid(NewWeapon))
	{
		NewWeapon->AttachToOwingPawn();
	}
}

void UCombactComponent::DistoryInventory()
{
	//
}

AWeapon* UCombactComponent::SpawnWeapon(TSubclassOf<AWeapon> WeaponClass) const
{
	AActor* Owner=GetOwner();
	if (!IsValid(Owner))return nullptr;// player1 start act as a server listen server
	if (Owner->GetLocalRole()< ROLE_Authority) return nullptr;
	//authority -this machine is allowed to make gameplay decisions for this actor 
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.Instigator =Cast<APawn>(Owner);//instigator is the actor who spawned IE PLAYER HERE  
	SpawnInfo.Owner = Owner;//what type of owner -is it a dog player a door or anything 
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	
	return GetWorld()->SpawnActor<AWeapon>(WeaponClass,SpawnInfo);
	//SpawnActor creates an instance of the BP_Pistol class and returns a pointer to it as an AWeapon*
	
}


