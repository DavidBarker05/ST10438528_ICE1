#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickupSpawner.generated.h"

UCLASS()
class ST10438528_ICE1_API APickupSpawner : public AActor {
	GENERATED_BODY()
	
	FTimerHandle RespawnHandle;

	public:
		APickupSpawner();

	protected:
		virtual void BeginPlay() override;

	protected:
		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
		TSubclassOf<AActor> PickupBlueprint;

	protected:
		UFUNCTION()
		void SpawnPickup();

	public:
		UFUNCTION(BlueprintCallable, Category = "Spawning")
		void RespawnPickup(const float Delay);
};
