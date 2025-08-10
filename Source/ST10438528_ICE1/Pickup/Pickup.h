#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

UCLASS()
class ST10438528_ICE1_API APickup : public AActor {
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Collision", meta = (AllowPrivateAccess = "true"))
	class USphereComponent* TriggerCollider;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Visual", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* PickupMesh;

	public:
		APickup();

	protected:
		UFUNCTION()
		void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
