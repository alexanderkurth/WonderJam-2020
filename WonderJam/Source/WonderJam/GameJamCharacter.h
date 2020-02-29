// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameJamCharacter.generated.h"


class UUserWidget;

UCLASS()
class WONDERJAM_API AGameJamCharacter : public ACharacter
{
	GENERATED_BODY()

protected:

	bool isFighting = false;
	FTimerHandle MemberTimerHandle;
	FTimerHandle getAgro;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float maxHealth = 100;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float limiteFrenzy = 100;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float maxFrenzy = 200;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float health = 100;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float frenzy = 10;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float decreaseFrenzy = 0.5f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float degats = 1;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float attqSpeed = 1;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float defense = 5;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float volVie = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int point = 10;

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool isFightAnime = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Widgets")
		TSubclassOf<UUserWidget> wMarchand;
	UPROPERTY()
		UUserWidget* HUD_Marchand;

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
		float GetFrenzy();
	UFUNCTION(BlueprintCallable)
		void SetFrenzy(float frenesie);
	UFUNCTION(BlueprintCallable)
		float GetDecreaseFrenzy();
	UFUNCTION(BlueprintCallable)
		void SetDecreaseFrenzy(float frenesie);
	UFUNCTION(BlueprintCallable)
		float GetLimiteFrenzy();
	UFUNCTION(BlueprintCallable)
		void SetLimiteFrenzy(float frenesi);
	UFUNCTION(BlueprintCallable)
		float GetMaxFrenzy();
	UFUNCTION(BlueprintCallable)
		void SetMaxFrenzy(float frenesi);

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

	UFUNCTION(BlueprintCallable)
		int GetPoint();
	UFUNCTION(BlueprintCallable)
		void SetPoint(int addPoint);

#pragma endregion

	UFUNCTION(BlueprintCallable)
		void TakeDammage(float damage);

	UFUNCTION(BlueprintCallable)
		void StartFight();

	UFUNCTION(BlueprintCallable)
		void StopFight();

	UFUNCTION(BlueprintCallable)
		void Fight();

	UFUNCTION(BlueprintCallable)
		void OpenMenuMarchand();
	UFUNCTION(BlueprintCallable)
		void CloseMenuMarchand();

};
