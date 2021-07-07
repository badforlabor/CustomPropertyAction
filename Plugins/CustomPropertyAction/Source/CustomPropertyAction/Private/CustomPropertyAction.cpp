
#include "CustomPropertyAction.h"

FCustomPropertyActionTest::FCustomPropertyActionTest()
{
	ActionList.OnNotify = FCustomPropertyAction::FOnClick::CreateRaw(this, &FCustomPropertyActionTest::OnClick);
	ActionList.ActionList.Add(TEXT("Action1"));
	ActionList.ActionList.Add(TEXT("Action2"));
}

void FCustomPropertyActionTest::OnClick(const FString& Action)
{
    
}