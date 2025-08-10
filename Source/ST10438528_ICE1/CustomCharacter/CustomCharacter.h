#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CustomCharacter.generated.h"

UCLASS(Abstract)
class ST10438528_ICE1_API ACustomCharacter : public ACharacter {
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* PlayerCamera;

	float NormalSpeed;

	FTimerHandle SpeedBoostTimerHandle;

	protected:
		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		class UInputAction* JumpAction;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		class UInputAction* MoveAction;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		class UInputAction* MouseLookAction;

	public:
		ACustomCharacter();

	public:	
		virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	protected:
		void Move(const struct FInputActionValue& Value);

		void Look(const struct FInputActionValue& Value);

	public:
		UFUNCTION(BlueprintCallable, Category = "Input")
		virtual void DoMove(float InputX, float InputY);

		UFUNCTION(BlueprintCallable, Category = "Input")
		virtual void DoLook(float Yaw, float Pitch);

		UFUNCTION(BlueprintCallable, Category = "Input")
		virtual void DoJumpStart();

		UFUNCTION(BlueprintCallable, Category = "Input")
		virtual void DoJumpEnd();

	public:
		void ApplySpeedBoost(float SpeedMultiplier, float Duration);

		void ResetSpeed();
};
