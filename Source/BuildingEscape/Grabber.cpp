// Copyright Cristina Roibu 2017

#include "BuildingEscape.h"
#include "Grabber.h"


// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame. You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
}

void UGrabber::BeginPlay()// Called when the game starts
{
	Super::BeginPlay();
	FindPhysicsHandle();
	SetupInputComponent();
}
void UGrabber::SetupInputComponent() {
	InputComponentOfPawn = GetOwner()->FindComponentByClass<UInputComponent>(); //UInputComponent is the type of variable we created btw
	if (InputComponentOfPawn) {
		//UE_LOG(LogTemp, Error, TEXT("WOOOOOOOOOOOOOOOOOOOOOO"));
		InputComponentOfPawn->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab); //Add the input in project settings. When you press the key for Grab call a method in this class
		InputComponentOfPawn->BindAction("Grab", IE_Released, this, &UGrabber::Release);
	}
}

void UGrabber::FindPhysicsHandle() {
	MyPhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>(); //look for the physics handle
	if (MyPhysicsHandle) {
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("PHYSICS HANDLE NOT FOUND: %s"), *GetOwner()->GetName());
	}
}
void UGrabber::Grab() {
	UE_LOG(LogTemp, Warning, TEXT("GRAB GRAB"));
	FHitResult HitResult = GetFirstPhysicsBodyInReach();
	UPrimitiveComponent* ComponentToGrab = HitResult.GetComponent(); //get the component to grab
	AActor* ActorHit = HitResult.GetActor();//get the actor that has been hit
	//try and reach out actors with physics body collision channel set
	
	if (ActorHit != nullptr) {//if hit smth then attach a physics handle
		MyPhysicsHandle->GrabComponent(
			ComponentToGrab,
			NAME_None, //name of the bone to which it attaches
			ComponentToGrab->GetOwner()->GetActorLocation(), //Fvector
			true); //allow rotation
	}
}
FVector UGrabber::GetReachLineEnd() {
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint( //get player view point, GetPlayerViewPoint has OUT PARAMETERS will output the parameters
		OUT PlayerViewPointLocation, // OUT doesnt mean anything it just signifies that 
		OUT PlayerViewPointRotation);
	//UE_LOG(LogTemp, Warning, TEXT("Location: %s \n Rotation: %s"), *PlayerViewPointLocation.ToString(), *PlayerViewPointRotation.ToString()); //need to put the * so the variable becomes TCHAR array
	 return PlayerViewPointLocation + (PlayerViewPointRotation.Vector()* Reach);//endline of debug line, .Vector(gives the forward Vector)
}
void UGrabber::Release() {
	UE_LOG(LogTemp, Warning, TEXT("RELEASE RELEASE"));
	if (!MyPhysicsHandle) { return; }; //if pointer is null stop here
	if (MyPhysicsHandle->GrabbedComponent) {//release physics
		MyPhysicsHandle->ReleaseComponent();
	}
}
// Called every frame
void UGrabber::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	LineTraceEnd = GetReachLineEnd();
	if (!MyPhysicsHandle) { return; }; //if pointer is null stop here
	if (MyPhysicsHandle->GrabbedComponent) {//if physics handle is attached move the object we're holding
		MyPhysicsHandle->SetTargetLocation(LineTraceEnd);
	}
}

const FHitResult UGrabber::GetFirstPhysicsBodyInReach() {

	DrawDebugLine(
		GetWorld(),
		PlayerViewPointLocation,
		LineTraceEnd,
		FColor(255, 0, 0),// RGB
		false, //redraw it every frame
		0.f, //lifetime does not matter bc is redrawn every frame
		0.f,
		10.f
	);
	FHitResult Hit; //making the linetrace aka ray-cast
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());//false is for: use TraceComplex(uses the playerCollision not the visibleCollision), ignore yourself
	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		PlayerViewPointLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),//physics body are the movable objects we set as such in the details panel
		TraceParameters
	);

	AActor* ActorHit = Hit.GetActor(); //get the hit actor and put him in this variable
	if (ActorHit) {
		//UE_LOG(LogTemp, Warning, TEXT("The actor: %s"), *ActorHit->GetName()); //see what you hit
	}
	return Hit;
}


