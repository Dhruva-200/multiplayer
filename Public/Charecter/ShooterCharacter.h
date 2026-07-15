
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interface/WeaponInterface.h"
#include "ShooterCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
//class USkeletalMeshComponent;
class UCombactComponent;
class UInputAction;
UCLASS()
class FPS_API AShooterCharacter : public ACharacter,public IWeaponInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

	/*
	// Multiplayer slide implementation (currently disabled).
	// Called by the owning player. The server performs the actual slide.
	void RequestSlide();
	*/

	virtual void BeginPlay() override;
	/* Interfaces*/
	
	virtual FName GetWeaponAttachmentPoint_Implementation(const FGameplayTag& WeaponType) const override;
	virtual USkeletalMeshComponent* GetMesh1P_Implementation() const override;
	virtual USkeletalMeshComponent* GetMesh3P_Implementation() const override;
	/* Interfaces*/
protected:
	// Called when the game starts or when spawned

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual  void PossessedBy(AController* NewController) override;
	void yourmum();
private:
	
	void Input_Cycle_Weapon();
	void Input_Reload_Weapon();
	void Input_Fire_Weapon_Pressed();
	void Input_Fire_Weapon_Released();
	void Input_Aim_Weapon_Pressed();
	void Input_Aim_Weapon_Released();
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCombactComponent> Combact;
	
	UPROPERTY(EditAnywhere, Category= " FPS | Input")
	TObjectPtr<UInputAction> CycleWeapon;
	
	UPROPERTY(EditAnywhere, Category= " FPS | Input")
	TObjectPtr<UInputAction> ReloadWeapon;
	
	UPROPERTY(EditAnywhere, Category= " FPS | Input")
	TObjectPtr<UInputAction> FireWeapon;
	
	UPROPERTY(EditAnywhere, Category= " FPS | Input")
	TObjectPtr<UInputAction> AimWeapon;
	
	
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USkeletalMeshComponent> Mesh1P;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCameraComponent> FirstPersonCameraComponent;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USpringArmComponent> SpringArm;

	/*
	UPROPERTY(EditDefaultsOnly, Category = "FPS|Movement")
	TObjectPtr<UAnimMontage> SlideAnimMontage;

	UFUNCTION(Server, Reliable)
	void ServerStartSlide();

	UFUNCTION(NetMulticast, Unreliable)
	void MulticastPlaySlideMontage();
	*/
	int alr() const;

};
