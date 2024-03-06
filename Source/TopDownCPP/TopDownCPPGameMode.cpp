// Copyright Epic Games, Inc. All Rights Reserved.

#include "TopDownCPPGameMode.h"
#include "TopDownCPPPlayerController.h"
#include "TopDownCPPCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATopDownCPPGameMode::ATopDownCPPGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ATopDownCPPPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_PlayerAvatar"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
		
	}
}