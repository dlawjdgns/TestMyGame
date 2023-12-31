// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "MyBTTask_RandomMove.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class TESTMYGAME_API UMyBTTask_RandomMove : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UMyBTTask_RandomMove(FObjectInitializer const& object_initializer);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& owner_Comp, uint8* NodeMemory);

private:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Search", meta = (AllowPrivateAccess = "true"))
		float search_radius = 1500.0f;
	
};
