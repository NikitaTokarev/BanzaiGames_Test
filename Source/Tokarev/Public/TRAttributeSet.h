// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "TRAttributeSet.generated.h"


#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


UCLASS()
class TOKAREV_API UTRAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UTRAttributeSet();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
	FGameplayAttributeData AbilityValue;
	ATTRIBUTE_ACCESSORS(UTRAttributeSet, AbilityValue);

	void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;
};
