// Copyright Cristina Roibu 2017

#include "BuildingEscape.h"
#include "OpenDoorWeirdly.h"
#include "WeirdDoor.h"


/*void AOpenDoorWeirdly::TriggerOpening() {
	OnActorBeginOverlap.AddDynamic(this, &AOpenDoorWeirdly::StillTriggering);
}*/

void AOpenDoorWeirdly::BeginPlay() {
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &AOpenDoorWeirdly::StillTriggering);
}

void AOpenDoorWeirdly::StillTriggering(AActor* actor1, AActor* actor2) {
	//start the open door animation
	WeirdDoorVar->Open();
}