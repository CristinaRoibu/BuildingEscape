// Copyright Cristina Roibu 2017

#pragma once

#include "Engine/TextRenderActor.h"
#include "Message.generated.h"

/**
 * 
 */
UCLASS()
class BUILDINGESCAPE_API AMessage : public ATextRenderActor
{
	GENERATED_BODY()
		virtual void BeginPlay() override;
		void DisplayText();
	    
	    FString Message1 = ("Press Y");
public:
		UFUNCTION(BlueprintCallable, Category = "Text Input")
		void PressedY();
	
};
