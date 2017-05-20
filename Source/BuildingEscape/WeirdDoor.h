// Copyright Cristina Roibu 2017

#pragma once

#include "GameFramework/Actor.h"
#include "WeirdDoor.generated.h"

UCLASS()
class BUILDINGESCAPE_API AWeirdDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeirdDoor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintImplementableEvent, Category = "Open fricking door")
		void Open(); 
	
};
