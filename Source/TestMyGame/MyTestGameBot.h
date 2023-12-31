// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyBasicCharacter.h"
#include "MyTestGameBot.generated.h"

/**
 * 
 */
UCLASS()
class TESTMYGAME_API AMyTestGameBot : public AMyBasicCharacter
{
	GENERATED_BODY()

public:
	AMyTestGameBot();

	UPROPERTY(EditAnywhere, Category = "Behavior")
		class UBehaviorTree* BotBehavior;

	UPROPERTY(EditAnywhere, Category = "Behavior")
		UAnimMontage* Attack_Melee;
	
};
