
#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "CustomPropertyAction.generated.h"

USTRUCT()
struct CUSTOMPROPERTYACTION_API FCustomPropertyAction
{
	GENERATED_BODY();

	/** Bone to attach the sphere to */
	UPROPERTY(EditAnywhere, Category = CollisionLimitBase)
		TArray<FString> ActionList;

	DECLARE_DELEGATE_OneParam(FOnClick, const FString& Action)
	FOnClick OnNotify;
};

USTRUCT()
struct CUSTOMPROPERTYACTION_API FCustomPropertyActionTest
{
	GENERATED_USTRUCT_BODY()

    FCustomPropertyActionTest();

	UPROPERTY(EditAnywhere)
		FCustomPropertyAction ActionList;

	void OnClick(const FString& Action);
};
