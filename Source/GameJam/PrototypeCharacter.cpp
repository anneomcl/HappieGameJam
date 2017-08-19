#include "GameJam.h"
#include "PrototypeCharacter.h"

APrototypeCharacter::APrototypeCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	
	// Setup Camera and attach it to the Root Component
	{
		// Use a spring arm to give the camera smooth, natural-feeling motion.
		SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraAttachmentArm"));
		SpringArm->SetupAttachment(RootComponent);
		SpringArm->RelativeRotation = FRotator(-45.f, 0.f, 0.f);
		SpringArm->TargetArmLength = 400.0f;
		SpringArm->bEnableCameraLag = true;
		SpringArm->CameraLagSpeed = 3.0f;
		// Create a camera and attach to our spring arm
		Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("ActualCamera"));
		Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	}

	Health = 100.0f;

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void APrototypeCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APrototypeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!DesiredMovement.IsZero())
	{
		SetActorLocation(GetActorLocation() + (DesiredMovement * DeltaTime));
		DesiredMovement = FVector(0, 0, 0);
	}
}

// Called to bind functionality to input
void APrototypeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("HorizontalMovement", this, &APrototypeCharacter::MoveHorizontaly);
}

void APrototypeCharacter::MoveHorizontaly(float AxisValue) 
{
	DesiredMovement.Y += FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100;
}

