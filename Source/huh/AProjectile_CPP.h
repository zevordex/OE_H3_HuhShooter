// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AProjectile_CPP.generated.h"

UCLASS()
class HUH_API AAProjectile_CPP : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAProjectile_CPP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		double LifeTime = 5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector Direction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool CustomTickAction = false;

};
