// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SResizableMenuBox.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeSResizableMenuBox() {}

// ********** Begin Cross Module References ********************************************************
MENUUI_API UEnum* Z_Construct_UEnum_MenuUI_ESplitType();
UPackage* Z_Construct_UPackage__Script_MenuUI();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum ESplitType ****************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESplitType;
static UEnum* ESplitType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ESplitType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ESplitType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_MenuUI_ESplitType, (UObject*)Z_Construct_UPackage__Script_MenuUI(), TEXT("ESplitType"));
	}
	return Z_Registration_Info_UEnum_ESplitType.OuterSingleton;
}
template<> MENUUI_API UEnum* StaticEnum<ESplitType>()
{
	return ESplitType_StaticEnum();
}
struct Z_Construct_UEnum_MenuUI_ESplitType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Horizontal.DisplayName", "Horizontal" },
		{ "Horizontal.Name", "ESplitType::Horizontal" },
		{ "ModuleRelativePath", "Public/SResizableMenuBox.h" },
		{ "Vertical.DisplayName", "Vertiacal" },
		{ "Vertical.Name", "ESplitType::Vertical" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ESplitType::Horizontal", (int64)ESplitType::Horizontal },
		{ "ESplitType::Vertical", (int64)ESplitType::Vertical },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_MenuUI_ESplitType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_MenuUI,
	nullptr,
	"ESplitType",
	"ESplitType",
	Z_Construct_UEnum_MenuUI_ESplitType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_MenuUI_ESplitType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_MenuUI_ESplitType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_MenuUI_ESplitType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_MenuUI_ESplitType()
{
	if (!Z_Registration_Info_UEnum_ESplitType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESplitType.InnerSingleton, Z_Construct_UEnum_MenuUI_ESplitType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ESplitType.InnerSingleton;
}
// ********** End Enum ESplitType ******************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_itizi_Documents_Unreal_Projects_ResizableMenuBox_UE5_Plugins_MenuUI_Source_MenuUI_Public_SResizableMenuBox_h__Script_MenuUI_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ ESplitType_StaticEnum, TEXT("ESplitType"), &Z_Registration_Info_UEnum_ESplitType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2927037583U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_itizi_Documents_Unreal_Projects_ResizableMenuBox_UE5_Plugins_MenuUI_Source_MenuUI_Public_SResizableMenuBox_h__Script_MenuUI_543841321(TEXT("/Script/MenuUI"),
	nullptr, 0,
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Users_itizi_Documents_Unreal_Projects_ResizableMenuBox_UE5_Plugins_MenuUI_Source_MenuUI_Public_SResizableMenuBox_h__Script_MenuUI_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_itizi_Documents_Unreal_Projects_ResizableMenuBox_UE5_Plugins_MenuUI_Source_MenuUI_Public_SResizableMenuBox_h__Script_MenuUI_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
