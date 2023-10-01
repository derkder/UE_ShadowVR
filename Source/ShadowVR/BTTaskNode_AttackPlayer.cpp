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
        // 获取玩家控制器
        APlayerController* PlayerController = UGameplayStatics::GetPlayerController(EnemyCharacter, 0);

        if (PlayerController)
        {
            // 获取玩家角色
            ACharacter* PlayerCharacter = Cast<ACharacter>(PlayerController->GetPawn());

            if (PlayerCharacter)
            {
                // 获取自身和玩家之间的距离
                float DistanceToPlayer = FVector::Distance(EnemyCharacter->GetActorLocation(), PlayerCharacter->GetActorLocation());

                // 如果距离在100以内，则调用玩家的受击函数
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