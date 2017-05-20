// Copyright Cristina Roibu 2017

#pragma once

#include "GameFramework/Actor.h"
#include "PickMeUp.generated.h"


UCLASS()
class BUILDINGESCAPE_API APickMeUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickMeUp();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(VisibleDefaultsOnly, Category="Picky")//to make it visible in the BP that extends this C++ class
	UStaticMeshComponent* ThePickMeUp;
private:
	void OverlappPawn();
	TArray<AActor*> OverlappingActor;
	
};
