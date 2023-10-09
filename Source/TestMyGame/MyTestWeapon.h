// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Particles/ParticleSystem.h"
#include "MyBasicCharacter.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyTestWeapon.generated.h"

UCLASS()
class TESTMYGAME_API AMyTestWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyTestWeapon(const FObjectInitializer& ObjectInitializer);

	void SetOwningPawn(AMyBasicCharacter* NewOwner);
	void AttachMeshToPawn();
	void OnEquip(const AMyTestWeapon* LastWeapon);

private:
	UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
		USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
		class UBoxComponent* WeaponCollision;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	AMyBasicCharacter* MyPawn;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor);

	UPROPERTY(EditDefaultsOnly, Category = "MyFX")
		UParticleSystem* HitFX;

};
