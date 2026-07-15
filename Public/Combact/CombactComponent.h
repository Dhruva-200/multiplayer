// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombactComponent.generated.h"
class UWeaponData;
class AWeapon;


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FPS_API UCombactComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UCombactComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,FActorComponentTickFunction* ThisTickFunction) override;
	
	void Initiate_CycleWeapon();
	void Initiate_FireWeapon_Pressed();
	void Initiate_FireWeapon_Released();
	void Initiate_Reload();
	void Initiate_Aim_Pressed();
	void Initiate_Aim_Released();
	UPROPERTY(EditDefaultsOnly,Category="FPS| Weapon")
	TObjectPtr<UWeaponData> WeaponData;
	
	void SpawnInventory();
	void DistoryInventory();
	
protected:
	
	
private:
       UPROPERTY(EditDefaultsOnly,Category="FPS|Weapon")// a parent bp is weapon,subclass is pistole , rifle 
	   TSubclassOf<AWeapon> DefaultWeaponn;// telling unreal which class to spawn 
	
	  AWeapon* SpawnWeapon(TSubclassOf<AWeapon> WeaponClass) const;
	  // WE ARE NOT CHANGIN ANYTHING IN CHARECTER THATS WHY CONST 
	/* class  AShooterCharacter : public ACharacter {
	public: 
	int32 Health = 100; 
	void PrintHealth() const;
	}; 
	void AShooterCharacter::PrintHealth() const {
	UE_LOG(LogTemp, Warning, TEXT("%d"), Health); can only read 
	}
	*/
};
