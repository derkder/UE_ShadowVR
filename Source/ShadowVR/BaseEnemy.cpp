// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseEnemy.h"
#include "BaseAIController.h"

// Sets default values
ABaseEnemy::ABaseEnemy()
{
	PrimaryActorTick.bCanEverTick = true;
	AIControllerClass = ABaseAIController::StaticClass();
}

// Called when the game starts or when spawned
void ABaseEnemy::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABaseEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABaseEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float ABaseEnemy::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	// 处理伤害逻辑，例如减少血量
	Enemy_HP -= DamageAmount;

	// 在这里添加其他处理伤害的逻辑，例如死亡检查、播放受伤动画等
	UE_LOG(LogTemp, Warning, TEXT("Godzilla ABaseEnemy::TakeDamage"));
	return DamageAmount;
}
