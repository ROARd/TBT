// Fill out your copyright notice in the Description page of Project Settings.


#include "TycoonPlayerState.h"


ATycoonPlayerState::ATycoonPlayerState()
{
}

void ATycoonPlayerState::ConsumeResource(const int Amount)
{
	if(EnoughResource(Amount))
	{
		Resource -= Amount;
	}
}

void ATycoonPlayerState::AddResource(const int Amount)
{
	Resource += Amount;
}

int ATycoonPlayerState::EnoughResource(const int Amount) const
{
	return Resource >= Amount;
}
