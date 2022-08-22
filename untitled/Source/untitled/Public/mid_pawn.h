#pragma once
#include "CoreMinimal.h"
#include "Character_1.h"
#include "Character_2.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"
#include "mid_pawn.generated.h"
UCLASS()
class UNTITLED_API Amid_pawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	Amid_pawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
		USpringArmComponent* spring_arm;
	UPROPERTY(EditAnywhere)
		UCameraComponent* Cam;
	UPROPERTY(EditAnywhere)
		ACharacter_1* Ch1;
	UPROPERTY(EditAnywhere)
		ACharacter_2* Ch2;
	FVector Mid_point_location;

	UPROPERTY(EditAnywhere)
	float Spring_constant = 1.0f;

};
