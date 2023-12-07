// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncNodeAction.generated.h"

class AMasterActor;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTargetBooleanValueChanged, const bool, NewValue);

UCLASS()
class UEENTHUSIAST_API UAsyncNodeAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	virtual void Activate() override;

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject", DefaultToSelf = "ListenerActor"), DisplayName= "Wait for Boolean Change")
	static UAsyncNodeAction* WaitForBooleanChange(
		UObject* WorldContextObject,
		AActor* ListenerActor,
		AMasterActor* TargetActor
		);
	
	UPROPERTY(BlueprintAssignable)
	FOnTargetBooleanValueChanged OnValueChange;

	UPROPERTY()
	AActor* ListenerActor;
	
	UPROPERTY()
	AMasterActor* TargetActor;

	UFUNCTION()
	void OnBooleanValueChanged(bool NewValue);
};
