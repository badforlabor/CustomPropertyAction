// Copyright Epic Games, Inc. All Rights Reserved.

#include "CustomPropertyActionEditor.h"
#include "CustomPropertyActionCustom.h"

#define LOCTEXT_NAMESPACE "FCustomPropertyActionEditorModule"

void FCustomPropertyActionEditorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
		FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	// 类名和属性名去掉前缀U或F
	PropertyModule.RegisterCustomPropertyTypeLayout(FName("CustomPropertyAction"),
		FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FCustomPropertyActionCustomization::MakeInstance));
}

void FCustomPropertyActionEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	PropertyModule.UnregisterCustomPropertyTypeLayout("CustomPropertyAction");
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCustomPropertyActionEditorModule, CustomPropertyActionEditor)