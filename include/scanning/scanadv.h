#pragma once

#include <GarrysMod/FactoryLoader.hpp>
#include <GarrysMod/Symbol.hpp>
#include <scanning/symbolfinder.hpp>
#include <detouring/hook.hpp>

#include <tier0/dbg.h>
#include <tier1/netadr.h>

#ifdef ARCHITECTURE_X86
typedef unsigned long _DWORD;
#elif ARCHITECTURE_X86_64
typedef unsigned long long _DWORD;
#endif

class CPhysicsHook;
class CCollisionEvent;
class IPhysicsObject;
class CBaseEntity;
class INetworkStringTable;
class CBaseClientState;
class CClientState;

namespace ScanningAdvanced
{
	namespace Symbols {
		extern const Symbol PhysicsGameSystem;
		extern const Symbol PhysOnCleanupDeleteList;
		extern const Symbol PhysIsInCallback;
		extern const Symbol expand_tree;
		extern const Symbol CCollisionEvent_ShouldFreezeContacts;
		extern const Symbol UTIL_Remove;
		extern const Symbol CBaseClientState_SetSignonState;
		extern const Symbol CBaseClientState_Disconnect;
		extern const Symbol CClientState_FullConnect;
		extern const Symbol GMEntityByIndex;
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
			Warning("%s: Detour failed: Signature not found\n", name);
			return nullptr;
		}

		return original;
	}

	template <class T>
	static inline void FastDetour(Detouring::Hook& detour, T original, void* hook, const char* name)
	{
		if (original)
			if (!detour.Create(Detouring::Hook::Target(reinterpret_cast<void*>(original)), hook))
				Warning("Unable to detour %s!\n", name);
			else
				detour.Enable();
	}

	typedef CPhysicsHook* (*PhysicsGameSystem_t)();
	PhysicsGameSystem_t PhysicsGameSystem();

	typedef void (*PhysOnCleanupDeleteList_t)();
	PhysOnCleanupDeleteList_t PhysOnCleanupDeleteList();

	typedef bool (*PhysIsInCallback_t)();
	PhysIsInCallback_t PhysIsInCallback();

	typedef void (*expand_tree_t)(_DWORD pTree, _DWORD howmuch);
	expand_tree_t expand_tree();

#if defined(SYSTEM_WINDOWS) && defined(ARCHITECTURE_X86)
	// IPhysicsObject** missing at this game version
	typedef bool (*CCollisionEvent_ShouldFreezeContacts_t)(CCollisionEvent* pEvent, int objC);
	__declspec(deprecated("Detouring this cause vphysics crash at Windows x86!")) CCollisionEvent_ShouldFreezeContacts_t CCollisionEvent_ShouldFreezeContacts();
#else
	typedef bool (*CCollisionEvent_ShouldFreezeContacts_t)(CCollisionEvent* pEvent, IPhysicsObject** pObjList, int objC);
	CCollisionEvent_ShouldFreezeContacts_t CCollisionEvent_ShouldFreezeContacts();
#endif

	typedef void (*UTIL_Remove_t)(CBaseEntity* pEnt);
	UTIL_Remove_t UTIL_Remove();

	typedef bool (__thiscall *CBaseClientState_SetSignonState_t)(CBaseClientState* state, int signon_state, int spawn_count);
	CBaseClientState_SetSignonState_t CBaseClientState_SetSignonState();

#if defined(SYSTEM_WINDOWS) && defined(ARCHITECTURE_X86_64)
	typedef __int64(__fastcall *CBaseClientState_Disconnect_t)(CBaseClientState* state, const char* reason);
#else 
	typedef void(__thiscall *CBaseClientState_Disconnect_t)(CBaseClientState* state, const char* reason, bool bShowMainMenu);
#endif
	CBaseClientState_Disconnect_t CBaseClientState_Disconnect();

	// Its CClientState part, but there CBaseClientState for capability with classproxy
	typedef void(__thiscall *CClientState_FullConnect_t)(CBaseClientState* state, netadr_t& adr);
	CClientState_FullConnect_t CClientState_FullConnect();

	typedef CBaseEntity*
#if defined(SYSTEM_WINDOWS) && defined(ARCHITECTURE_X86_64)
		(__fastcall
#else
		(__cdecl
#endif
		*GMEntityByIndex_t)(int32 index);
	GMEntityByIndex_t GMEntityByIndex();
}