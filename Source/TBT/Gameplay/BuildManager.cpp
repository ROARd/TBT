// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildManager.h"

#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"


ABuildManager::ABuildManager()
{
	USceneComponent* sceneComp = CreateDefaultSubobject<USceneComponent>(FName("DefaultSceneRoot"));
	SetRootComponent(sceneComp);
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMesh->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);

	PrimaryActorTick.bCanEverTick = true;
}

void ABuildManager::BeginPlay()
{
	Super::BeginPlay();
	this->SetActorTickEnabled(false);
	
	ATycoonPlayerController* controller = Cast<ATycoonPlayerController>(GEngine->GetFirstLocalPlayerController(GetWorld()));
	if(IsValid(controller))
	{
		Controller = controller;
		Controller->BuildModeChangedEvent.AddDynamic(this, &ABuildManager::SwitchBuildMode);
		
		PlayerState = Controller->GetPlayerState<ATycoonPlayerState>();
	}

	ensure(HouseData);
}

void ABuildManager::BuildHouse()
{
	if(bCanBuild)
	{
		AActor* newActor = GetWorld()->SpawnActor(HouseData->HouseStruct.HouseActor, &this->GetTransform());
		PlayerState->ConsumeResource(HouseData->HouseStruct.Price);
		BuildingAdded.Broadcast(newActor);
	}
}

void ABuildManager::SwitchBuildMode()
{
	if(bIsInBuildMode)
	{
		Controller->ActionRequestedEvent.RemoveDynamic(this, &ABuildManager::BuildHouse);
		StaticMesh->SetStaticMesh(nullptr);
	}
	else
	{
		Controller->ActionRequestedEvent.AddDynamic(this, &ABuildManager::BuildHouse);
		StaticMesh->SetStaticMesh(HouseData->HouseStruct.Mesh);
	}

	bIsInBuildMode = !bIsInBuildMode;
	this->SetActorTickEnabled(bIsInBuildMode);
}

bool ABuildManager::CalcCanBuild() const
{
	TArray<AActor*> overlappingActors;
	StaticMesh->GetOverlappingActors(overlappingActors);

	return overlappingActors.Num() == 0 && PlayerState->EnoughResource(HouseData->HouseStruct.Price);
}

void ABuildManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Controller->DeprojectMousePositionToWorld(WorldLocation, WorldDirection);
	const FVector newTraceEnd = WorldDirection * 100000 + WorldLocation;

	if(newTraceEnd != TraceEnd)
	{
		TraceEnd = newTraceEnd;
		
		GetWorld()->LineTraceSingleByChannel(HitResult, WorldLocation, TraceEnd, ECC_GameTraceChannel1, CollisionQueryParams);
		this->SetActorLocation(HitResult.ImpactPoint);
		this->SetActorHiddenInGame(!HitResult.bBlockingHit);

		bCanBuild = this->CalcCanBuild();
		StaticMesh->SetMaterial(0, bCanBuild ? nullptr : ConstructionRestrictedMat);
	}
}

