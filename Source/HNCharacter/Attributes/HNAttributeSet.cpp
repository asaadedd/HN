#include "HNAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

UHNAttributeSet::UHNAttributeSet()
{
	Health = 1000;
	Flux = 100;
	Energy = 100;
	Speed = 10;
	Regen = 10;
	Discharge = 10;
	Agility = 10;
	Charge = 10;
	Precision = 10;
}

void UHNAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

void UHNAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UHNAttributeSet, Health);
	DOREPLIFETIME(UHNAttributeSet, Flux);
	DOREPLIFETIME(UHNAttributeSet, Energy);
	DOREPLIFETIME(UHNAttributeSet, Speed);
	DOREPLIFETIME(UHNAttributeSet, Regen);
	DOREPLIFETIME(UHNAttributeSet, Discharge);
	DOREPLIFETIME(UHNAttributeSet, Agility);
	DOREPLIFETIME(UHNAttributeSet, Charge);
	DOREPLIFETIME(UHNAttributeSet, Precision);
}

void UHNAttributeSet::OnRep_Health(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHNAttributeSet, Health, OldValue);
}

void UHNAttributeSet::OnRep_Flux(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHNAttributeSet, Flux, OldValue);
}

void UHNAttributeSet::OnRep_Energy(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHNAttributeSet, Energy, OldValue);
}

void UHNAttributeSet::OnRep_Speed(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHNAttributeSet, Speed, OldValue);
}

void UHNAttributeSet::OnRep_Regen(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHNAttributeSet, Regen, OldValue);
}

void UHNAttributeSet::OnRep_Discharge(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHNAttributeSet, Discharge, OldValue);
}

void UHNAttributeSet::OnRep_Agility(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHNAttributeSet, Agility, OldValue);
}

void UHNAttributeSet::OnRep_Charge(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHNAttributeSet, Charge, OldValue);
}

void UHNAttributeSet::OnRep_Precision(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHNAttributeSet, Precision, OldValue);
}