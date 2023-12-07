// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncNodeAction.h"
#include "MasterActor.h"

void UAsyncNodeAction::Activate()
{
	Super::Activate();

	if(ListenerActor && TargetActor)
	{
		TargetActor->OnBooleanValueChanged.AddDynamic(this, &UAsyncNodeAction::OnBooleanValueChanged);
	}
}

UAsyncNodeAction* UAsyncNodeAction::WaitForBooleanChange(
	UObject* WorldContextObject,
	AActor* ListenerActor,
	AMasterActor* TargetActor)
{
	UAsyncNodeAction* Action = NewObject<UAsyncNodeAction>();
	Action->ListenerActor = ListenerActor;
	Action->TargetActor = TargetActor;
	Action->RegisterWithGameInstance(WorldContextObject);

	return Action;
}

void UAsyncNodeAction::OnBooleanValueChanged(const bool NewValue)
{
	OnValueChange.Broadcast(NewValue);
}
