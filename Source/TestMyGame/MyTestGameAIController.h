// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

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
	AMyTestGameAIController();

	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* pawn) override;
	virtual void Tick(float DeltaSeconds) override;
	virtual FRotator GetControlRotation()const override;

	UFUNCTION()
	void OnPawnDetected(const TArray<AActor*> &DetectedPawns);

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "AI")
	float AISightRadius = 500.f;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "AI")
	float AISightAge = 5.f;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "AI")
	float AILoseSightRadius = AISightRadius + 50.f;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "AI")
	float AIFieldOfView = 90.f;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "AI")
	class UAISenseConfig_Sight* SightConfig;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "AI")
	bool bIsPlayerDetected = false;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "AI")
	float DistanceToPlayer = 0.0f;

private:
	UPROPERTY(Transient)
		UBlackboardComponent* BlackboardComp;

	UPROPERTY(Transient)
		UBehaviorTreeComponent* BehaviorComp;
	
};
