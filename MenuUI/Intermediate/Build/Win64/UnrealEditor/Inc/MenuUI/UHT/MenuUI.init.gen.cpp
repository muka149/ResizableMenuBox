// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMenuUI_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_MenuUI;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_MenuUI()
	{
		if (!Z_Registration_Info_UPackage__Script_MenuUI.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/MenuUI",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0xB6DB2A06,
				0xB33923C0,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_MenuUI.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_MenuUI.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_MenuUI(Z_Construct_UPackage__Script_MenuUI, TEXT("/Script/MenuUI"), Z_Registration_Info_UPackage__Script_MenuUI, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xB6DB2A06, 0xB33923C0));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
