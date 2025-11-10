// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SResizableMenuBox.h"

#ifdef MENUUI_SResizableMenuBox_generated_h
#error "SResizableMenuBox.generated.h already included, missing '#pragma once' in SResizableMenuBox.h"
#endif
#define MENUUI_SResizableMenuBox_generated_h

#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_itizi_Documents_Unreal_Projects_ResizableMenuBox_UE5_Plugins_MenuUI_Source_MenuUI_Public_SResizableMenuBox_h

// ********** Begin Enum ESplitType ****************************************************************
#define FOREACH_ENUM_ESPLITTYPE(op) \
	op(ESplitType::Horizontal) \
	op(ESplitType::Vertical) 

enum class ESplitType : uint8;
template<> struct TIsUEnumClass<ESplitType> { enum { Value = true }; };
template<> MENUUI_API UEnum* StaticEnum<ESplitType>();
// ********** End Enum ESplitType ******************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
