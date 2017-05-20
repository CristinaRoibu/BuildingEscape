// Copyright Cristina Roibu 2017

#pragma once

#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;
	void FindPhysicsHandle();
	void SetupInputComponent();

private:
	float Reach = 100.f;
	UInputComponent* InputComponentOfPawn = nullptr;
	UPhysicsHandleComponent* MyPhysicsHandle = nullptr; //like initializing a variable with zero

	void Grab();  //raycast and grab whats in reach
	void Release();
	
	const FHitResult GetFirstPhysicsBodyInReach();
	FVector LineTraceEnd;
	FVector PlayerViewPointLocation;
	FVector GetReachLineEnd();
};
