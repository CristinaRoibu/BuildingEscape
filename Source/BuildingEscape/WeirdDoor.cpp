// Copyright Cristina Roibu 2017

#include "BuildingEscape.h"
#include "WeirdDoor.h"


// Sets default values
AWeirdDoor::AWeirdDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWeirdDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeirdDoor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}