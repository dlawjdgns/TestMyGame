// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTestAnimNotifyState.h"
#include "MyBasicCharacter.h"

void UMyTestAnimNotifyState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animtion, float TotalDuration)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, __FUNCTION__);

	if (MeshComp != NULL && MeshComp->GetOwner() != NULL)
	{
		AMyBasicCharacter* Player = Cast<AMyBasicCharacter>(MeshComp->GetOwner());
		if (Player != NULL)
		{
			Player->ShowFX();
		}
	}
}

void UMyTestAnimNotifyState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animtion)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, __FUNCTION__);

	if (MeshComp != NULL && MeshComp->GetOwner() != NULL)
	{
		AMyBasicCharacter* Player = Cast<AMyBasicCharacter>(MeshComp->GetOwner());
		if (Player != NULL)
		{
			Player->Attack_Melee_End();
		}
	}
}