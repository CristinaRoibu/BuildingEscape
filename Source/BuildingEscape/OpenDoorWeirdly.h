// Copyright Cristina Roibu 2017

#pragma once

#include "Engine/TriggerBox.h"
#include "OpenDoorWeirdly.generated.h"

/**
 * 
 */
UCLASS()
class BUILDINGESCAPE_API AOpenDoorWeirdly : public ATriggerBox
{
	GENERATED_BODY()
	
private:
	//void TriggerOpening();
	virtual void BeginPlay() override;

	UFUNCTION()
	void StillTriggering(AActor* actor1, AActor* actor2); // actors are the trigger and the overlapping thing

	UPROPERTY(EditAnywhere, Category = "Open fricking door")
	class AWeirdDoor* WeirdDoorVar;
	
};
