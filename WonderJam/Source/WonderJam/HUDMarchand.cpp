// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDMarchand.h"
#include "UMG/Public/Components/Button.h"
#include "UMG/Public/Components/TextBlock.h"
#include "GameJamCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

bool UHUDMarchand::Initialize()
{
	if(!Super::Initialize())
	return false;

	player = Cast<AGameJamCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	if (returnBtn)
	{
		returnBtn->OnClicked.AddDynamic(this, &UHUDMarchand::ReturnGame);
		returnBtn->OnHovered.AddDynamic(this, &UHUDMarchand::ReturnHover);
		returnBtn->OnUnhovered.AddDynamic(this, &UHUDMarchand::ReturnUnhover);
		returnBtn->SetBackgroundColor(defaultColor);
	}
	if (degatsUpBtn)
	{
		degatsUpBtn->OnClicked.AddDynamic(this, &UHUDMarchand::DegatUpGame);
		//degatsUpBtn->OnHovered.AddDynamic(this, &UHUDMarchand::ReturnHover);
		//degatsUpBtn->OnUnhovered.AddDynamic(this, &UHUDMarchand::ReturnUnhover);
	}
	if (maxVieUpBtn)
	{
		maxVieUpBtn->OnClicked.AddDynamic(this, &UHUDMarchand::MaxVieUpGame);
	}
	if (volVieUpBtn)
	{
		volVieUpBtn->OnClicked.AddDynamic(this, &UHUDMarchand::VolVieUpGame);
		//volVieUpBtn->OnHovered.AddDynamic(this, &UHUDMarchand::ReturnHover);
		//volVieUpBtn->OnUnhovered.AddDynamic(this, &UHUDMarchand::ReturnUnhover);
	}
	if (maxFrenesieUpBtn)
	{
		maxFrenesieUpBtn->OnClicked.AddDynamic(this, &UHUDMarchand::MaxFrenesieUpGame);
	}
	if (defenseUpBtn)
	{
		defenseUpBtn->OnClicked.AddDynamic(this, &UHUDMarchand::DefenseUpGame);
	}
	if (baisseFrenesieUpBtn)
	{
		baisseFrenesieUpBtn->OnClicked.AddDynamic(this, &UHUDMarchand::BaisseFrenesieUpGame);
	}

	return true;
}

void UHUDMarchand::NativeConstruct()
{
	//UWidgetBlueprintLibrary::SetInputMode_UIOnly(player->GetController()->CastToPlayerController(), this);

	if (pointValue)
	{
		pointValue->SetText(FText::FromString(FString::Printf(TEXT("%d"), player->GetPoint())));
	}
	if (damageValue)
	{
		damageValue->SetText(FText::FromString(FString::Printf(TEXT("%.2f + %.2f"), player->GetDegat(), UP_DAMAGE)));
	}
	if (maxVieValue)
	{
		maxVieValue->SetText(FText::FromString(FString::Printf(TEXT("%.2f + %.2f"), player->GetMaxHealth(), MAX_HEALTH )));
	}
	if (volVieValue)
	{
		volVieValue->SetText(FText::FromString(FString::Printf(TEXT("%.2f + %.2f"), player->GetVolVie(), VOL_VIE)));
	}
	if (maxFrenesieValue)
	{
		maxFrenesieValue->SetText(FText::FromString(FString::Printf(TEXT("%.2f + %.2f"), player->GetMaxFrenzy(), MAX_FRENESIE)));
	}
	if (defenseValue)
	{
		defenseValue->SetText(FText::FromString(FString::Printf(TEXT("%.2f + %.2f"), player->GetDefense(), DEFENSE)));
	}
	if (frenesieValue)
	{
		frenesieValue->SetText(FText::FromString(FString::Printf(TEXT("%.2f + %.2f"), player->GetDecreaseFrenzy(), BAISSE_FRENESIE)));
	}
	if (returnBtn)
		returnBtn->SetBackgroundColor(defaultColor);
}

void UHUDMarchand::ReturnGame()
{
	player->CloseMenuMarchand();
}

void UHUDMarchand::ReturnHover()
{
	returnBtn->SetBackgroundColor(selectedColor);
}

void UHUDMarchand::ReturnUnhover()
{
	returnBtn->SetBackgroundColor(defaultColor);
}

#pragma region Up action

void UHUDMarchand::DegatUpGame()
{
	if (player->GetPoint() > 0)
	{
		player->SetDegat(UP_DAMAGE);
		player->SetPoint(COUT_POINT);
		damageValue->SetText(FText::FromString(FString::Printf(TEXT("%.2f + %.2f"), player->GetDegat(), UP_DAMAGE)));
		if (pointValue)
		{
			pointValue->SetText(FText::FromString(FString::Printf(TEXT("%d"), player->GetPoint())));
		}
	}
}

void UHUDMarchand::MaxVieUpGame()
{
	if (player->GetPoint() > 0)
	{
		player->SetMaxHealth(MAX_HEALTH);
		player->SetPoint(COUT_POINT);
		maxVieValue->SetText(FText::FromString(FString::Printf(TEXT("%.2f + %.2f"), player->GetMaxHealth(), MAX_HEALTH)));
		if (pointValue)
		{
			pointValue->SetText(FText::FromString(FString::Printf(TEXT("%d"), player->GetPoint())));
		}
	}
}

void UHUDMarchand::VolVieUpGame()
{
	if (player->GetPoint() > 0)
	{
		player->SetVolVie(VOL_VIE);
		player->SetPoint(COUT_POINT);
		volVieValue->SetText(FText::FromString(FString::Printf(TEXT("%.2f + %.2f"), player->GetVolVie(), VOL_VIE)));
		if (pointValue)
		{
			pointValue->SetText(FText::FromString(FString::Printf(TEXT("%d"), player->GetPoint())));
		}
	}
}

void UHUDMarchand::MaxFrenesieUpGame()
{
	if (player->GetPoint() > 0)
	{
		player->SetLimiteFrenzy(MAX_FRENESIE / 2);
		player->SetMaxFrenzy(MAX_FRENESIE);
		player->SetPoint(COUT_POINT);
		maxFrenesieValue->SetText(FText::FromString(FString::Printf(TEXT("%.2f + %.2f"), player->GetMaxFrenzy(), MAX_FRENESIE)));
		if (pointValue)
		{
			pointValue->SetText(FText::FromString(FString::Printf(TEXT("%d"), player->GetPoint())));
		}
	}
}

void UHUDMarchand::DefenseUpGame()
{
	if (player->GetPoint() > 0)
	{
		player->SetDefense(DEFENSE);
		player->SetPoint(COUT_POINT);
		defenseValue->SetText(FText::FromString(FString::Printf(TEXT("%.2f + %.2f"), player->GetDefense(), DEFENSE)));
		if (pointValue)
		{
			pointValue->SetText(FText::FromString(FString::Printf(TEXT("%d"), player->GetPoint())));
		}
	}
}

void UHUDMarchand::BaisseFrenesieUpGame()
{
	if (player->GetPoint() > 0)
	{
		player->SetDecreaseFrenzy(BAISSE_FRENESIE);
		player->SetPoint(COUT_POINT);
		frenesieValue->SetText(FText::FromString(FString::Printf(TEXT("%.2f + %.2f"), player->GetDecreaseFrenzy(), BAISSE_FRENESIE)));
		if (pointValue)
		{
			pointValue->SetText(FText::FromString(FString::Printf(TEXT("%d"), player->GetPoint())));
		}
	}
}

#pragma endregion
