#pragma once

#include "CoreMinimal.h"
#include "FHouseStruct.generated.h"

USTRUCT(BlueprintType)
struct FHouseStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float BuildTime;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 ResourceMaxCapacity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float ResourceGenerateInterval;
};
