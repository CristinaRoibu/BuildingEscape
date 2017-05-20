// Copyright Cristina Roibu 2017

#include "BuildingEscape.h"
#include "OpenDoor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	//ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn(); dont need it anymore, now doors open because of weight not pawn
	Owner = GetOwner(); //since GetOwner() return a pointer AActor variable needs to be a pointer
	if (!PressurePlate) {
		UE_LOG(LogTemp, Warning, TEXT("NO PRESSURE PLATE!!!!!"));
	}
}


// Called every frame
void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	if (GetTotalMassActorsOnPlate() > 50.f) { //poll(check every frame) the triggerVolume, if actor that opens is in the volume
		OnOpen.Broadcast(); //when open door is called, instead of setting the rotation directly we are broadcasting on that event
								   //whenever the method open door is called this will broadcast and the listeners will act when they receive the broadcast
		//LastDoorOpenTime = GetWorld()->GetTimeSeconds(); // store in the variable this exact time
	}else{
	    //UE_LOG(LogTemp, Warning, TEXT("%f %f"), GetWorld()->GetTimeSeconds(), LastDoorOpenTime)
		OnClose.Broadcast();
	}
}

float UOpenDoor::GetTotalMassActorsOnPlate() {
	float TotalMass = 0.f;
	
	TArray<AActor*> OnPlateActors;
	PressurePlate->GetOverlappingActors(OUT OnPlateActors); //find overlapping actors and add their masses, pressure plate is a variable that contains the triggerVolume
	if (!PressurePlate) { return TotalMass; };
	for (AActor* ArrayActor : OnPlateActors) {
		UE_LOG(LogTemp, Warning, TEXT("OBJECT: %s"), *(ArrayActor->GetName()) );
		UPrimitiveComponent* ThePrimitiveComponent = ArrayActor->FindComponentByClass<UPrimitiveComponent>();
		TotalMass += ThePrimitiveComponent->GetMass();
	}
			/*for (int32 i = 0; i < OnPlateActors.Num(); i++ ) {
				UE_LOG(LogTemp, Warning, TEXT("OBJECT: %s"), *OnPlateActors.Last()->GetName());
			}*/
	return TotalMass;
}