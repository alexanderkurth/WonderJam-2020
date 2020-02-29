// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameJamCharacter.generated.h"

UCLASS()
class WONDERJAM_API AGameJamCharacter : public ACharacter
{
	GENERATED_BODY()

protected:

	bool isFighting = false;
	FTimerHandle MemberTimerHandle;

	float maxHealth = 100;
	float maxFrenesie = 100;
	float health = 100;
	float frenesie = 25;
	float degats = 1;
	float attqSpeed = 1;
	float defense = 5;
	float volVie = 1;

public:

	bool isFightAnime = false;

public:
	// Sets default values for this character's properties
	AGameJamCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

#pragma region ascesseur

	UFUNCTION(BlueprintCallable)
		float GetHealth();
	UFUNCTION(BlueprintCallable)
		void SetHealth(float vie);
	UFUNCTION(BlueprintCallable)
		float GetMaxHealth();
	UFUNCTION(BlueprintCallable)
		void SetMaxHealth(float vie);

	UFUNCTION(BlueprintCallable)
		float GetDegat();
	UFUNCTION(BlueprintCallable)
		void SetDegat(float damage);
	UFUNCTION(BlueprintCallable)
		float GetSpeed();
	UFUNCTION(BlueprintCallable)
		void SetSpeed(float speed);
	UFUNCTION(BlueprintCallable)
		float GetDefense();
	UFUNCTION(BlueprintCallable)
		void SetDefense(float def);
	UFUNCTION(BlueprintCallable)
		float GetVolVie();
	UFUNCTION(BlueprintCallable)
		void SetVolVie(float absorption);

#pragma endregion

	UFUNCTION(BlueprintCallable)
		void TakeDammage(float damage);

	UFUNCTION(BlueprintCallable)
		void StartFight();

	UFUNCTION(BlueprintCallable)
		void StopFight();

	UFUNCTION(BlueprintCallable)
		void Fight();

};
