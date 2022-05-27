#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "HNGameplayAbility.generated.h"

UCLASS()
class HNABILITY_API UHNGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Animation")
	UAnimMontage* Montage;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Constrains")
	float Range;
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTargetHitDelegate, FGameplayEventData, Payload);
	UPROPERTY()
	FTargetHitDelegate TargetHit;

	void PlayAnimation();
	bool IsTargetPositionValid(const AActor* Target) const;

private:
	bool IsActorInFieldOfView(const AActor* Target) const;
};
