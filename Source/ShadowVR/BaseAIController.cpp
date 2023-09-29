// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "BaseAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

void ABaseAIController::BeginPlay()
{
	Super::BeginPlay();
	if (ensure(BehaviorTree))
	{
		RunBehaviorTree(BehaviorTree);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Godzilla !BehaviorTree"));
	}

	APawn* MyPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	UBlackboardComponent* MyBlackboard = GetBlackboardComponent();
	if (MyPawn && MyBlackboard)
	{
		MyBlackboard->SetValueAsVector("MoveToLocation", MyPawn->GetActorLocation());
		MyBlackboard->SetValueAsObject("TargetActor", MyPawn);
		UE_LOG(LogTemp, Warning, TEXT("MyPawn's Location: X=%f, Y=%f, Z=%f"), MyPawn->GetActorLocation().X, MyPawn->GetActorLocation().Y, MyPawn->GetActorLocation().Z);
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("Godzilla !MyPawn && MyBlackboard"));
	}
}