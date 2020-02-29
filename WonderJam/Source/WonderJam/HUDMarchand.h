// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HUDMarchand.generated.h"

#define COUT_POINT -1
#define UP_DAMAGE 0.5f
#define MAX_HEALTH 10.f
#define VOL_VIE 0.5f
#define MAX_FRENESIE 10.f
#define DEFENSE 1.f
#define BAISSE_FRENESIE 0.25f

/**
 *
 */

class AGameJamCharacter;
class UButton;
class UTextBlock;

UCLASS()
class WONDERJAM_API UHUDMarchand : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY()
		AGameJamCharacter* player;

public:

	UPROPERTY(meta = (BindWidgetOptional))
		UButton* returnBtn;
	UPROPERTY(meta = (BindWidgetOptional))
		UButton* degatsUpBtn;
	UPROPERTY(meta = (BindWidgetOptional))
		UButton* maxVieUpBtn;
	UPROPERTY(meta = (BindWidgetOptional))
		UButton* volVieUpBtn;
	UPROPERTY(meta = (BindWidgetOptional))
		UButton* maxFrenesieUpBtn;
	UPROPERTY(meta = (BindWidgetOptional))
		UButton* defenseUpBtn;
	UPROPERTY(meta = (BindWidgetOptional))
		UButton* baisseFrenesieUpBtn;

	UPROPERTY(meta = (BindWidgetOptional))
		UTextBlock* pointValue;
	UPROPERTY(meta = (BindWidgetOptional))
		UTextBlock* damageValue;
	UPROPERTY(meta = (BindWidgetOptional))
		UTextBlock* maxVieValue;
	UPROPERTY(meta = (BindWidgetOptional))
		UTextBlock* volVieValue;
	UPROPERTY(meta = (BindWidgetOptional))
		UTextBlock* maxFrenesieValue;
	UPROPERTY(meta = (BindWidgetOptional))
		UTextBlock* defenseValue;
	UPROPERTY(meta = (BindWidgetOptional))
		UTextBlock* frenesieValue;

	TArray<UButton*> buttons;
	int buttonIndex;

#pragma region couleur interaction

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "couleur")
		FColor selectedColor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "couleur")
		FColor defaultColor;

#pragma endregion

	bool isOpen;

	bool Initialize();
	void NativeConstruct();

#pragma region Retour Action

	UFUNCTION(BlueprintCallable)
		void ReturnGame();
	UFUNCTION(BlueprintCallable)
		void ReturnHover();
	UFUNCTION(BlueprintCallable)
		void ReturnUnhover();

#pragma endregion

#pragma region Up

	UFUNCTION(BlueprintCallable)
		void DegatUpGame();
	UFUNCTION(BlueprintCallable)
		void MaxVieUpGame();
	UFUNCTION(BlueprintCallable)
		void VolVieUpGame();
	UFUNCTION(BlueprintCallable)
		void MaxFrenesieUpGame();
	UFUNCTION(BlueprintCallable)
		void DefenseUpGame();
	UFUNCTION(BlueprintCallable)
		void BaisseFrenesieUpGame();

#pragma endregion

};
