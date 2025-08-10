#include "Pickup/PickupSpawner.h"
#include "Pickup/Pickup.h"

APickupSpawner::APickupSpawner() { }

void APickupSpawner::BeginPlay() {
	Super::BeginPlay();
	SpawnPickup();
}

void APickupSpawner::SpawnPickup() {
	if (!PickupBlueprint) return;
	FActorSpawnParameters ActorSpawnParams;
	ActorSpawnParams.Owner = this;
	AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(PickupBlueprint, GetActorTransform());
	if (APickup* Pickup = Cast<APickup>(SpawnedActor)) Pickup->PickupSpawner = this;
}

void APickupSpawner::RespawnPickup(const float Delay) { GetWorldTimerManager().SetTimer(RespawnHandle, this, &APickupSpawner::SpawnPickup, Delay, false); }