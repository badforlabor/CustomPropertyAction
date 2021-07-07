// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CustomPropertyActionEditor : ModuleRules
{
	public CustomPropertyActionEditor(ReadOnlyTargetRules Target) : base(Target)
	{
        if (Target.Configuration != UnrealTargetConfiguration.Shipping)
        {
            OptimizeCode = CodeOptimization.Never;
        }
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"CustomPropertyAction",
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);

			
        if (Target.bBuildEditor == true)
        {
            PrivateDependencyModuleNames.AddRange(new string[]
            {
                "UnrealEd",
                "GraphEditor",
            });
        }
        PrivateIncludePathModuleNames.AddRange(
            new string[] {
            }
        );
        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "InputCore",
            "SlateCore",
            "UnrealEd",
            "GraphEditor",
            "PropertyEditor",
        });
	}
}
