// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileManager_CPP.h"



// Sets default values
AProjectileManager_CPP::AProjectileManager_CPP()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AProjectileManager_CPP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectileManager_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AAProjectile_CPP* AProjectileManager_CPP::SpawnRealProjectile(TSubclassOf<AAProjectile_CPP> ProjectileClass, FTransform SpawnTransform, APawn *Instigatorr, double Lifetime, FVector Direction)
{
	if (!IsValid(ProjectileClass)) return nullptr;
	AAProjectile_CPP* Spawned = GetWorld()->SpawnActorDeferred<AAProjectile_CPP>(ProjectileClass, SpawnTransform,nullptr,Instigatorr);
	if (IsValid(Spawned)){
		Spawned->LifeTime = Lifetime;
		Spawned->SetLifeSpan(Lifetime);
		Spawned->Direction = Direction;

		RealProjectiles.Add(GlobalProjectileCounter, Spawned);
		IncrementProjectileCounter();

		Spawned->FinishSpawning(SpawnTransform);
	}
	return Spawned;
}

int AProjectileManager_CPP::IncrementProjectileCounter()
{
	GlobalProjectileCounter++;
	return GlobalProjectileCounter;
}

