#pragma once
#include "Components/ActorComponent.h"
#include "HNTargetSystemComponent.generated.h"

UCLASS()
class UHNTargetSystemComponent: public UActorComponent
{
	GENERATED_BODY()
public:
	void SetupTargetingInputs(class UInputComponent* PlayerInputComponent, FActorOnClickedSignature OnClicked);
	void SetTarget(AActor* Actor);

private:
	UPROPERTY()
	AActor* TargetActor;
	
	void FindTarget();
	void ActorClicked(AActor* TouchedActor, FKey ButtonPressed);
};
