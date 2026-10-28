// Fill out your copyright notice in the Description page of Project Settings.


#include "PLayerState/CXPlayerState.h"
#include "Net/UnrealNetwork.h"

static int32 GMyTestCoin = 0;

static FAutoConsoleVariableRef CVarAddCoinsServer(
	TEXT("cheat.addcoin.server"),
	GMyTestCoin,
	TEXT("코인을 입력한 수치만큼 증가시킵니다."),
	FConsoleVariableDelegate::CreateLambda([](IConsoleVariable* CVar)
		{
			if (CVar)
			{
				UE_LOG(LogTemp, Warning, TEXT("콘솔 변수 변경됨! 현재 값: %d"), CVar->GetInt());

				UE_LOG(LogTemp, Warning, TEXT("콘솔 변수 변경됨! GMyTestCoin 값: %d"), GMyTestCoin);

				if (GWorld)
				{
					if (GWorld->GetFirstPlayerController())
					{
						GWorld->GetFirstPlayerController()->GetPlayerState<ACXPlayerState>()->CTSAddCoins(GMyTestCoin);
					}
				}
				GMyTestCoin = 0;
			}
		}),
	ECVF_Cheat
);

static FAutoConsoleVariableRef CVarAddCoinsClient(
	TEXT("cheat.addcoin.client"),
	GMyTestCoin,
	TEXT("코인을 입력한 수치만큼 증가시킵니다."),
	FConsoleVariableDelegate::CreateLambda([](IConsoleVariable* CVar)
		{
			if (CVar)
			{
				UE_LOG(LogTemp, Warning, TEXT("콘솔 변수 변경됨! 현재 값: %d"), CVar->GetInt());

				UE_LOG(LogTemp, Warning, TEXT("콘솔 변수 변경됨! GMyTestCoin 값: %d"), GMyTestCoin);

				if (GWorld)
				{
					if (GWorld->GetFirstPlayerController())
					{
						GWorld->GetFirstPlayerController()->GetPlayerState<ACXPlayerState>()->AddCoins(GMyTestCoin);
					}
				}
				GMyTestCoin = 0;
			}
		}),
	ECVF_Cheat
);


void ACXPlayerState::CTSAddBonusMaxSpeed_Implementation(const float Value)
{
	AddBonusMaxSpeed(Value);
}

void ACXPlayerState::CTSAddCoins_Implementation(const int32 Value)
{
	AddCoins(Value);
}

void ACXPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(ThisClass, Coins, COND_OwnerOnly);
	DOREPLIFETIME_CONDITION(ThisClass, BonusMaxSpeed, COND_OwnerOnly);

}

void ACXPlayerState::AddCoins(int32 Value)
{
	if (HasAuthority() == true &&
		Value > 0)
	{
		FString PlayerName = GetPlayerName();
		Coins = Coins + Value;
		UE_LOG(LogTemp, Warning, TEXT("%s - AddCoin: %d(+%d)"), *PlayerName, Coins, Value);
	}
}

void ACXPlayerState::AddBonusMaxSpeed(float Value)
{
	if (HasAuthority() == true &&
		Value > 0)
	{
		BonusMaxSpeed = BonusMaxSpeed + Value;
	}
}

bool ACXPlayerState::RemoveCoins(int32 Value)
{
	if (HasAuthority() == true &&
		Value > 0 &&
		Coins > 5)
	{
		Coins < Value ?
			Coins = 0 :
			Coins = Coins - Value;
		return true;
	}
	return false;
}
bool ACXPlayerState::RemoveBonusMaxSpeed(float Value)
{
	if (HasAuthority() == true &&
		Value > 0.f)
	{
		BonusMaxSpeed < Value ?
			BonusMaxSpeed = 0 :
			BonusMaxSpeed = BonusMaxSpeed - Value;

		return true;
	}
	return false;
}

FString ACXPlayerState::GetPlayerStateInfo() const
{
	return FString::Printf(TEXT("Coins: %d, BonusMaxSpeed: %.2f"), Coins, BonusMaxSpeed);
}
