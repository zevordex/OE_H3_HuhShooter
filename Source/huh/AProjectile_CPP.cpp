// Fill out your copyright notice in the Description page of Project Settings.


#include "AProjectile_CPP.h"

// Sets default values
AAProjectile_CPP::AAProjectile_CPP()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAProjectile_CPP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAProjectile_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

