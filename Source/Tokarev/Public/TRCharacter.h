// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "Abilities/GameplayAbility.h"
#include "TRCharacter.generated.h"

class UTRAttributeSet;

UCLASS()
class TOKAREV_API ATRCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATRCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Ability System")
	UAbilitySystemComponent* AbilitySystemComp;

	UFUNCTION(BlueprintCallable, Category = "Ability System")
	void InitializeAbility(TSubclassOf<UGameplayAbility> AbilityToGet, int32 AbilityLevel);

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const { return AbilitySystemComp; };

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Ability System")
	const class UTRAttributeSet* AttributeSetComp;

	UFUNCTION(BlueprintPure, Category = "Ability System")
	void GetAbilityValue(float& AbilityValue);

	void OnAbilityValueChangedNative(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintImplementableEvent, Category = "Ability System")
	void OnAbilityValueChanged(float OldValue, float NewValue);
	
};
