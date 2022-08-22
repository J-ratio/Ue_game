// Fill out your copyright notice in the Description page of Project Settings.


#include "Character_1.h"

// Sets default values
ACharacter_1::ACharacter_1()
{

	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	VisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisibleComponent"));
	VisibleComponent -> SetupAttachment(RootComponent);
 	

}

// Called when the game starts or when spawned
void ACharacter_1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacter_1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!MovementDirection.IsZero()) {
		const FVector NewLocation = GetActorLocation() + (MovementDirection * DeltaTime * MovementSpeed);
		SetActorLocation(NewLocation);
	}

	Ch1_location = GetActorLocation();

}

// Called to bind functionality to input
void ACharacter_1::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis(TEXT("W/S"), this, &ACharacter_1::MoveForward);
	InputComponent->BindAxis(TEXT("A/D"), this, &ACharacter_1::MoveRight);

}

void ACharacter_1::MoveForward(float Value)
{
	MovementDirection.X = FMath::Clamp(Value, -1.0f, 1.0f);
}

void ACharacter_1::MoveRight(float Value)
{
	MovementDirection.Y = FMath::Clamp(Value, -1.0f, 1.0f);
}

