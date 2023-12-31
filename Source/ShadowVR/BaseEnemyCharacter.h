// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseEnemyCharacter.generated.h"

UCLASS()
class SHADOWVR_API ABaseEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(EditAnyWhere)
	float Enemy_HP;

	UPROPERTY(EditAnyWhere)
	float Attack_Range = 100;

	UPROPERTY(EditAnyWhere)
	float Attack_Num = 15;;

public:
	// Sets default values for this character's properties
	ABaseEnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	float GetAttackNum() 
	{
		return Attack_Num;
	}

	float GetAttackRange()
	{
		return Attack_Range;
	}
};
