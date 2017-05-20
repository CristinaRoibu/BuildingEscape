// Copyright Cristina Roibu 2017

#pragma once

#include "GameFramework/DefaultPawn.h"
#include "DefaultPawnParent.generated.h"

/**
 * 
 */
UCLASS()
class BUILDINGESCAPE_API ADefaultPawnParent : public ADefaultPawn
{
	GENERATED_BODY()
	
public:
	void PickUpNuked();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Points")
	int NumberOfPicky;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Life")
	float MaxLife = 10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Life")
	float CurrentLife = 10;
	
	UFUNCTION(BlueprintCallable, Category ="RestartLevel")
	void RestartLevel();

	virtual void Tick(float DeltaSeconds) override;

	FVector EndForwardVectorPawn;
	FHitResult OutHit;


	UWorld* TheWorld;
	UFUNCTION(BlueprintCallable, Category = "ShootArrow")
	void SpawnArrow();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ShootArrow")
	TSubclassOf<class AArrow> ArrowClass; //ask the blueprint for a class to spawn that is child of AArow or AArow itself. This is the class to spawn
};
