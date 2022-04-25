// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class HN : ModuleRules
{
	public HN(ReadOnlyTargetRules Target) : base(Target)
	{
		PrivateDependencyModuleNames.AddRange(new string[] {"GameplayAbilities"});
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "HNAbility", "HNCharacter" });
	}
}
