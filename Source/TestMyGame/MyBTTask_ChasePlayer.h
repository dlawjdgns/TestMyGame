// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "MyTestGameBot.h"
#include "MyBTTask_ChasePlayer.generated.h"

/**
 * 
 */
UCLASS()
class TESTMYGAME_API UMyBTTask_ChasePlayer : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UMyBTTask_ChasePlayer(FObjectInitializer const& object_initializer);

	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8 node_memory);
};