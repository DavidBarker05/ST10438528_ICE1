#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "Components/InputComponent.h"
#include "CustomCharacter.generated.h"

UCLASS(Abstract)
class ST10438528_ICE1_API ACustomCharacter : public ACharacter {
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* PlayerCamera;

	protected:
		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		UInputAction* JumpAction;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		UInputAction* MoveAction;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		UInputAction* MouseLookAction;

	public:
		ACustomCharacter();

	public:	
		virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	protected:
		void Move(const FInputActionValue& Value);

		void Look(const FInputActionValue& Value);

	public:
		UFUNCTION(BlueprintCallable, Category = "Input")
		virtual void DoMove(float InputX, float InputY);

		UFUNCTION(BlueprintCallable, Category = "Input")
		virtual void DoLook(float Yaw, float Pitch);

		UFUNCTION(BlueprintCallable, Category = "Input")
		virtual void DoJumpStart();

		UFUNCTION(BlueprintCallable, Category = "Input")
		virtual void DoJumpEnd();
};
