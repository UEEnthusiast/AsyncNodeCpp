// Copyright Epic Games, Inc. All Rights Reserved.

#include "UEEnthusiastGameMode.h"
#include "UEEnthusiastCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUEEnthusiastGameMode::AUEEnthusiastGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
