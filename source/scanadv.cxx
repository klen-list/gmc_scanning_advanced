#include "scanning/scanadv.h"

#ifdef ARCHITECTURE_X86_64
	#error ERROR: SRCDS x86-64 is not supported, I dont use x64 myself
	#error No reason for me use x64 SRCDS with ???[no symbol for this frame] crashstack unwind and sigs instead x32 easy visible symbols
#endif

namespace ScanningAdvanced
{
	namespace Symbols {
		// === Util symbols ===

		// void __cdecl sub_103CC6A0(int)
		// note: linux: UTIL_Remove(CBaseEntity*) -> call UTIL_Remove(IServerNetworkable*) with ent+20
		// note: windows: UTIL_Remove(CBaseEntity*) -> just use v1 = ent+12 as IServerNetworkable*
		const Symbol UTIL_Remove = DEFSYM("\x55\x8B\xEC\x56\x8B\x75\x08\x85\xF6\x74\x61\x83", "_Z11UTIL_RemoveP11CBaseEntity");
		
		// int __cdecl sub_100C30E0(int a1)
		// note: if a1 pass OP_TEST - return UTIL_EntityByIndex, else return GetWorldEntity
		const Symbol GMEntityByIndex = DEFSYM("\x55\x8B\xEC\x8B\x45\x08\x85\xC0\x75\x06\x5D", "_Z15GMEntityByIndexi");

		// === VPhysics symbols ===

		// char __thiscall sub_1031AAC0(_DWORD *this, int a2, int a3)
		// note: 1:1 windows and linux psecudocode
		// warn: at linux use __cdecl instead __thiscall
		const Symbol CCollisionEvent_ShouldFreezeContacts = DEFSYM("\x55\x8B\xEC\x8B\x15****\x56\x8B", "_ZN15CCollisionEvent20ShouldFreezeContactsEPP14IPhysicsObjecti");

		// int (***sub_10319610())() -> "return &off_1098F770"
		// warn: CANT get update-stable sig for this
		// note: just keep last 2b of .data addr updated (find a func inside CServerGameDLL::DLLInit)
		const Symbol PhysicsGameSystem = DEFSYM("\xB8\x70\xF7**\xC3", "_Z17PhysicsGameSystemv");

		// int sub_103191E0() -> calls FlushQueuedOperations at &g_Collisions
		//                    -> calls physenv + dword* offset 196 (200 at linux)
		// note: method doesnt have return (use void)
		const Symbol PhysOnCleanupDeleteList = DEFSYM("\xB9****\xE8****\x8B\x0D****\x85\xC9\x74\x08\x8B\x01\xFF\xA0\xC4", "_Z23PhysOnCleanupDeleteListv");

		// bool sub_10303510() -> call physenv + 140 (144 at linux) and check .data globalvar dword > 0
		// note: I also found GMOD_PhysIsInCallback, its return result of (GMOD_PhysicsGameSystemIsInCallback || PhysIsInCallback)
		// note: GMOD_PhysIsInCallback return globalvar byte and used in many Entity__*(LuaInterface), TODO: get more info about this
		const Symbol PhysIsInCallback = DEFSYM("\x8B\x0D****\x85\xC9\x74\x0E\x8B\x01\x8B\x80\x8C\x00\x00\x00\xFF\xD0\x84\xC0\x75\x09", "_Z16PhysIsInCallbackv");

		// int __thiscall sub_10084150(_DWORD *this, int*)
		// warn: at linux use __cdecl instead __thiscall
		// note: method doesnt have return (use void)
		const Symbol expand_tree = DEFSYM("\x55\x8B\xEC\x83\xEC\x08\x53\x56\x8B\xF1\x8B\x46\x34", "_ZN19IVP_OV_Tree_Manager11expand_treeEPK11IVP_OV_Node");

		// void __cdecl sub_103187D0(float)
		// note: linux - unsigned int (still void) __usercall PhysFrame@<eax>(float@<xmm0>)
		// warn: windows - stack reserve byte (sub esp - 83~EC) changed 20(x14)->28(x1C) from last upd
		// I also turned this byte into mask, but sig became longer, keep eye on this
		const Symbol PhysFrame = DEFSYM("\x55\x8B\xEC\x83\xEC*\x83\x3D****\x00\x53\x56\x57\x0F", "_ZL9PhysFramef");

		// === Player-related symbols ===

		// char __thiscall sub_1008BE90(_DWORD *this, int a2)
		// warn: at linux use __cdecl instead __thiscall
		const Symbol CBaseClient_ProcessStringCmd = DEFSYM("\x55\x8B\xEC\x8B\x45\x08\x83\xC1\xFC", "_ZN11CBaseClient16ProcessStringCmdEP13NET_StringCmd");

		// === Lua-related symbols ===

		// void __cdecl sub_101662C0(void *Src)
		// note: linux - method doesnt have return (use void)
		// note: *Src is std::string const&
		const Symbol GModAutoRefresh_HandleLuaFileChange = DEFSYM("\x55\x8B\xEC\x83\xEC\x4C\x53\x8B\x5D\x08\x8D", "_ZN9GarrysMod11AutoRefresh19HandleLuaFileChangeERKSs");

		// === Experimental symbols (Test symbols while searching for a problem solutions, high probability of deletion/modify) ===

		const Symbol CObjectPairHash_RemoveAllPairsForObject = DEFSYM("\x55\x8B\xEC\x8B\x45\x08\x83\xEC\x10", "_ZN15CObjectPairHash23RemoveAllPairsForObjectEPv");
	}
	
	PhysicsGameSystem_t PhysicsGameSystem()
	{
		
		return SigResolve<PhysicsGameSystem_t>(Loaders::Server, Symbols::PhysicsGameSystem, "PhysicsGameSystem");
	}

	PhysOnCleanupDeleteList_t PhysOnCleanupDeleteList()
	{
		return SigResolve<PhysOnCleanupDeleteList_t>(Loaders::Server, Symbols::PhysOnCleanupDeleteList, "PhysOnCleanupDeleteList");
	}

	PhysIsInCallback_t PhysIsInCallback()
	{
		return SigResolve<PhysIsInCallback_t>(Loaders::Server, Symbols::PhysIsInCallback, "PhysIsInCallback");
	}

	CCollisionEvent_ShouldFreezeContacts_t CCollisionEvent_ShouldFreezeContacts()
	{
		return SigResolve<CCollisionEvent_ShouldFreezeContacts_t>(Loaders::Server, Symbols::CCollisionEvent_ShouldFreezeContacts, "CCollisionEvent::ShouldFreezeContacts");
	}

	UTIL_Remove_t UTIL_Remove()
	{
		return SigResolve<UTIL_Remove_t>(Loaders::Server, Symbols::UTIL_Remove, "UTIL_Remove");
	}

	expand_tree_t expand_tree()
	{
		return SigResolve<expand_tree_t>(Loaders::VPhysic, Symbols::expand_tree, "IVP_OV_Tree_Manager::expand_tree");
	}

	GMEntityByIndex_t GMEntityByIndex()
	{
		return SigResolve<GMEntityByIndex_t>(Loaders::Server, Symbols::GMEntityByIndex, "GMEntityByIndex");
	}

	CBaseClient_ProcessStringCmd_t CBaseClient_ProcessStringCmd()
	{
		return SigResolve<CBaseClient_ProcessStringCmd_t>(Loaders::Engine, Symbols::CBaseClient_ProcessStringCmd, "CBaseClient::ProcessStringCmd");
	}

	GModAutoRefresh_HandleLuaFileChange_t GModAutoRefresh_HandleLuaFileChange()
	{
		return SigResolve<GModAutoRefresh_HandleLuaFileChange_t>(Loaders::Server, Symbols::GModAutoRefresh_HandleLuaFileChange, "GarrysMod::AutoRefresh::HandleLuaFileChange");
	}

	PhysFrame_t PhysFrame()
	{
		return SigResolve<PhysFrame_t>(Loaders::Server, Symbols::PhysFrame, "PhysFrame");
	}

	CObjectPairHash_RemoveAllPairsForObject_t CObjectPairHash_RemoveAllPairsForObject()
	{
		return SigResolve<CObjectPairHash_RemoveAllPairsForObject_t>(Loaders::VPhysic, Symbols::CObjectPairHash_RemoveAllPairsForObject, "CObjectPairHash::RemoveAllPairsForObject");
	}
}