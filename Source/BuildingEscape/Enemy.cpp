// Copyright Cristina Roibu 2017

#include "BuildingEscape.h"
#include "Enemy.h"


// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TheEnemy = CreateDefaultSubobject<UStaticMeshComponent>(FName("PillarEnemy"));//assign a MeshComponent to the instance TheEnemy. In the details panel we assigned the pillar to this variable
}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemy::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	MovingPillar();
}

void AEnemy::MovingPillar() {
	//(FVector DeltaLocation, bool bSweep = false, FHitResult* OutSweepHitResult = nullptr, ETeleportType Teleport = ETeleportType::None);
	if (GetActorLocation().Y <= LocationOne && !ChangeDirection) {
		AddActorWorldOffset(FVector(0.f, 35.f, 0.f), false); //moves this class and its components attached
	}else { ChangeDirection = true; } //if the pillar reaches its destination against the wall then stop and change direction

	if (ChangeDirection) {
		AddActorWorldOffset(FVector(0.f, -35.f, 0.f), true); //moves this class and its components attached
	}

	if (GetActorLocation().Y <= LocationTwo) { ChangeDirection = false; } //if the pillar is at this moment in its original position then swap directions go the other way
}