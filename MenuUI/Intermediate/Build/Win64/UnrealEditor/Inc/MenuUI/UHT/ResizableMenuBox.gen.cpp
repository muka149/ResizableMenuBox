// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ResizableMenuBox.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeResizableMenuBox() {}

// ********** Begin Cross Module References ********************************************************
MENUUI_API UClass* Z_Construct_UClass_UResizableMenuBox();
MENUUI_API UClass* Z_Construct_UClass_UResizableMenuBox_NoRegister();
MENUUI_API UEnum* Z_Construct_UEnum_MenuUI_ESplitType();
UMG_API UClass* Z_Construct_UClass_UCanvasPanel();
UPackage* Z_Construct_UPackage__Script_MenuUI();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UResizableMenuBox ********************************************************
void UResizableMenuBox::StaticRegisterNativesUResizableMenuBox()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UResizableMenuBox;
UClass* UResizableMenuBox::GetPrivateStaticClass()
{
	using TClass = UResizableMenuBox;
	if (!Z_Registration_Info_UClass_UResizableMenuBox.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ResizableMenuBox"),
			Z_Registration_Info_UClass_UResizableMenuBox.InnerSingleton,
			StaticRegisterNativesUResizableMenuBox,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UResizableMenuBox.InnerSingleton;
}
UClass* Z_Construct_UClass_UResizableMenuBox_NoRegister()
{
	return UResizableMenuBox::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UResizableMenuBox_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "ResizableMenuBox.h" },
		{ "ModuleRelativePath", "Public/ResizableMenuBox.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SplitType_MetaData[] = {
		{ "Category", "Menu Settings" },
		{ "ModuleRelativePath", "Public/ResizableMenuBox.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SplitRatio_MetaData[] = {
		{ "Category", "Menu Settings" },
		{ "ModuleRelativePath", "Public/ResizableMenuBox.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_SplitType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SplitType;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SplitRatio_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SplitRatio;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UResizableMenuBox>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UResizableMenuBox_Statics::NewProp_SplitType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UResizableMenuBox_Statics::NewProp_SplitType = { "SplitType", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UResizableMenuBox, SplitType), Z_Construct_UEnum_MenuUI_ESplitType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SplitType_MetaData), NewProp_SplitType_MetaData) }; // 2927037583
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UResizableMenuBox_Statics::NewProp_SplitRatio_Inner = { "SplitRatio", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UResizableMenuBox_Statics::NewProp_SplitRatio = { "SplitRatio", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UResizableMenuBox, SplitRatio), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SplitRatio_MetaData), NewProp_SplitRatio_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UResizableMenuBox_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UResizableMenuBox_Statics::NewProp_SplitType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UResizableMenuBox_Statics::NewProp_SplitType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UResizableMenuBox_Statics::NewProp_SplitRatio_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UResizableMenuBox_Statics::NewProp_SplitRatio,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UResizableMenuBox_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UResizableMenuBox_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UCanvasPanel,
	(UObject* (*)())Z_Construct_UPackage__Script_MenuUI,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UResizableMenuBox_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UResizableMenuBox_Statics::ClassParams = {
	&UResizableMenuBox::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UResizableMenuBox_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UResizableMenuBox_Statics::PropPointers),
	0,
	0x00B000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UResizableMenuBox_Statics::Class_MetaDataParams), Z_Construct_UClass_UResizableMenuBox_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UResizableMenuBox()
{
	if (!Z_Registration_Info_UClass_UResizableMenuBox.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UResizableMenuBox.OuterSingleton, Z_Construct_UClass_UResizableMenuBox_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UResizableMenuBox.OuterSingleton;
}
UResizableMenuBox::UResizableMenuBox(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UResizableMenuBox);
UResizableMenuBox::~UResizableMenuBox() {}
// ********** End Class UResizableMenuBox **********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_itizi_Documents_Unreal_Projects_ResizableMenuBox_UE5_Plugins_MenuUI_Source_MenuUI_Public_ResizableMenuBox_h__Script_MenuUI_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UResizableMenuBox, UResizableMenuBox::StaticClass, TEXT("UResizableMenuBox"), &Z_Registration_Info_UClass_UResizableMenuBox, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UResizableMenuBox), 4108409318U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_itizi_Documents_Unreal_Projects_ResizableMenuBox_UE5_Plugins_MenuUI_Source_MenuUI_Public_ResizableMenuBox_h__Script_MenuUI_1646862703(TEXT("/Script/MenuUI"),
	Z_CompiledInDeferFile_FID_Users_itizi_Documents_Unreal_Projects_ResizableMenuBox_UE5_Plugins_MenuUI_Source_MenuUI_Public_ResizableMenuBox_h__Script_MenuUI_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_itizi_Documents_Unreal_Projects_ResizableMenuBox_UE5_Plugins_MenuUI_Source_MenuUI_Public_ResizableMenuBox_h__Script_MenuUI_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
