#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "HNAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
		GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class UHNAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UHNAttributeSet();
	
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	UPROPERTY(BlueprintReadOnly, Category = "Static", ReplicatedUsing=OnRep_Health)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UHNAttributeSet, Health)
	
	UPROPERTY(BlueprintReadOnly, Category = "Static", ReplicatedUsing=OnRep_Flux)
	FGameplayAttributeData Flux;
	ATTRIBUTE_ACCESSORS(UHNAttributeSet, Flux)
	
	UPROPERTY(BlueprintReadOnly, Category = "Static", ReplicatedUsing=OnRep_Energy)
	FGameplayAttributeData Energy;
	ATTRIBUTE_ACCESSORS(UHNAttributeSet, Energy)
	
	UPROPERTY(BlueprintReadOnly, Category = "General", ReplicatedUsing=OnRep_Speed)
	FGameplayAttributeData Speed;
	ATTRIBUTE_ACCESSORS(UHNAttributeSet, Speed)
	
	UPROPERTY(BlueprintReadOnly, Category = "General", ReplicatedUsing=OnRep_Regen)
	FGameplayAttributeData Regen;
	ATTRIBUTE_ACCESSORS(UHNAttributeSet, Regen)
	
	UPROPERTY(BlueprintReadOnly, Category = "Defence", ReplicatedUsing=OnRep_Discharge)
	FGameplayAttributeData Discharge;
	ATTRIBUTE_ACCESSORS(UHNAttributeSet, Discharge)
	
	UPROPERTY(BlueprintReadOnly, Category = "Defence", ReplicatedUsing=OnRep_Agility)
	FGameplayAttributeData Agility;
	ATTRIBUTE_ACCESSORS(UHNAttributeSet, Agility)
	
	UPROPERTY(BlueprintReadOnly, Category = "Offence", ReplicatedUsing=OnRep_Charge)
	FGameplayAttributeData Charge;
	ATTRIBUTE_ACCESSORS(UHNAttributeSet, Charge)
	
	UPROPERTY(BlueprintReadOnly, Category = "Defence", ReplicatedUsing=OnRep_Precision)
	FGameplayAttributeData Precision;
	ATTRIBUTE_ACCESSORS(UHNAttributeSet, Precision)

protected:
	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& OldValue);
	
	UFUNCTION()
	virtual void OnRep_Flux(const FGameplayAttributeData& OldValue);
	
	UFUNCTION()
	virtual void OnRep_Energy(const FGameplayAttributeData& OldValue);
	
	UFUNCTION()
	virtual void OnRep_Speed(const FGameplayAttributeData& OldValue);
	
	UFUNCTION()
	virtual void OnRep_Regen(const FGameplayAttributeData& OldValue);
	
	UFUNCTION()
	virtual void OnRep_Discharge(const FGameplayAttributeData& OldValue);
	
	UFUNCTION()
	virtual void OnRep_Agility(const FGameplayAttributeData& OldValue);
	
	UFUNCTION()
	virtual void OnRep_Charge(const FGameplayAttributeData& OldValue);
	
	UFUNCTION()
	virtual void OnRep_Precision(const FGameplayAttributeData& OldValue);
};