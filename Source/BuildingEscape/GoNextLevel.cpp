// Copyright Cristina Roibu 2017

#include "BuildingEscape.h"
#include "GoNextLevel.h"




void AGoNextLevel::BeginPlay() {
	Super::BeginPlay(); //calls the original Beginplay method
	OnActorBeginOverlap.AddDynamic(this, &AGoNextLevel::CallNextLevel); //this: on this insatance of this class||&AGoNextLevel::CallNextLevel: passes the memory address of this method

}

void AGoNextLevel::CallNextLevel(AActor* Actor1, AActor* Actor2) { // actors are the trigger and the overlapping thing
	UGameplayStatics::OpenLevel(this, FName("NewMap2")); //static void OpenLevel(UObject* WorldContextObject, FName LevelName, bool bAbsolute = true, FString Options = FString(TEXT("")));
}