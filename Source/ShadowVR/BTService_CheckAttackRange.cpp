#include "BTService_CheckAttackRange.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

void UBTService_CheckAttackRange::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    UBlackboardComponent* BlackBoardComp = OwnerComp.GetBlackboardComponent();
    if (ensure(BlackBoardComp))
    {
        AActor* TargetActor = Cast<AActor>(BlackBoardComp->GetValueAsObject("TargetActor"));
        if (TargetActor)
        {
            AAIController* MyController = OwnerComp.GetAIOwner();
            if (ensure(MyController))
            {
                APawn* AIPawn = MyController->GetPawn();
                if (ensure(AIPawn))
                {
                    float DistanceTo = FVector::Distance(TargetActor->GetActorLocation(), AIPawn->GetActorLocation());
                    BlackBoardComp->SetValueAsBool(FollowRangeKey.SelectedKeyName, DistanceTo > 100.f && DistanceTo < 600.f);
                    BlackBoardComp->SetValueAsBool(AttackRangeKey.SelectedKeyName, DistanceTo < 100.f);
                }
            }
        }
    }

}