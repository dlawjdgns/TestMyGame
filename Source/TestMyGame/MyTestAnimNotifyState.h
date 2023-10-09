// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "Animation/AnimSequenceBase.h"
//#include "Components/SkeletalMeshComponent.h"
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "MyTestAnimNotifyState.generated.h"

/**
 * 
 */
UCLASS()
class TESTMYGAME_API UMyTestAnimNotifyState : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration) override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
	
};
