#include "MasterActor.h"

#include "Components/CapsuleComponent.h"
#include "Net/UnrealNetwork.h"

AMasterActor::AMasterActor()
{
	PrimaryActorTick.bCanEverTick = false;
	
	TriggerCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Trigger Capsule"));
	TriggerCapsule->InitCapsuleSize(55.f, 96.0f);;
	TriggerCapsule->SetCollisionProfileName(TEXT("Trigger"));
	TriggerCapsule->SetupAttachment(RootComponent);

	TriggerCapsule->OnComponentBeginOverlap.AddDynamic(this, &AMasterActor::OnOverlapBegin); 
}

void AMasterActor::SetBooleanValue_Implementation(const bool BooleanValue)
{
	bBooleanValue = BooleanValue;
    
	OnBooleanValueChanged.Broadcast(BooleanValue);
}

void AMasterActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor)
	{
		SetBooleanValue(true);
	}
}

void AMasterActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AMasterActor, bBooleanValue);
}
