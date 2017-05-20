// Copyright Cristina Roibu 2017

#include "BuildingEscape.h"
#include "Message.h"



void AMessage::BeginPlay() {
	Super::BeginPlay();
	DisplayText();
}
void AMessage::DisplayText() {
	GetTextRender()->SetText(Message1);
	GetTextRender()->TextRenderColor = FColor::Black;
}

void AMessage::PressedY() { //the text renderer is a blueprint class and it detects the player input
	UE_LOG(LogTemp, Error, TEXT("PRESED: Y !!!!!!!!!!!!!!!!!!!!!!!!!!"));
	Message1 = "These violent delights have violent ends";
	GetTextRender()->SetText(Message1);
}