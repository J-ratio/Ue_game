// Fill out your copyright notice in the Description page of Project Settings.


#include "mid_pawn.h"

// Sets default values
Amid_pawn::Amid_pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	//SpringArm
	spring_arm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	spring_arm->SetupAttachment(RootComponent);
	spring_arm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	spring_arm->TargetArmLength = 300.0f;

	//Cam
	Cam = CreateDefaultSubobject<UCameraComponent>(TEXT("Cam"));
	Cam->SetupAttachment(spring_arm, USpringArmComponent::SocketName);
}

// Called when the game starts or when spawned
void Amid_pawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Amid_pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Mid_point_location.X = (Ch1->Ch1_location.X + Ch2->Ch2_location.X) / 2;
	Mid_point_location.Y = (Ch1->Ch1_location.Y + Ch2->Ch2_location.Y) / 2;
	Mid_point_location.Z = (Ch1->Ch1_location.Z + Ch2->Ch2_location.Z) / 2;

	SetActorLocation(Mid_point_location);

	spring_arm->TargetArmLength = 300.0f + Spring_constant * (sqrt(((Ch1->Ch1_location.X - Ch2->Ch2_location.X) * (Ch1->Ch1_location.X - Ch2->Ch2_location.X)) + ((Ch1->Ch1_location.Y - Ch2->Ch2_location.Y) * (Ch1->Ch1_location.Y - Ch2->Ch2_location.Y))));

}

// Called to bind functionality to input
void Amid_pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

