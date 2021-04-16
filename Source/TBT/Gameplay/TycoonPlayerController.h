// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TycoonPlayerController.generated.h"

UCLASS()
class TBT_API ATycoonPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATycoonPlayerController();

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTycoonControllerEvent);

	UPROPERTY(BlueprintAssignable)
	FTycoonControllerEvent BuildModeChangedEvent;

	UPROPERTY(BlueprintAssignable)
	FTycoonControllerEvent ActionRequestedEvent;

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	void ActionRequested();
	void BuildModeChanged();

public:
	
	virtual void Tick(float DeltaTime) override;

	
};
