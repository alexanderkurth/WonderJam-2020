// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameJamEnemy.generated.h"

UCLASS()
class WONDERJAM_API AGameJamEnemy : public APawn
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float health = 100;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float degats = 1;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float attqSpeed = 1;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float defense = 5;

public:
	// Sets default values for this character's properties
	AGameJamEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

#pragma region ascesseur

	UFUNCTION(BlueprintCallable)
		float GetHealth();
	UFUNCTION(BlueprintCallable)
		void SetHealth(float vie);

	UFUNCTION(BlueprintCallable)
		float GetDegat();
	UFUNCTION(BlueprintCallable)
		void SetDegat(float damage);
	UFUNCTION(BlueprintCallable)
		float GetDefense();
	UFUNCTION(BlueprintCallable)
		void SetDefense(float def);

#pragma endregion

	UFUNCTION(BlueprintCallable)
		void TakeDammage(float damage);


	UFUNCTION(BlueprintCallable)
		void Fight();
};
