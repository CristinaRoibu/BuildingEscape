// Copyright Cristina Roibu 2017

#include "BuildingEscape.h"
#include "Level3Enemy.h"
#include "DefaultPawnParent.h"


// Sets default values
ALevel3Enemy::ALevel3Enemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CubeEnemy = CreateDefaultSubobject<UStaticMeshComponent>(FName("CubeEnemy"));
	RootComponent = CubeEnemy;
	EnemyCollision = CreateDefaultSubobject<UBoxComponent>(FName("CollisionEnemy"));
	EnemyCollision->AttachToComponent(CubeEnemy, FAttachmentTransformRules::KeepRelativeTransform);//attach component to the root so they move together
	EnemyCollision->OnComponentBeginOverlap.AddDynamic(this, &ALevel3Enemy::OverlappedMe);//on component overlapp is a variable of type Delegate for notification of start of overlap with a specific component
	//when you overlap the enemy collision this will call the methods you give him, in this case OverlappedMe
}

void ALevel3Enemy::BeginPlay()
{
	Super::BeginPlay();
}
void ALevel3Enemy::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	//EnemyMethod();
	EnemyPosition = GetActorLocation();
	if (!ChangeDirection) {
		AddActorWorldOffset(FVector(0.f, -15.f, 0.f), false);
	} else {
		AddActorWorldOffset(FVector(0.f, 15.f, 0.f), false);
	}
	
	if (EnemyPosition.Y <= -2035) { ChangeDirection = true; }//when the enemy is at the second location he will change direction
	else if (EnemyPosition.Y >= -913) { ChangeDirection = false; }

}

void ALevel3Enemy::EnemyMethod(){
	CubeEnemy->GetOverlappingActors(OverlappedEnemy);
	if (OverlappedEnemy.Num() == 0) { return; }
	UE_LOG(LogTemp, Warning, TEXT("donkey %s"), *OverlappedEnemy[0]->GetName());
}

void ALevel3Enemy::OverlappedMe(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if (CanDoDamage) {
		//UE_LOG(LogTemp, Warning, TEXT("donkey and a cow: %s"), *OtherActor->GetName());
		ADefaultPawnParent* ADefaultPawnParentObject = Cast<ADefaultPawnParent>(OtherActor); // to cast to ADefaultPawnParent you need to include firsty
		float ResultingLife = ADefaultPawnParentObject->CurrentLife - 3;
		ADefaultPawnParentObject->CurrentLife = FMath::Clamp<float>(ResultingLife, 0.f, ADefaultPawnParentObject->MaxLife);//clamp does not allow you to go under or above a certain numbers
		CanDoDamage = false;
		if (ResultingLife == 0) {

		}
	}
	else {
		FTimerHandle TimerBoh;
		GetWorld()->GetTimerManager().SetTimer(TimerBoh, this, &ALevel3Enemy::ResetCanDoDamage, 0.5f, false); // if you set it at true it will loop and call the method you give it every amount of time you give it
		//after the false you can input a float and it will mean that the method will be called the first time after that amount of time and the rest of times after the amount of time before the true
		//GetWorld()->GetTimerManager().ClearTimer(TimerBoh);// you can delete, pause...a timer like this, using FTimerHandle
	}
}

void ALevel3Enemy::ResetCanDoDamage() {
	CanDoDamage = true;
}