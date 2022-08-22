#pragma once
#include "CoreMinimal.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Actor.h"
#include "Character_1.h"
#include "Character_2.h"
#include "MyActor.generated.h"
UCLASS()
class UNTITLED_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		USpringArmComponent* spring_arm;
	UPROPERTY(EditAnywhere)
		UCameraComponent* Cam;
	UPROPERTY(EditAnywhere)
		ACharacter_1* Ch1;
	UPROPERTY(EditAnywhere)
		ACharacter_2* Ch2;
	FVector Mid_point_location;
	int Spring_constant = 1;

};
