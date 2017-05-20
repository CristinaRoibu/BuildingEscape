// Copyright Cristina Roibu 2017

#pragma once

#include "GameFramework/Actor.h"
#include "Level3Enemy.generated.h"

UCLASS()
class BUILDINGESCAPE_API ALevel3Enemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevel3Enemy();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(VisibleDefaultsOnly, Category = "CubeEnemy")
	UStaticMeshComponent* CubeEnemy;//valorizzata nel blueprint che estende questa classe

	void EnemyMethod();

	TArray<AActor*> OverlappedEnemy;

	UPROPERTY(VisibleDefaultsOnly, Category = "CubeEnemy")
	UBoxComponent* EnemyCollision;

	UFUNCTION()
	void OverlappedMe(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	FVector EnemyPosition;

	bool ChangeDirection = false;

	bool CanDoDamage = true;
	UFUNCTION()
	void ResetCanDoDamage();
};
