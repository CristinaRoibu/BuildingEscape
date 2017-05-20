// Copyright Cristina Roibu 2017

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	void CloseDoor();
	
	UPROPERTY(BlueprintAssignable)
		FDoorEvent OnOpen;
	
	UPROPERTY(BlueprintAssignable)
		FDoorEvent OnClose;

private:
	UPROPERTY(EditAnywhere)
	float OpenAngle = -90.0f;
	
	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate; //contains the trigger volume

	//AActor* ActorThatOpens; //pawn inherits from actor

	AActor* Owner = nullptr;
	
	float GetTotalMassActorsOnPlate(); //returns total mass in kilograms

	
};
