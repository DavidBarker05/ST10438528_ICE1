// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ST10438528_ICE1 : ModuleRules
{
	public ST10438528_ICE1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"ST10438528_ICE1",
			"ST10438528_ICE1/Variant_Platforming",
			"ST10438528_ICE1/Variant_Combat",
			"ST10438528_ICE1/Variant_Combat/AI",
			"ST10438528_ICE1/Variant_SideScrolling",
			"ST10438528_ICE1/Variant_SideScrolling/Gameplay",
			"ST10438528_ICE1/Variant_SideScrolling/AI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
