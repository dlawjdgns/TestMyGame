// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTTask_FindPlayerLocation.h"
#include "Kismet/GameplayStatics.h"
#include "MyTestGameAIController.h"
#include "GameFramework/Character.h"
#include "NavigationSystem.h"
#include "blackboard_keys.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType.h"
#include "BehaviorTree/BlackboardComponent.h"

UMyBTTask_FindPlayerLocation::UMyBTTask_FindPlayerLocation(FObjectInitializer const& object_initializer)
{
	NodeName = TEXT("Find Player Location");
}

EBTNodeResult::Type UMyBTTask_FindPlayerLocation::ExecuteTask(UBehaviorTreeComponent& owner_Comp, uint8* node_memory)
{
	ACharacter* const player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	auto const cont = Cast<AMyTestGameAIController>(owner_Comp.GetAIOwner());

	FVector const player_location = player->GetActorLocation();
	if (search_random)
	{
		FNavLocation loc;

		UNavigationSystemV1* const nav_sys = UNavigationSystemV1::GetCurrent(GetWorld());
		if (nav_sys->GetRandomPointInNavigableRadius(player_location, search_radius, loc, nullptr))
		{
			cont->get_blackboard()->SetValueAsVector(bb_keys::target_location, loc.Location);
		}
	}
	else
	{
		cont->get_blackboard()->SetValueAsVector(bb_keys::target_location, player_location);
	}

	return EBTNodeResult::Type();
}
