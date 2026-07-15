// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "WeaponData.generated.h"

/**
 * 
 */
UCLASS()
class FPS_API UWeaponData : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, Category="FPS|WeaponData| Weapons")
	TMap<FGameplayTag,FName> GripPoints;
};
