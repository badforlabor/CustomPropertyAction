
#include "CustomPropertyActionCustom.h"
#include "PropertyEditing.h"
#include "Slate.h"

#define LOCTEXT_NAMESPACE "CustomPropertyActionCustomization"

TSharedRef<IPropertyTypeCustomization> FCustomPropertyActionCustomization::MakeInstance()
{
	return MakeShareable(new FCustomPropertyActionCustomization);
}

void FCustomPropertyActionCustomization::CustomizeHeader(TSharedRef<IPropertyHandle> PropertyHandle, FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& CustomizationUtils)
{
	TArray<void*> StructPtrs;
	PropertyHandle->AccessRawData(StructPtrs);
	CachedOwner = (StructPtrs.Num() == 1) ? reinterpret_cast<FCustomPropertyAction*>(StructPtrs[0]) : nullptr;
}

void FCustomPropertyActionCustomization::CustomizeChildren(TSharedRef<IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder& ChildBuilder, IPropertyTypeCustomizationUtils& StructCustomizationUtils)
{
	TSharedPtr<SVerticalBox> ChannelsWidget;
	ChildBuilder.AddCustomRow(NSLOCTEXT("CustomPropertyActionCustomization", "CustomPropertyActionCustomization", "Actions"))
		.NameContent()
		[
			StructPropertyHandle->CreatePropertyNameWidget()
		]
	.ValueContent()
		.MaxDesiredWidth(500.f)
		[
			SAssignNew(ChannelsWidget, SVerticalBox)
		];

	if (CachedOwner)
	{
		for (const auto& It : CachedOwner->ActionList)
		{
			ChannelsWidget->AddSlot()
				.AutoHeight()
				.VAlign(VAlign_Top)
				.Padding(1, 2)
				[
					SNew(SButton)
					.IsFocusable(false)
				.ContentPadding(0)
				.OnClicked(this, &FCustomPropertyActionCustomization::OnShapePropertyChanged, It)
				.Content()
				[
					SNew(STextBlock)
					.Text(FText::FromString(It))
				]
				];
		}
	}
}

FReply FCustomPropertyActionCustomization::OnShapePropertyChanged(FString Action)
{
	if (CachedOwner)
	{
		if (CachedOwner->OnNotify.IsBound())
		{
			CachedOwner->OnNotify.Execute(Action);
		}
	}
	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE