
#include "UI/ChatUI.h"
#include "Components/Widget.h"
#include "CXPlayerController.h"

void UChatUI::NativeConstruct()
{
	Super::NativeConstruct();

	if (EditableTextChatInput->OnTextCommitted.IsAlreadyBound(this, &UChatUI::OnChatInputTextCommitted) == false)
	{
		EditableTextChatInput->OnTextCommitted.AddDynamic(this, &UChatUI::OnChatInputTextCommitted);
	}
}

void UChatUI::NativeDestruct()
{
	if (EditableTextChatInput->OnTextCommitted.IsAlreadyBound(this, &UChatUI::OnChatInputTextCommitted) == true)
	{
		EditableTextChatInput->OnTextCommitted.RemoveDynamic(this, &UChatUI::OnChatInputTextCommitted);
	}
	Super::NativeDestruct();
}

void UChatUI::OnNewChatMessage(const FString& Sender, const FString& Message)
{
	FString NewMessage = Sender + TEXT(": ") + Message;

	FString OldMessage = MultilineEditableTextChatLog->GetText().ToString();
	OldMessage += '\n';

	FText Messages = FText::FromString(OldMessage + NewMessage);

	MultilineEditableTextChatLog->SetText(Messages);
}

void UChatUI::OnChatInputTextCommitted(const FText& Text, ETextCommit::Type CommitMethod)
{
	if (CommitMethod == ETextCommit::OnEnter)
	{
		if (!Text.IsEmpty())
		{
			FString ChatMessage = Text.ToString();
			EditableTextChatInput->SetText(FText::GetEmpty());
			if (ACXPlayerController* PC = GetOwningPlayer<ACXPlayerController>())
			{

				PC->CTSChatMessage(ChatMessage);

			}
		}
	}
}
