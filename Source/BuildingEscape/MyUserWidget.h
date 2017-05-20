// Copyright Cristina Roibu 2017

#pragma once

#include "Blueprint/UserWidget.h"
#include "MyUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class BUILDINGESCAPE_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Riddle")
	FString Username;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Riddle")
	FString Password;
	
	
};
