#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputMappingContext.h"
#include "CustomPlayerController.generated.h"

UCLASS(Abstract)
class ST10438528_ICE1_API ACustomPlayerController : public APlayerController {
	GENERATED_BODY()
	
	protected:
		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
		TArray<UInputMappingContext*> DefaultMappingContexts;

		virtual void SetupInputComponent() override;
};
