// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionTypes.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "MyTestGameAIController.generated.h"

/**
 * 
 */
UCLASS(config = Game)
class TESTMYGAME_API AMyTestGameAIController : public AAIController
{
	GENERATED_BODY()

public:
	AMyTestGameAIController(FObjectInitializer const& object_initializer = FObjectInitializer::Get());

	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* pawn) override;
	virtual void Tick(float DeltaSeconds) override;
	virtual FRotator GetControlRotation()const override;

	class UBlackboardComponent* get_blackboard();

	UFUNCTION(BlueprintCallable, Category = Behavior)
		void on_target_detected(AActor* actor, FAIStimulus const stimulus);


private:
	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category = "AI", meta = (AllowPrivateAccess = "true"))
		UBehaviorTreeComponent * behavior_tree_Comp;

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category = "AI", meta = (AllowPrivateAccess = "true"))
		UBehaviorTree* btree;

	UBlackboardComponent* blackboard;
	UAISenseConfig_Sight* sight_config;

	void setup_perception_system();
	
};
