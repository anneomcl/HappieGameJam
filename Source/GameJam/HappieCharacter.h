<<<<<<< HEAD
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HappieCharacter.generated.h"

UCLASS()
class GAMEJAM_API AHappieCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHappieCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Movement Functions
	void MoveHorizontally(float AxisValue);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Camera
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UCameraComponent* Camera;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) USpringArmComponent* SpringArm;

	// Health System
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float Health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float MaxHealth;
};
=======
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HappieCharacter.generated.h"

UCLASS()
class GAMEJAM_API AHappieCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHappieCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Movement Functions
	void MoveHorizontally(float AxisValue);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Camera
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UCameraComponent* Camera;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) USpringArmComponent* SpringArm;

	// Health System
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float Health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float MaxHealth;
};
>>>>>>> refs/remotes/anneomcl/master
