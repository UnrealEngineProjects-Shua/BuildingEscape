// Copyright Joshua Mathews 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/PrimitiveComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/TriggerVolume.h"
#include "Engine/World.h"
#include "OpenDoor.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable)
		FDoorEvent OnClose;

	UPROPERTY(BlueprintAssignable)
		FDoorEvent OnOpen;
		
private:
	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate = nullptr;  // Pawn inherits from actor

	UPROPERTY(EditAnywhere)
		float TriggerMass = 30.f;

		AActor* Owner = nullptr;
	
		// Returns total mass in kg
		float TotalMassOnPlate();
};
