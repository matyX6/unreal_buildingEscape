// Copyright Matija Jambrešić 2017

#pragma once

#include "Components/ActorComponent.h"
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
	//How far ahead of player can we reach
	float Reach = 100.f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;

	//ray-cast and grab what is in reach
	void Grab();

	//called when grab key is released
	void Release();

	//Find attached physics handle component
	void FindPhysicsHandleComponent();

	//Look for attached input component(only appears at run time)
	void SetupInputComponent();
		
	const FHitResult GetFirstPhysicsBodyInReach();

	//Start of Reach Line
	FVector GetReachLineStart();

	//Returns current end of Reach Line
	FVector GetReachLineEnd();
};
