// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAvatarAnimInstance.h"
#include "PlayerAvatar.h"

void UPlayerAvatarAnimInstance::OnStateAnimationEnds()
{
	if (State == EPlayerState::Attack) 
	{
		State = EPlayerState::Locomotion;
	}
	else
	{
		auto ownerActor = this->GetOwningActor();
		auto PlayerAvatar = Cast<APlayerAvatar>(ownerActor);
		
		if (PlayerAvatar == nullptr)
		{
			return;
		}
		if (State == EPlayerState::Hit)
		{
			if (PlayerAvatar->GetHealthPoints() > 0.0f)
			{
				State = EPlayerState::Locomotion;
			}
			else
			{
				State = EPlayerState::Die;
			}
		}
		else if (State == EPlayerState::Die) 
		{
			//Call die process 
			PlayerAvatar->IsKilled();
		}
	}
}
