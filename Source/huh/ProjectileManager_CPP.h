// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AProjectile_CPP.h"
#include "ProjectileManager_CPP.generated.h"

USTRUCT(BlueprintType)
struct FSHypoProjectile
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		double SecondsTimestamp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		double Lifetime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector Direction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		double Damage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		APawn* Owner;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int RenderId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		double Size;
};


UCLASS()
class HUH_API AProjectileManager_CPP : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileManager_CPP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int GlobalProjectileCounter = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		double BulletTickrate = 0.0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TMap<int, FSHypoProjectile> HypoProjectiles;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TMap<int, AAProjectile_CPP*> RealProjectiles;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SpawnRealProjectile", Keywords = "Projectile"), Category = "ProjectileManager")
		AAProjectile_CPP* SpawnRealProjectile(TSubclassOf<AAProjectile_CPP> ProjectileClass, FTransform SpawnTransform, APawn *Instigatorr, double Lifetime, FVector Direction);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "IncrementProjectileCounter", Keywords = "Projectile"), Category = "ProjectileManager")
		int IncrementProjectileCounter();

};
