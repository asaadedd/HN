#pragma once
#include "Abilities/GameplayAbility.h"
#include "HNGameplayAbility.generated.h"

UCLASS()
class UHNGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Animation")
	UAnimMontage* Montage;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Constrains")
	float Range;

	bool IsTargetPositionValid(const AActor* Target) const;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTargetHitDelegate, FGameplayEventData, Payload);
	UPROPERTY()
	FTargetHitDelegate TargetHit;

private:
	bool IsActorInFieldOfView(const AActor* Target) const;
};
