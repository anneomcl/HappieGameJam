// Fill out your copyright notice in the Description page of Project Settings.

#include "GameJam.h"
#include "HappieCharacter.h"


// Sets default values
AHappieCharacter::AHappieCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Don't rotate when the controller rotates.
	{
		bUseControllerRotationPitch = false;
		bUseControllerRotationYaw = false;
		bUseControllerRotationRoll = false;
	}
	// Setup Camera
	{
		// Initialize and Configure Spring Arm
		SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
		SpringArm->SetupAttachment(RootComponent);
		SpringArm->bAbsoluteRotation = true; // Rotation of the character should not affect rotation of boom
		SpringArm->bDoCollisionTest = false;
		SpringArm->RelativeRotation = FRotator(-45.f, 0.f, 0.f);
		SpringArm->TargetArmLength = 400.0f;
		SpringArm->bEnableCameraLag = true;
		SpringArm->CameraLagSpeed = 3.0f;
		// Initialize Camera and attach it to the Spring Arm
		Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
		Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
		Camera->bUsePawnControlRotation = false; // We don't want the controller rotating the camera
	}
	// Configure character movement
	{
		GetCharacterMovement()->bOrientRotationToMovement = false;
		GetCharacterMovement()->AirControl = 1.0f;
		GetCharacterMovement()->JumpZVelocity = 900.0f;
		
	}
	// Health System
	{
		MaxHealth = 100.0f;
		Health = MaxHealth;
	}
	
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void AHappieCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHappieCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHappieCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAxis("HorizontalMovement", this, &AHappieCharacter::MoveHorizontally);
}

void AHappieCharacter::MoveHorizontally(float AxisValue)
{
	AddMovementInput(FVector(0.f, 1.f, 0.f), AxisValue);
}

