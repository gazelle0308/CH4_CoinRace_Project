// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CX : ModuleRules
{
    public CX(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] {

            // Initial Dependencies
            "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "ChaosVehicles", "PhysicsCore",
    
            // UI Dependencies
            "UMG", "SlateCore",

            });

        PrivateDependencyModuleNames.AddRange(new string[] { });

        PublicIncludePaths.AddRange(new string[] { "CX" });
    }
}
