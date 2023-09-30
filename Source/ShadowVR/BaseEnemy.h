// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BaseEnemy.generated.h"

UCLASS()
class SHADOWVR_API ABaseEnemy : public APawn
{
	GENERATED_BODY()

	UPROPERTY(EditAnyWhere)
	float Enemy_HP;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	ABaseEnemy();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

};
