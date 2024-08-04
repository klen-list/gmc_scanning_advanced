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
class CObjectPairHash;

#ifdef SYSTEM_WINDOWS
	#define DIFF_WINUNIX(win, unix) win
	#define SYM Symbol::FromSignature
	#define DEFSYM(win, unix) SYM(win)
#elif SYSTEM_LINUX
	#define DIFF_WINUNIX(win, unix) unix
	#define SYM Symbol::FromName
	#define DEFSYM(win, unix) SYM(unix)
#else
	#error Unsupported platform!
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
		extern const Symbol GModAutoRefresh_HandleLuaFileChange;
		extern const Symbol PhysFrame;
		extern const Symbol CObjectPairHash_RemoveAllPairsForObject;
	}

	namespace Loaders {
		static SourceSDK::FactoryLoader Server("server");
		static SourceSDK::FactoryLoader VPhysic("vphysics");
		static SourceSDK::FactoryLoader Engine("engine");
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

	typedef void (DIFF_WINUNIX(__thiscall, __cdecl)* expand_tree_t)(uintptr_t pTree, uintptr_t howmuch);
	expand_tree_t expand_tree();

	typedef bool (DIFF_WINUNIX(__thiscall, __cdecl)* CCollisionEvent_ShouldFreezeContacts_t)(CCollisionEvent* pEvent, IPhysicsObject** pObjList, int objC);
	CCollisionEvent_ShouldFreezeContacts_t CCollisionEvent_ShouldFreezeContacts();

	typedef void (__cdecl* UTIL_Remove_t)(CBaseEntity* pEnt);
	UTIL_Remove_t UTIL_Remove();
	
	typedef CBaseEntity* (__cdecl* GMEntityByIndex_t)(int32_t index);
	GMEntityByIndex_t GMEntityByIndex();

	typedef bool (DIFF_WINUNIX(__thiscall, __cdecl)* CBaseClient_ProcessStringCmd_t)(CBaseClient* client, uintptr_t* cmd);
	CBaseClient_ProcessStringCmd_t CBaseClient_ProcessStringCmd();
	
	typedef void (__cdecl* GModAutoRefresh_HandleLuaFileChange_t)(const std::string &file);
	GModAutoRefresh_HandleLuaFileChange_t GModAutoRefresh_HandleLuaFileChange();

	typedef void (__cdecl* PhysFrame_t)(float deltaTime);
	PhysFrame_t PhysFrame();

	typedef int(__cdecl* CObjectPairHash_RemoveAllPairsForObject_t)(CObjectPairHash* hash, void* pObject);
	CObjectPairHash_RemoveAllPairsForObject_t CObjectPairHash_RemoveAllPairsForObject();
}