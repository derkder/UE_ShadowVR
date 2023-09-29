// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BaseAIController.generated.h"

/**
 * 
 */
UCLASS()
class SHADOWVR_API ABaseAIController : public AAIController
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UBehaviorTree* BehaviorTree;

protected:
	virtual void BeginPlay() override;
};
