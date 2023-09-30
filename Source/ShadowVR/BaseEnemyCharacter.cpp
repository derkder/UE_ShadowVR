// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseAIController.h"
#include "BaseEnemyCharacter.h"

// Sets default values
ABaseEnemyCharacter::ABaseEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AIControllerClass = ABaseAIController::StaticClass();
	Enemy_HP = 40;
}

// Called when the game starts or when spawned
void ABaseEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float ABaseEnemyCharacter::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	// �����˺��߼����������Ѫ��
	Enemy_HP -= DamageAmount;
	if (0 == Enemy_HP)
	{
		Destroy();
	}
	// ������������������˺����߼�������������顢�������˶�����
	UE_LOG(LogTemp, Warning, TEXT("Godzilla ABaseEnemy::TakeDamage"));
	return DamageAmount;
}

