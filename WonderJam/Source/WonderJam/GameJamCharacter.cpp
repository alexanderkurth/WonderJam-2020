// Fill out your copyright notice in the Description page of Project Settings.


#include "GameJamCharacter.h"
#include "Engine/Engine.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

// Sets default values
AGameJamCharacter::AGameJamCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGameJamCharacter::BeginPlay()
{
	Super::BeginPlay();

	health = 100;

	isFighting = false;

	isFightAnime;
	
	if(wMarchand)
		HUD_Marchand =  UUserWidget::CreateWidgetInstance(*this->Controller->CastToPlayerController(), wMarchand, wMarchand.GetDefaultObject()->GetFName());


}

// Called every frame
void AGameJamCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AGameJamCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Attaque", IE_Pressed, this, &AGameJamCharacter::StartFight);
	PlayerInputComponent->BindAction("Attaque", IE_Released, this, &AGameJamCharacter::StopFight);
	PlayerInputComponent->BindAction("OpenUpgrade", IE_Pressed, this, &AGameJamCharacter::OpenMenuMarchand);
}

#pragma region assesseur

float AGameJamCharacter::GetMaxHealth()
{
	return this->maxHealth;
}

void AGameJamCharacter::SetMaxHealth(float vie)
{
	this->maxHealth += vie;
}

float AGameJamCharacter::GetHealth()
{
	return this->health;
}

void AGameJamCharacter::SetHealth(float vie)
{
	this->health += vie;
}

float AGameJamCharacter::GetFrenzy()
{
	return this->frenzy;
}

void AGameJamCharacter::SetFrenzy(float frenesie)
{
	this->frenzy += frenesie;
}

float AGameJamCharacter::GetDecreaseFrenzy()
{
	return this->decreaseFrenzy;
}

void AGameJamCharacter::SetDecreaseFrenzy(float frenesie)
{
	this->decreaseFrenzy += frenesie;
}

float AGameJamCharacter::GetLimiteFrenzy()
{
	return limiteFrenzy;
}

void AGameJamCharacter::SetLimiteFrenzy(float frenesi)
{
	this->limiteFrenzy += frenesi;
}

float AGameJamCharacter::GetMaxFrenzy()
{
	return maxFrenzy;
}

void AGameJamCharacter::SetMaxFrenzy(float frenesi)
{
	this->maxFrenzy += frenesi;
}

float AGameJamCharacter::GetDegat()
{
	return degats;
}

void AGameJamCharacter::SetDegat(float damage)
{
	degats += damage;
}

float AGameJamCharacter::GetSpeed()
{
	return attqSpeed;
}

void AGameJamCharacter::SetSpeed(float speed)
{
	this->attqSpeed += speed;
}

float AGameJamCharacter::GetDefense()
{
	return defense;
}

void AGameJamCharacter::SetDefense(float def)
{
	this->defense += def;
}

float AGameJamCharacter::GetVolVie()
{
	return this->volVie;
}

void AGameJamCharacter::SetVolVie(float absorption)
{
	volVie += absorption;
}

int AGameJamCharacter::GetPoint()
{
	return this->point;
}

void AGameJamCharacter::SetPoint(int addPoint)
{
	this->point += addPoint;
}


#pragma endregion

//fonction permettant d'infligé des dégats au joueur
void AGameJamCharacter::TakeDammage(float damage)
{
	this->health -= damage>defense?(damage - defense):0;
}

void AGameJamCharacter::StartFight()
{
	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AGameJamCharacter::Fight, 1 / this->attqSpeed, true, 0.0f);
}

void AGameJamCharacter::StopFight()
{
	GetWorldTimerManager().ClearTimer(MemberTimerHandle);
	isFightAnime = false;
}

//fonction pour infliger des dégatsau monstres
void AGameJamCharacter::Fight()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("fight"));
	//lancer anim
	//adapter anim a vitesse attaque
	//verifier les enemy touche ici ou dans enemy?
	isFightAnime = false;
}

void AGameJamCharacter::OpenMenuMarchand()
{
	if (HUD_Marchand)
		HUD_Marchand->AddToViewport();
}

void AGameJamCharacter::CloseMenuMarchand()
{
	HUD_Marchand->RemoveFromViewport();
	//UWidgetBlueprintLibrary::SetInputMode_GameOnly(this->GetController()->CastToPlayerController());
	//UWidgetBlueprintLibrary::SetInputMode_GameAndUI(this->GetController()->CastToPlayerController());
}
