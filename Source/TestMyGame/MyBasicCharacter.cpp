// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBasicCharacter.h"
#include "MyTestGameCharacter.h"
#include "Particles/ParticleSystem.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMyBasicCharacter::AMyBasicCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleAsset(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));

	if (ParticleAsset.Succeeded())
	{
		HitFX = ParticleAsset.Object;
	}

	ComboAttack_Num = 0;
	isDuringAttack = false;

}

USkeletalMeshComponent* AMyBasicCharacter::GetSpesificPawnMesh() const
{
	return nullptr;
}

FName AMyBasicCharacter::GetWeaponAttachPoint() const
{
	return FName();
}

void AMyBasicCharacter::EquipWeapon(AMyTestWeapon* Weapon)
{
}

// Called when the game starts or when spawned
void AMyBasicCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyBasicCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyBasicCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMyBasicCharacter::Attack_Melee()
{
	if (!isDuringAttack)
	{
		if (ComboAttack_Num < 3)
		{
			int Num = 0;
			int tmp_Num = rand() % 3 + 1;
			FString PlaySection = "Attack_" + FString::FromInt(Num) + FString::FromInt(tmp_Num);
			PlayAnimMontage(Attack_AnimMontage, 1.f, FName(*PlaySection));

			ComboAttack_Num++;

			isDuringAttack = true;
		}
		else
		{
			PlayAnimMontage(Attack_AnimMontage, 1.f, FName("Attack_04"));
			ComboAttack_Num = 0;
		}
	}

	
}

void AMyBasicCharacter::Attack_Melee_End()
{
	isDuringAttack = false;
}

void AMyBasicCharacter::ShowFX()
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), HitFX, GetActorLocation());
}

