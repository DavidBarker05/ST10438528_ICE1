#include "Pickup/Pickup.h"
#include "Components/SphereComponent.h"
#include "CustomCharacter/CustomCharacter.h"
#include "Pickup/PickupSpawner.h"

APickup::APickup() {
	TriggerCollider = CreateDefaultSubobject<USphereComponent>(TEXT("TriggerCollider"));
	RootComponent = TriggerCollider;
	TriggerCollider->SetCollisionProfileName(TEXT("OverlapOnlyPawn"));
	TriggerCollider->SetGenerateOverlapEvents(true);
	TriggerCollider->OnComponentBeginOverlap.AddDynamic(this, &APickup::OnComponentBeginOverlap);
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	PickupMesh->SetupAttachment(RootComponent);
}

void APickup::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if (ACustomCharacter* CustomCharacter = Cast<ACustomCharacter>(OtherActor)) {
		const float Duration = 5.0f;
		CustomCharacter->ApplySpeedBoost(2.0f, Duration);
		if (PickupSpawner) PickupSpawner->RespawnPickup(Duration);
	}
}

