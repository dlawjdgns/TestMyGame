// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "MyBTTask_FindPlayerLocation.generated.h"

/**
 * 
 */
UCLASS()
class TESTMYGAME_API UMyBTTask_FindPlayerLocation : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UMyBTTask_FindPlayerLocation(FObjectInitializer const& object_initializer);

	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& owner_Comp, uint8* node_memory) override;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Search", meta = (AllowProtectedAccess = true))
		float search_radius = 150.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Search", meta = (AllowProtectedAccess = true))
		bool search_random = false;
};
