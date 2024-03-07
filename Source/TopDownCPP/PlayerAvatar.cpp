// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerAvatar.h"

// Sets default values
APlayerAvatar::APlayerAvatar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create the camera spring arm
	_SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	_SpringArmComponent->SetupAttachment(RootComponent);
	_SpringArmComponent->SetUsingAbsoluteRotation(true);
	_SpringArmComponent->TargetArmLength = 800.0f;
	_SpringArmComponent->SetRelativeRotation(FRotator(-60.0f, 0.0f, 0.0f));
	_SpringArmComponent->bDoCollisionTest = false;

	//Create the camera
	_CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	_CameraComponent->SetupAttachment(_SpringArmComponent, USpringArmComponent::SocketName);
	_CameraComponent->bUsePawnControlRotation = false;

	//Top Down character rotation should not be controlled by player but running direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	//Character's Movement Component
	auto characterMovement = GetCharacterMovement();
	characterMovement->bOrientRotationToMovement = true;
	characterMovement->RotationRate = FRotator(0.0f, 640.0f, 0.0f);
	characterMovement->bConstrainToPlane = true;
	characterMovement->bSnapToPlaneAtStart = true;

}

int APlayerAvatar::GetHealthPoints()
{
	return _HealthPoints;
}

bool APlayerAvatar::IsKilled()
{
	return (_HealthPoints <= 0.0f);
}

bool APlayerAvatar::CanAttack()
{
	return (_AttackCountingDown <= 0.0f);
}

// Called when the game starts or when spawned
void APlayerAvatar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerAvatar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UPlayerAvatarAnimInstance* animInst = Cast<UPlayerAvatarAnimInstance>(GetMesh()->GetAnimInstance());
	animInst->Speed = GetCharacterMovement()->Velocity.Size2D();
}

// Called to bind functionality to input
void APlayerAvatar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

