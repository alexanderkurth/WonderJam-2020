// Fill out your copyright notice in the Description page of Project Settings.


#include "GameJamEnemy.h"

// Sets default values
AGameJamEnemy::AGameJamEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGameJamEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGameJamEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float AGameJamEnemy::GetHealth()
{
	return health;
}

//prends la valeurs de degat
void AGameJamEnemy::SetHealth(float vie)
{
	this->health = vie;
}

float AGameJamEnemy::GetDegat()
{
	return degats;
}

//prends la valeurs de degat
void AGameJamEnemy::SetDegat(float damage)
{
	this->degats = damage;
}

float AGameJamEnemy::GetDefense()
{
	return this->defense;
}

void AGameJamEnemy::SetDefense(float def)
{
	this->defense = def;
}

void AGameJamEnemy::TakeDammage(float damage)
{
	this->health -= damage > defense ? (damage - defense) : 0;
}

void AGameJamEnemy::Fight()
{
}
