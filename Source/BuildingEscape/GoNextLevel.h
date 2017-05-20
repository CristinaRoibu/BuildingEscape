// Copyright Cristina Roibu 2017

#pragma once

#include "Engine/TriggerBox.h"
#include "GoNextLevel.generated.h"

/**
 * 
 */
UCLASS()
class BUILDINGESCAPE_API AGoNextLevel : public ATriggerBox
{
	GENERATED_BODY()
	
	
public:
	virtual void BeginPlay() override;

	UFUNCTION()
	void CallNextLevel(AActor* Actor1, AActor* Actor2);
};
