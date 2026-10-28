// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CXPawn.h"

#ifdef CX_CXPawn_generated_h
#error "CXPawn.generated.h already included, missing '#pragma once' in CXPawn.h"
#endif
#define CX_CXPawn_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class ACXPawn ******************************************************************
#define FID_Git_CX_Source_CX_CXPawn_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void CTSAttack_Implementation(); \
	DECLARE_FUNCTION(execCTSAttack);


#define FID_Git_CX_Source_CX_CXPawn_h_27_CALLBACK_WRAPPERS
CX_API UClass* Z_Construct_UClass_ACXPawn_NoRegister();

#define FID_Git_CX_Source_CX_CXPawn_h_27_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACXPawn(); \
	friend struct Z_Construct_UClass_ACXPawn_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend CX_API UClass* Z_Construct_UClass_ACXPawn_NoRegister(); \
public: \
	DECLARE_CLASS2(ACXPawn, AWheeledVehiclePawn, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/CX"), Z_Construct_UClass_ACXPawn_NoRegister) \
	DECLARE_SERIALIZER(ACXPawn)


#define FID_Git_CX_Source_CX_CXPawn_h_27_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ACXPawn(ACXPawn&&) = delete; \
	ACXPawn(const ACXPawn&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACXPawn); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACXPawn); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(ACXPawn) \
	NO_API virtual ~ACXPawn();


#define FID_Git_CX_Source_CX_CXPawn_h_24_PROLOG
#define FID_Git_CX_Source_CX_CXPawn_h_27_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Git_CX_Source_CX_CXPawn_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Git_CX_Source_CX_CXPawn_h_27_CALLBACK_WRAPPERS \
	FID_Git_CX_Source_CX_CXPawn_h_27_INCLASS_NO_PURE_DECLS \
	FID_Git_CX_Source_CX_CXPawn_h_27_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ACXPawn;

// ********** End Class ACXPawn ********************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Git_CX_Source_CX_CXPawn_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
