// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "TycoonPlayerController.h"
#include "TycoonPlayerState.h"
#include "GameFramework/Actor.h"
#include "TBT/Data/HouseData.h"

#include "BuildManager.generated.h"

UCLASS()
class TBT_API ABuildManager : public AActor
{
	GENERATED_BODY()

public:
	ABuildManager();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UStaticMeshComponent* StaticMesh;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UHouseData* HouseData;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UMaterial* ConstructionRestrictedMat;
	
	UPROPERTY(BlueprintReadOnly)
	ATycoonPlayerController* Controller;
	UPROPERTY(BlueprintReadOnly)
	ATycoonPlayerState* PlayerState;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBuildManagerEvent, AActor*, Actor);
	
	UPROPERTY(BlueprintAssignable)
	FBuildManagerEvent BuildingAdded;

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void SwitchBuildMode();
	UFUNCTION()
	void BuildHouse();

	UPROPERTY(BlueprintReadOnly)
	bool bIsInBuildMode;

public:
	virtual void Tick(float DeltaTime) override;

private:
	bool CalcCanBuild() const;
	
	bool bCanBuild;
	FVector WorldLocation, WorldDirection, TraceEnd;
	FCollisionQueryParams CollisionQueryParams;
	FHitResult HitResult;
};
