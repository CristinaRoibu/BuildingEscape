// Copyright Cristina Roibu 2017

#pragma once

#include "GameFramework/Actor.h"
#include "Enemy.generated.h"

UCLASS()
class BUILDINGESCAPE_API AEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemy();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//UPROPERTY(EditAnywhere, Category = "Pass The Enemy")
	//AActor* TheEnemy;
	UPROPERTY(EditAnywhere, Category = "Pass The Enemy") 
	UStaticMeshComponent* TheEnemy; //create instance of type StaticMeshComponent that will contain the enemy
	//another way to do that is to create a blueprint class that extends this class and assign there the pillar as the enemy
	UPROPERTY(EditAnywhere, Category = "Pass The Enemy")
	float LocationOne = 500.f; //the second pillar is setted at 501 because otherwize it wastes 2 frames trying to go into the wall(since the if says: <= "GetActorLocation().Y <= LocationOne=500") 
	UPROPERTY(EditAnywhere, Category = "Pass The Enemy")
	float LocationTwo = -270.f;

private:
	bool ChangeDirection = false;
	void MovingPillar();
};
