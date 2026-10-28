
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ScrollBox.h"
#include "Components/EditableTextBox.h"
#include "Components/MultiLineEditableTextBox.h"
#include "ChatUI.generated.h"


UCLASS()
class CX_API UChatUI : public UUserWidget
{
	GENERATED_BODY()

public:
	void OnNewChatMessage(const FString& Sender, const FString& Message);


protected:

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	UFUNCTION()
	void OnChatInputTextCommitted(const FText& Text, ETextCommit::Type CommitMethod);

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UEditableTextBox> EditableTextChatInput;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UScrollBox> EditableTextChatScroll;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UMultiLineEditableTextBox> MultilineEditableTextChatLog;
};
