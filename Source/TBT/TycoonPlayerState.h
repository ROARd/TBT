// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"

#include "TycoonPlayerState.generated.h"

UCLASS()
class TBT_API ATycoonPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	ATycoonPlayerState();

	UFUNCTION(BlueprintCallable)
	void ConsumeResource(int Amount);

	UFUNCTION(BlueprintCallable)
	void AddResource(int Amount);

	UFUNCTION(BlueprintCallable)
	int EnoughResource(int Amount) const;
	
protected:
	UPROPERTY(BlueprintReadOnly)
	int Resource;
};
