// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyBasicCharacter.generated.h"

UCLASS()
class TESTMYGAME_API AMyBasicCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyBasicCharacter();

	USkeletalMeshComponent* GetSpesificPawnMesh()const;

	FName GetWeaponAttachPoint()const;

	void EquipWeapon(class AMyTestWeapon* Weapon);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = "Pawn")
		UAnimMontage* Attack_AnimMontage;

	void Attack_Melee();
	void Attack_Melee_End();
	void ShowFX();

	bool isDuringAttack = true;
	int32 ComboAttack_Num;

	UPROPERTY(EditDefaultsOnly, Category = "MyFX")
	UParticleSystem* HitFX;

};