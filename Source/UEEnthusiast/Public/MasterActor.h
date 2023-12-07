#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Delegates/Delegate.h"

#include "MasterActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBooleanValueChanged, const bool, NewValue);

UCLASS()
class UEENTHUSIAST_API AMasterActor : public AActor
{
    GENERATED_BODY()

public:
    FBooleanValueChanged OnBooleanValueChanged;

    AMasterActor();

    UFUNCTION(Server, Reliable)
    void SetBooleanValue(const bool BooleanValue);

    UFUNCTION()
    void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    void GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const override;
private:
    UPROPERTY(Replicated)
    bool bBooleanValue = false;

    UPROPERTY(VisibleAnywhere, Category = "Trigger Capsule")
    class UCapsuleComponent* TriggerCapsule;
};