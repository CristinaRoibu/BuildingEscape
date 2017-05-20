// Copyright Cristina Roibu 2017

#include "BuildingEscape.h"
#include "BullsEye.h"


// Sets default values
ABullsEye::ABullsEye()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ABullsEye::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABullsEye::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

