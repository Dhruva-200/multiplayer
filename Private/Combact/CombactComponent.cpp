// Fill out your copyright notice in the Description page of Project Settings.


#include "Combact/CombactComponent.h"


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

