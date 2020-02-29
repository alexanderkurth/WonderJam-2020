// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HUDPause.generated.h"

/**
 * 
 */

class AGameJamCharacter;
class UButton;

UCLASS()
class WONDERJAM_API UHUDPause : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY()
		AGameJamCharacter* player;

	FTimerHandle TimerHandle;

public:

	UPROPERTY(meta = (BindWidgetOptional))
		UButton* returnBtn;
	UPROPERTY(meta = (BindWidgetOptional))
		UButton* exitBtn;

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
		void ExitGame();
	UFUNCTION(BlueprintCallable)
		void ExitHover();
	UFUNCTION(BlueprintCallable)
		void ExitUnhover();

#pragma endregion

#pragma region Continue Action

	UFUNCTION(BlueprintCallable)
		void ContinueGame();
	UFUNCTION(BlueprintCallable)
		void ContinueHover();
	UFUNCTION(BlueprintCallable)
		void ContinueUnhover();

#pragma endregion
};
