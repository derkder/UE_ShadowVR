// Fill out your copyright notice in the Description page of Project Settings.

#include "AIController.h"
#include "Engine/EngineTypes.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Character.h"
#include "BaseEnemyCharacter.h"
#include "Engine/DamageEvents.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BTTaskNode_AttackPlayer.h"

EBTNodeResult::Type UBTTaskNode_AttackPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    UE_LOG(LogTemp, Warning, TEXT("Godzilla AttackPlayer"));
    ABaseEnemyCharacter* EnemyCharacter = Cast<ABaseEnemyCharacter>(OwnerComp.GetAIOwner()->GetPawn());
    if (EnemyCharacter)
    {
        // ��ȡ��ҿ�����
        APlayerController* PlayerController = UGameplayStatics::GetPlayerController(EnemyCharacter, 0);

        if (PlayerController)
        {
            // ��ȡ��ҽ�ɫ
            ACharacter* PlayerCharacter = Cast<ACharacter>(PlayerController->GetPawn());

            if (PlayerCharacter)
            {
                // ��ȡ��������֮��ľ���
                float DistanceToPlayer = FVector::Distance(EnemyCharacter->GetActorLocation(), PlayerCharacter->GetActorLocation());

                // ���������100���ڣ��������ҵ��ܻ�����
                if (DistanceToPlayer <= EnemyCharacter->GetAttackRange())
                {
                    PlayerCharacter->TakeDamage(EnemyCharacter->GetAttackNum(), FDamageEvent(), nullptr, EnemyCharacter);

                }

                return EBTNodeResult::Succeeded;
            }
        }
    }
    return EBTNodeResult::Failed;
}