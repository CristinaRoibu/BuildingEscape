// Copyright Cristina Roibu 2017

#include "BuildingEscape.h"
#include "DefaultPawnParent.h"
#include "Arrow.h"
void ADefaultPawnParent::PickUpNuked() {//this method is called
	NumberOfPicky = NumberOfPicky + 10;
	//UE_LOG(LogTemp, Warning, TEXT("Im sexy and I know it"));

	//OpenLevel(UObject* WorldContextObject, FName LevelName, bool bAbsolute = true, FString Options = FString(TEXT("")));
	if (NumberOfPicky == 50) { UGameplayStatics::OpenLevel(this, FName("NewMap4")); }
}

void ADefaultPawnParent::RestartLevel() {
	UGameplayStatics::OpenLevel(this, FName("NewMap3"));
}

 void ADefaultPawnParent::Tick(float DeltaTime) {
	 Super::Tick(DeltaTime);
	
	 bool Balls;
	 TheWorld = GetWorld();
	 APlayerController* VarPlayerController;
	 VarPlayerController = TheWorld->GetFirstPlayerController();//valorizza la variabile VarPlayerController
	
	 FVector CameraVector;
	 FRotator CameraRotator;
	 VarPlayerController->GetPlayerViewPoint(CameraVector, CameraRotator);//here you call the method GetPlayerController which gives you 2 out parameters that valorizzano le due variabili sopra
	 EndForwardVectorPawn = (CameraRotator.Vector() * 1500.f) + CameraVector; //moltiplica la lunghezza vector

	 Balls = TheWorld->LineTraceSingleByChannel(//this one gives you the hit result (makes linetrace but you do not see it)
		 OutHit,
		 CameraVector,
		 EndForwardVectorPawn,
		 ECollisionChannel::ECC_Visibility//puoi scrivere ECC_Visibility senza fare ECollisionChannel::
	);
	

	 DrawDebugLine(//makes the linetrace that you can see(does not detect collisions)
		 TheWorld,
		 CameraVector,
		 EndForwardVectorPawn,
		 FColor::Red,
		 false,
		 0.f,
		 0,
		 15.f
	 );

	 if (Balls) { EndForwardVectorPawn = OutHit.Location; }
	 FVector TossVelocity;
	 bool asd = UGameplayStatics::SuggestProjectileVelocity(//makes an line that is an ark 
		 this,
		 TossVelocity,
		 CameraVector,
		 EndForwardVectorPawn,
		 1900.f,
		 false, //if its true it will make a higher ark
		 0.f,
		 0.f,
		 ESuggestProjVelocityTraceOption::DoNotTrace,
		 FCollisionResponseParams::DefaultResponseParam,
		 TArray<AActor*>(),
		 true
	 );

	 UE_LOG(LogTemp, Warning, TEXT("%i"), asd);
	/* (UObject* WorldContextObject,
		 FVector& TossVelocity, 
		 FVector StartLocation,
		 FVector EndLocation, 
		 float TossSpeed, 
		 bool bHighArc = false, 
		 float CollisionRadius = 0.f,
		 float OverrideGravityZ = 0, 
		 ESuggestProjVelocityTraceOption::Type TraceOption = ESuggestProjVelocityTraceOption::TraceFullPath,
		 const FCollisionResponseParams& ResponseParam = FCollisionResponseParams::DefaultResponseParam, 
		 const TArray<AActor*>& ActorsToIgnore = TArray<AActor*>(), 
		 bool bDrawDebug = false);*/


	/*	void DrawDebugLine(const UWorld* InWorld, 
			FVector const& LineStart, F
			FVector const& LineEnd, 
			FColor const& Color, 
			bool bPersistentLines = false, 
			float LifeTime = -1.f, 
			uint8 DepthPriority = 0, 
			float Thickness = 0.f);*/
	
	
	if (Balls == false) { return; }
	 UE_LOG(LogTemp, Warning, TEXT("birubirubiru %i %s"), Balls, *OutHit.GetActor()->GetName());
	
	/* bool LineTraceSingleByChannel(
		 struct FHitResult& OutHit, 
		 const FVector& Start, 
		 const FVector& End,
		 ECollisionChannel TraceChannel,
		 const FCollisionQueryParams& Params = FCollisionQueryParams::DefaultQueryParam,
		 const FCollisionResponseParams& ResponseParam = FCollisionResponseParams::DefaultResponseParam) const;
	*/
	 
	
	 }
 void ADefaultPawnParent::SpawnArrow() {
	 // T* SpawnActor(UClass* Class, FVector const& Location, FRotator const& Rotation, const FActorSpawnParameters& SpawnParameters = FActorSpawnParameters())

	 GetWorld()->SpawnActor<AArrow>(
		 ArrowClass,
		 GetActorLocation(),
		 GetActorForwardVector().Rotation() //so you spawn it with the rotation of where che pawn looks
		 );
}