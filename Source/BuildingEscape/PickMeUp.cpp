// Copyright Cristina Roibu 2017

#include "BuildingEscape.h"
#include "PickMeUp.h"
#include "DefaultPawnParent.h"


// Sets default values
APickMeUp::APickMeUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ThePickMeUp = CreateDefaultSubobject<UStaticMeshComponent>(FName("Picky Up"));//the name is the one displayed in the details panel as the component
}

// Called when the game starts or when spawned
void APickMeUp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickMeUp::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	OverlappPawn();
}

void APickMeUp::OverlappPawn() {
	//GetOverlappingActors(TArray<AActor*>& OverlappingActors, TSubclassOf<AActor> ClassFilter=nullptr) const;
	GetOverlappingActors(OverlappingActor);
	if (OverlappingActor.Num() == 0 ) { return; }
	//UE_LOG(LogTemp, Warning, TEXT("bla bla bla donkey %s"), *OverlappingActor[0]->GetName() );
	ADefaultPawnParent* DefaultPawnParentObject = Cast<ADefaultPawnParent>(OverlappingActor[0]); //cast to ADefaultPawnParent to see if that is what you overlapped
	if (!DefaultPawnParentObject) { return; }
	DefaultPawnParentObject->PickUpNuked(); //call the method that is declared in the class DefaultPawnParent. We are acting on the specific class DefaultPawnParent(the instance used in the game)
	Destroy();
}