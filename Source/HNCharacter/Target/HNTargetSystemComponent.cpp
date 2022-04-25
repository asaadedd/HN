#include "HNTargetSystemComponent.h"

#include "HNCharacter/Character/HNCharacter.h"
#include "Kismet/GameplayStatics.h"

void UHNTargetSystemComponent::SetupTargetingInputs(UInputComponent* PlayerInputComponent, FActorOnClickedSignature OnClicked)
{
	PlayerInputComponent->BindAction("Target Player", IE_Pressed, this, &UHNTargetSystemComponent::FindTarget);
	OnClicked.AddDynamic(this, &UHNTargetSystemComponent::ActorClicked);
}

void UHNTargetSystemComponent::SetTarget(AActor* Actor)
{
	TargetActor = Actor;
}

void UHNTargetSystemComponent::FindTarget()
{
	TArray<TEnumAsByte<EObjectTypeQuery>> StrArr;
	TArray<AActor*> ActorsToIgnore;
	TArray<AActor*> FoundActors;

	// ActorsToIgnore.Add(Source);
	// const bool IsAnyActorFound = UKismetSystemLibrary::SphereOverlapActors(GetWorld(), Source->GetActorLocation(), Range, StrArr, Target->GetClass(), ActorsToIgnore, FoundActors);
	// if (!IsAnyActorFound)
	// {
	// 	return false;
	// }
	//
	//
	// for (const AActor* FoundActor : FoundActors) {
	// 	if (FoundActor == Target)
	// 	{
	// 		return true;
	// 	}
	// }
	//
	// return false;
}

void UHNTargetSystemComponent::ActorClicked(AActor* TouchedActor, FKey ButtonPressed)
{
	ACharacter* Character = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (!Character)
	{
		return;
	}

	AHNCharacter* HNCharacter = Cast<AHNCharacter>(Character);

	if (!HNCharacter)
	{
		return;
	}

	HNCharacter->GetTargetSystemComponent()->SetTarget(TouchedActor);	
}
