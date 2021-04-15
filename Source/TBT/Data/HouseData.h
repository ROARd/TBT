// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


#include "FHouseSpawnStruct.h"
#include "HouseData.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class TBT_API UHouseData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FHouseSpawnStruct HouseStruct;
};
