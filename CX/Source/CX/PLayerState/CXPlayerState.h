// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "CXPlayerState.generated.h"

/**
 *
 */
UCLASS()
class CX_API ACXPlayerState : public APlayerState
{
	GENERATED_BODY()

public:

	UFUNCTION(Server, Reliable)
	void CTSAddBonusMaxSpeed(const float Value);

	UFUNCTION(Server, Reliable)
	void CTSAddCoins(const int32 Value);

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	int32 GetCoins() const { return Coins; }
	float GetBonusMaxSpeed() const { return BonusMaxSpeed; }

	void AddCoins(int32 Value);
	void AddBonusMaxSpeed(float Value);

	bool RemoveCoins(int32 Value);
	bool RemoveBonusMaxSpeed(float Value);

	UFUNCTION(BlueprintCallable)
	FString GetPlayerStateInfo() const;

public:
	UPROPERTY(Replicated)
	int32 Coins = 0;

	UPROPERTY(Replicated)
	float BonusMaxSpeed = 0.1;
};
