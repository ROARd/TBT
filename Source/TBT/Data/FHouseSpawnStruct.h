#pragma once

#include "CoreMinimal.h"
#include "FHouseStruct.generated.h"

USTRUCT(BlueprintType)
struct FHouseSpawnStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> HouseActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMesh* Mesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 Price;
};