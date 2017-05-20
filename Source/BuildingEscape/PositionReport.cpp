// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingEscape.h"
#include "PositionReport.h"


// Sets default values for this component's properties
UPositionReport::UPositionReport()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	
}


// Called when the game starts
void UPositionReport::BeginPlay()
{


	Super::BeginPlay(); //you call the original beginPlay code with this line (because this method is overrided here)
	FString Name = GetOwner()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("Name of owner %s"), *Name);//%S its a placeholder for the var string Name (*Name with the * it translates the string into a TCHAR)
	//UE_LOG(LogTemp, Warning, TEXT("Position report reporting for duty!!!!!!!!!"));//color Warning:yellow, Log=grey, Error:Red

	
	FVector ObjectPos; //create the variable of type vector
	ObjectPos = GetOwner()->GetActorLocation(); //the method GetOwner returns a pointer to actor|| GetTransform().position
	UE_LOG(LogTemp, Warning, TEXT("The location is %s"), *(ObjectPos.ToString()));//ToString transforms the vector into a string


	
}


// Called every frame
void UPositionReport::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

