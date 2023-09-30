// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BTService_CheckAttackRange.generated.h"

/**
 * 
 */
UCLASS()
class SHADOWVR_API UBTService_CheckAttackRange : public UBTService
{
	GENERATED_BODY()
protected:
	//可以动态的修改绑定的黑板键
	UPROPERTY(EditAnywhere, Category = "AI")
	FBlackboardKeySelector FollowRangeKey;

	UPROPERTY(EditAnywhere, Category = "AI")
	FBlackboardKeySelector AttackRangeKey;

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
};
