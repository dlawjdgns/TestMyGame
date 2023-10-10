// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBTTask_RandomMove.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "MyTestGameAIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BTNode.h"
#include "NavigationSystem.h"
#include "blackboard_keys.h"

UMyBTTask_RandomMove::UMyBTTask_RandomMove(FObjectInitializer const& object_initializer)
{
	NodeName = TEXT("Find Random Location");
}

EBTNodeResult::Type UMyBTTask_RandomMove::ExecuteTast(UBehaviorTreeComponent& owner_Comp, uint8* NodeMemory)
{
	auto const cont = Cast<AMyTestGameAIController>(owner_Comp.GetAIOwner());
	auto const npc = cont->GetPawn();
	
	FVector const origin = npc->GetActorLocation();
	FNavLocation loc;

	UNavigationSystemV1* const nav_sys = UNavigationSystemV1::GetCurrent(GetWorld());
	if (nav_sys->GetRandomPointInNavigableRadius(origin, search_radius, loc, nullptr))
	{
		cont->get_blackboard()->SetValueAsVector(bb_keys::target_location, loc);
	}

	FinishLatentTask(owner_Comp, EBTNodeResult::Succeeded);

	return EBTNodeResult::Succeeded;
}
