// Fill out your copyright notice in the Description page of Project Settings.


#include "TycoonPlayerController.h"


ATycoonPlayerController::ATycoonPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
	bShowMouseCursor = true;
}

void ATycoonPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void ATycoonPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("BuildMode", IE_Released, this, &ATycoonPlayerController::BuildModeChanged);
	InputComponent->BindAction("DoAction", IE_Pressed, this, &ATycoonPlayerController::ActionRequested);
}


void ATycoonPlayerController::ActionRequested()
{
	ActionRequestedEvent.Broadcast();
}

void ATycoonPlayerController::BuildModeChanged()
{
	BuildModeChangedEvent.Broadcast();
}

void ATycoonPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
