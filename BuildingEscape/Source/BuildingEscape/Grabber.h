// Copyright Joshua Mathews 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/InputComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	// How far can the player reach to grab something?
	float Reach = 100.f;
	
	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	UInputComponent* InputComponent = nullptr;

	// Find attached physics
	void FindPhysicsHandleComponent();

	// Setup (assemed) attached input component
	void SetupInputComponent();

	// Ray-cast and grab what is in reach
	void Grab();

	// Call when grab is released
	void Release();

	// Returns current start of reach line
	FVector GetReachLineStart();
	
	// Returns current end of reach line
	FVector GetReachLineEnd();

	// Return hit for first physics body in reach
	const FHitResult GetFirstPhysicsBodyInReach();
};
