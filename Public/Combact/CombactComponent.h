// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombactComponent.generated.h"


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
	
protected:
	
	
private:
	
	
};
