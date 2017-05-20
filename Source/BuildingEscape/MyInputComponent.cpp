// Copyright Cristina Roibu 2017

#include "BuildingEscape.h"
#include "MyInputComponent.h"
#include "MyUserWidget.h"

UMyInputComponent::UMyInputComponent() {
	PrimaryComponentTick.bCanEverTick = true;//means it can tick
}

void UMyInputComponent::BeginPlay() {
	Super::BeginPlay();
	BindAction("CheckRiddles", IE_Pressed, this, &UMyInputComponent::WordsControl);
}

void UMyInputComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	MoveWallUp();
	
}

void UMyInputComponent::MoveWallUp() {

	if (!TheLiftingWall) { return; }
	FVector VectorOfWall = TheLiftingWall->GetActorLocation();
	if (VectorOfWall.Z >= 270) { return; }
	if (!CorrectUsername && !CorrectPassword) { return; } //if they are both false do not call the method that lifts the wall
	RiddlesWidget->RemoveFromViewport();
	if (OutSweepHitResult.bBlockingHit == 1) { return; }
	TheLiftingWall->AddActorWorldOffset(FVector(0.f, 0.f, 1.f), false, &OutSweepHitResult, ETeleportType::TeleportPhysics);  //AddActorWorldOffset(FVector DeltaLocation, bool bSweep = false, FHitResult* OutSweepHitResult = nullptr, ETeleportType Teleport = ETeleportType::None);
}

void UMyInputComponent::WordsControl() {
	if (!RiddlesWidget) { return; }
	UE_LOG(LogTemp, Warning, TEXT("%s and %s"), *RiddlesWidget->Username, *RiddlesWidget->Password);
	if (RiddlesWidget->Username.Equals("fallen leaves", ESearchCase::IgnoreCase)) {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 50.0f, FColor::Blue, TEXT("Correct username!"));
			CorrectUsername = true;
		}
	}
	else {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 50.0f, FColor::Red, TEXT("WRONG USERNAME"));
		}
	}

	
	if (RiddlesWidget->Password.Equals("gum", ESearchCase::IgnoreCase)) {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 50.0f, FColor::Blue, TEXT("Correct password!"));
			CorrectPassword = true;
		}
		return;
	}
	else if (RiddlesWidget->Password.Equals("penis", ESearchCase::IgnoreCase) || RiddlesWidget->Password.Equals("dick", ESearchCase::IgnoreCase)) {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 50.0f, FColor::Red, TEXT("PASSWORD: C'MON BE SERIOUS!"));
		}
		return;
	}
	else{
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 50.0f, FColor::Red, TEXT("WRONG PASSWORD"));
		}
	}

	if (!TheLiftingWall) { return; }
	UE_LOG(LogTemp, Warning, TEXT("WIIIIIIIIIIIIIIIIIIII %s"), *TheLiftingWall->GetName());
}