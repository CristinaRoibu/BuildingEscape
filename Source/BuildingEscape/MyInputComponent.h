// Copyright Cristina Roibu 2017

#pragma once

#include "Components/InputComponent.h"
#include "MyInputComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BUILDINGESCAPE_API UMyInputComponent : public UInputComponent
{
	GENERATED_BODY()
	
public:
	UMyInputComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void BeginPlay() override;

	void WordsControl();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Riddle")
	class UMyUserWidget* RiddlesWidget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pass the wall")
	AActor* TheLiftingWall;// this variable is setted in the TriggerBoxRiddleBlueprint, through the controlled pawn we can risalire alla this class and set this variable
	void MoveWallUp();

private:
	bool CorrectUsername = false; //if both of them are true then the player guessed the username and password
	bool CorrectPassword = false;//now the method that will lift the wall will be called
	FHitResult OutSweepHitResult;
};
