#include "HNGameplayAbility.h"
#include "Kismet/GameplayStatics.h"

void UHNGameplayAbility::PlayAnimation()
{
}

bool UHNGameplayAbility::IsTargetPositionValid(const AActor* Target) const
{
	const APawn* Pawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	return Pawn->GetDistanceTo(Target) <= Range && IsActorInFieldOfView(Target);
}

bool UHNGameplayAbility::IsActorInFieldOfView(const AActor* Target) const
{
	const APlayerController* Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	const APawn* Pawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	return Controller->LineOfSightTo(Target, Pawn->GetActorLocation());
}
