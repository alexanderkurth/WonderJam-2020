// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDPause.h"
#include "UMG/Public/Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "GameJamCharacter.h"

bool UHUDPause::Initialize()
{
	if (!Super::Initialize())
		return false;

	player = Cast<AGameJamCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	if (returnBtn)
	{
		returnBtn->OnClicked.AddDynamic(this, &UHUDPause::ContinueGame);
		returnBtn->OnHovered.AddDynamic(this, &UHUDPause::ContinueHover);
		returnBtn->OnUnhovered.AddDynamic(this, &UHUDPause::ContinueUnhover);
		returnBtn->SetBackgroundColor(defaultColor);
	}
	if (exitBtn)
	{
		exitBtn->OnClicked.AddDynamic(this, &UHUDPause::ExitGame);
		exitBtn->OnHovered.AddDynamic(this, &UHUDPause::ExitHover);
		exitBtn->OnUnhovered.AddDynamic(this, &UHUDPause::ExitUnhover);
		exitBtn->SetBackgroundColor(defaultColor);
	}
	return true;
}

void UHUDPause::NativeConstruct()
{
}

void UHUDPause::ExitGame()
{
	FGenericPlatformMisc::RequestExit(false);
}

void UHUDPause::ExitHover()
{
	exitBtn->SetBackgroundColor(selectedColor);
}

void UHUDPause::ExitUnhover()
{
	exitBtn->SetBackgroundColor(defaultColor);
}

void UHUDPause::ContinueGame()
{
	player->ClosePause();
}

void UHUDPause::ContinueHover()
{
	returnBtn->SetBackgroundColor(selectedColor);
}

void UHUDPause::ContinueUnhover()
{
	returnBtn->SetBackgroundColor(defaultColor);
}
