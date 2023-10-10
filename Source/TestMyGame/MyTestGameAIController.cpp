// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTestGameAIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Kismet/GameplayStatics.h"
#include "MyTestGameCharacter.h"


AMyTestGameAIController::AMyTestGameAIController(FObjectInitializer const& object_initializer)
{
	PrimaryActorTick.bCanEverTick = true;

	setup_perception_system();
}

void AMyTestGameAIController::BeginPlay()
{
	Super::BeginPlay();

	if (GetPerceptionComponent() != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("All System Set!"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No Component!"));
	}
}

void AMyTestGameAIController::OnPossess(APawn* pawn)
{
	Super::OnPossess(pawn);
}

void AMyTestGameAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

FRotator AMyTestGameAIController::GetControlRotation() const
{
	if (GetPawn() == nullptr)
	{
		return FRotator(0.f, 0.f, 0.f);
	}

	return FRotator(0.f, GetPawn()->GetActorRotation().Yaw, 0.0f);
}

UBlackboardComponent* AMyTestGameAIController::get_blackboard()
{
	return nullptr;
}

void AMyTestGameAIController::on_target_detected(AActor* actor, FAIStimulus const stimulus)
{
	if (auto const ch = Cast<AMyTestGameCharacter>(actor))
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "Find Player!!");
	}
}

void AMyTestGameAIController::setup_perception_system()
{
	sight_config = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component")));

	sight_config->SightRadius = 500.f;
	sight_config->LoseSightRadius = sight_config->SightRadius + 50.0f;
	sight_config->PeripheralVisionAngleDegrees = 90.0f;
	sight_config->SetMaxAge(5.0f);
	sight_config->AutoSuccessRangeFromLastSeenLocation = 520.0f;
	sight_config->DetectionByAffiliation.bDetectEnemies = true;
	sight_config->DetectionByAffiliation.bDetectFriendlies = true;
	sight_config->DetectionByAffiliation.bDetectNeutrals = true;

	GetPerceptionComponent()->SetDominantSense(*sight_config->GetSenseImplementation());
	GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this, &AMyTestGameAIController::on_target_detected);
	GetPerceptionComponent()->ConfigureSense(*sight_config);
}
