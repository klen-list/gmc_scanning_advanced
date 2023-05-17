#pragma once

#include <GarrysMod/FactoryLoader.hpp>
#include <GarrysMod/Symbol.hpp>
#include <scanning/symbolfinder.hpp>
#include <detouring/hook.hpp>

#include <tier0/dbg.h>
#include <tier1/netadr.h>

class CPhysicsHook;
class CCollisionEvent;
class IPhysicsObject;
class CBaseEntity;
class CBaseClient;
class CMultiplayRules;
class KeyValues;
struct edict_t;

#ifdef SYSTEM_WINDOWS
	#define TYPEDIFF_WIN(win, other) win

	#ifdef ARCHITECTURE_X86
		#define TYPEDIFF_WIN86(win, other) win
		#define TYPEDIFF_WIN64(win, other) other
	#elif ARCHITECTURE_X86_64
		#define TYPEDIFF_WIN86(win, other) other
		#define TYPEDIFF_WIN64(win, other) win
	#endif
#else
	#define TYPEDIFF_WIN(win, other) other
	#define TYPEDIFF_WIN86(win, other) other
	#define TYPEDIFF_WIN64(win, other) other
#endif

namespace ScanningAdvanced
{
	namespace Symbols {
		extern const Symbol PhysicsGameSystem;
		extern const Symbol PhysOnCleanupDeleteList;
		extern const Symbol PhysIsInCallback;
		extern const Symbol expand_tree;
		extern const Symbol CCollisionEvent_ShouldFreezeContacts;
		extern const Symbol UTIL_Remove;
		extern const Symbol GMEntityByIndex;
		extern const Symbol CBaseClient_ProcessStringCmd;
		extern const Symbol CMultiplayRules_ClientCommandKeyValues;
		extern const Symbol GModDataPack_GetHashFromDatatable;
		extern const Symbol PhysFrame;
	}
	
	static SymbolFinder symbolfinder;

	template <class T>
	static inline T SigResolve(SourceSDK::FactoryLoader& loader, const Symbol& symbol, const char* name)
	{
		static T original = reinterpret_cast<T>(symbolfinder.Resolve(
			loader.GetModule(), symbol.name.c_str(), symbol.length, nullptr
		));

		if (!original)
		{
			Warning("%s: Signature not found\n", name);
			return nullptr;
		}

		return original;
	}

	template <class T>
	static inline void FastDetour(Detouring::Hook& detour, T original, void* hook, const char* name)
	{
		if (original)
		{
			if (!detour.Create(Detouring::Hook::Target(reinterpret_cast<void*>(original)), hook))
				Warning("%s: Unable to detour!\n", name);
			else
				detour.Enable();
		}
	}

	typedef CPhysicsHook* (*PhysicsGameSystem_t)();
	PhysicsGameSystem_t PhysicsGameSystem();

	typedef void (*PhysOnCleanupDeleteList_t)();
	PhysOnCleanupDeleteList_t PhysOnCleanupDeleteList();

	typedef bool (*PhysIsInCallback_t)();
	PhysIsInCallback_t PhysIsInCallback();

	typedef void (*expand_tree_t)(uintptr_t pTree, uintptr_t howmuch);
	expand_tree_t expand_tree();

#if defined(SYSTEM_WINDOWS) && defined(ARCHITECTURE_X86)
	// TODO: Add callconv and check for missing IPhysicsObject**
	typedef bool (*CCollisionEvent_ShouldFreezeContacts_t)(CCollisionEvent* pEvent, int objC);
	__declspec(deprecated("TODO: Fixme")) CCollisionEvent_ShouldFreezeContacts_t CCollisionEvent_ShouldFreezeContacts();
#else
	typedef bool (*CCollisionEvent_ShouldFreezeContacts_t)(CCollisionEvent* pEvent, IPhysicsObject** pObjList, int objC);
	CCollisionEvent_ShouldFreezeContacts_t CCollisionEvent_ShouldFreezeContacts();
#endif

	typedef void (*UTIL_Remove_t)(CBaseEntity* pEnt);
	UTIL_Remove_t UTIL_Remove();
	
	typedef CBaseEntity* (TYPEDIFF_WIN64(__fastcall, __cdecl) *GMEntityByIndex_t)(int32 index);
	GMEntityByIndex_t GMEntityByIndex();

	typedef bool (TYPEDIFF_WIN86(__thiscall, __cdecl) *CBaseClient_ProcessStringCmd_t)(CBaseClient* client, uintptr_t* cmd);
	CBaseClient_ProcessStringCmd_t CBaseClient_ProcessStringCmd();

	typedef char* (__cdecl *CMultiplayRules_ClientCommandKeyValues_t)(CMultiplayRules* pMPRules, edict_t* pEntity, KeyValues* pKeyValues);
	CMultiplayRules_ClientCommandKeyValues_t CMultiplayRules_ClientCommandKeyValues();
	
	typedef TYPEDIFF_WIN(void, int) (__cdecl* GModAutoRefresh_HandleLuaFileChange_t)(void*);
	GModAutoRefresh_HandleLuaFileChange_t GModAutoRefresh_HandleLuaFileChange();
	
	typedef void* (__stdcall* GModDataPack_GetHashFromDatatable_t)(void*, std::string const&, std::string);
	GModDataPack_GetHashFromDatatable_t GModDataPack_GetHashFromDatatable();

	typedef TYPEDIFF_WIN(void, unsigned int) (__cdecl* PhysFrame_t)(float);
	PhysFrame_t PhysFrame();
}