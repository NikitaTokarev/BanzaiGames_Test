// Fill out your copyright notice in the Description page of Project Settings.


#include "TRAttributeSet.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"

UTRAttributeSet::UTRAttributeSet()
{

}


void UTRAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetAbilityValueAttribute())
	{
		SetAbilityValue(GetAbilityValue());
	}
}
