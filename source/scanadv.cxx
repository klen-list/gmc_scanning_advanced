#include "scanning/scanadv.h"

namespace ScanningAdvanced
{
	namespace Symbols {
#ifdef SYSTEM_WINDOWS
#ifdef ARCHITECTURE_X86
		const Symbol UTIL_PlayerDecalTrace = Symbol::FromSignature("\x55\x8B\xEC\x83\xEC\x20\x56\x8B\x75\x08\xF3\x0F\x10\x46\x2C\x0F\x2E\x05****\x9F\xF6\xC4\x44\x7B\x4E\x8D\x4D\xE0\xE8****\x8D\x4D");
		const Symbol UTIL_Remove = Symbol::FromSignature("TODO_TODO_TODO");
		const Symbol CCollisionEvent_ShouldFreezeContacts = Symbol::FromSignature("\x55\x8B\xEC\x8B\x15\x58\x2C**\x56\x8B\xF1\x8B\x42\x18\x8B\x8E\x5C\x01\x00\x00\x3B\xC8\x7F*\x48\x3B\xC8\x7D*");
		const Symbol PhysicsGameSystem = Symbol::FromSignature("\xB8\x30\xC7**\xC3");
		const Symbol PhysOnCleanupDeleteList = Symbol::FromSignature("\xB9\xC8\xC5**\xE8\x46\xD7**\x8B\x0D\x58\xAF**\x85\xC9\x74*\x8B\x01\xFF\xA0\xC4\x00\x00\x00\xC3");
		const Symbol PhysIsInCallback = Symbol::FromSignature("\x8B\x0D\x58\xAF**\x85\xC9\x74*\x8B\x01\x8B\x80\x8C\x00\x00\x00\xFF\xD0\x84\xC0\x75*\x83\x3D\x24***\x00\x7E*\xB0\x01\xC3\x32\xC0\xC3");
		const Symbol expand_tree = Symbol::FromSignature("\x55\x8B\xEC\x83\xEC\x08\x53\x56\x8B\xF1\x8B\x46\x34\x8B\x40\x10\x57\x89*\xF8\x83\xF8\x28\x7E*\x50\x68\x48***\xE8\x74***\x83\xC4\x08");
		const Symbol CBaseClientState_SetSignonState = Symbol::FromSignature("\x55\x8B\xEC\x56\x57\x8B\x7D\x08\x8B\xF1\x83\xFF\x07\x77\x1B\x83\xFF\x02");
		const Symbol CBaseClientState_Disconnect = Symbol::FromSignature("\x55\x8B\xEC\xDD\x05****\x83\xEC\x28\x56\x8B\xF1\x57\x8B\xBE");
		const Symbol CClientState_FullConnect = Symbol::FromSignature("\x55\x8B\xEC\x53\x8B\x5D\x08\x56\x57\x53\x8B\xF9\xE8****\x8B\x4F\x10");
		const Symbol GMEntityByIndex = Symbol::FromSignature("\x55\x8B\xEC\x8B\x45\x08\x85\xC0\x75\x06\x5D\xE9****\x89\x45\x08\x5D\xE9****\xCC");

#elif ARCHITECTURE_X86_64
		const Symbol UTIL_PlayerDecalTrace = Symbol::FromSignature("TODO_TODO_TODO");
		const Symbol UTIL_Remove = Symbol::FromSignature("\x48\x83\xEC\x28\x48\x85\xC9\x0F\x84****\x48\x89\x5C\x24\x30\x48\x8D\x59\x18\x48\x85\xDB\x74*\x48\x8B\xCB\xE8****\x84\xC0\x75\x67\xE8****");
		const Symbol CCollisionEvent_ShouldFreezeContacts = Symbol::FromSignature("\x40\x53\x48\x83\xEC\x20\x48\x8B\x15****\x48\x8B\xD9\x8B\x89\x04\x02\x00\x00\x8B\x42\x18\x3B\xC8\x7F*\xFF\xC8\x3B\xC8\x7D*");
		const Symbol PhysicsGameSystem = Symbol::FromSignature("TODO_TODO_TODO");
		const Symbol PhysOnCleanupDeleteList = Symbol::FromSignature("TODO_TODO_TODO");
		const Symbol PhysIsInCallback = Symbol::FromName("?PhysIsInCallback@@YA_NXZ");
		const Symbol expand_tree = Symbol::FromSignature("TODO_TODO_TODO");
		const Symbol CBaseClientState_SetSignonState = Symbol::FromSignature("\x48\x89\x5C\x24*\x48\x89\x74\x24*\x57\x48\x83\xEC\x20\x41\x8B\xF0\x8B");
		const Symbol CBaseClientState_Disconnect = Symbol::FromSignature("\x48\x89\x5C\x24*\x48\x89\x74\x24*\x57\x48\x83\xEC\x60\x48\x8B\x05****\x48\x33");
		const Symbol CClientState_FullConnect = Symbol::FromSignature("\x48\x89\x5C\x24*\x48\x89\x74\x24*\x57\x48\x83\xEC\x20\x48\x8B\xF2\x48\x8B\xF9\xE8****\x48\x8B\x4F\x20");
		const Symbol GMEntityByIndex = Symbol::FromSignature("\x85\xC9\x0F\x84****\xE9****\xCC");
#endif
#elif SYSTEM_LINUX
#ifdef ARCHITECTURE_X86
		const Symbol UTIL_PlayerDecalTrace = Symbol::FromName("_Z21UTIL_PlayerDecalTraceP10CGameTracei");
		const Symbol UTIL_Remove = Symbol::FromName("_Z11UTIL_RemoveP11CBaseEntity");
		const Symbol CCollisionEvent_ShouldFreezeContacts = Symbol::FromName("_ZN15CCollisionEvent20ShouldFreezeContactsEPP14IPhysicsObjecti");
		const Symbol PhysicsGameSystem = Symbol::FromName("_Z17PhysicsGameSystemv");
		const Symbol PhysOnCleanupDeleteList = Symbol::FromName("_Z23PhysOnCleanupDeleteListv");
		const Symbol PhysIsInCallback = Symbol::FromName("_Z16PhysIsInCallbackv");
		const Symbol expand_tree = Symbol::FromName("_ZN19IVP_OV_Tree_Manager11expand_treeEPK11IVP_OV_Node");
		const Symbol CBaseClientState_SetSignonState = Symbol::FromSignature("TODO_TODO_TODO");
		const Symbol CBaseClientState_Disconnect = Symbol::FromSignature("TODO_TODO_TODO");
		const Symbol CClientState_FullConnect = Symbol::FromSignature("TODO_TODO_TODO");
		const Symbol GMEntityByIndex = Symbol::FromName("_Z15GMEntityByIndexi");
#elif ARCHITECTURE_X86_64
		const Symbol UTIL_PlayerDecalTrace = Symbol::FromSignature("TODO_TODO_TODO");
		const Symbol UTIL_Remove = Symbol::FromName("TODO_TODO_TODO");
		const Symbol CCollisionEvent_ShouldFreezeContacts = Symbol::FromName("TODO_TODO_TODO");
		const Symbol PhysicsGameSystem = Symbol::FromName("TODO_TODO_TODO");
		const Symbol PhysOnCleanupDeleteList = Symbol::FromName("TODO_TODO_TODO");
		const Symbol PhysIsInCallback = Symbol::FromName("TODO_TODO_TODO");
		const Symbol expand_tree = Symbol::FromName("TODO_TODO_TODO");
		const Symbol CBaseClientState_SetSignonState = Symbol::FromSignature("TODO_TODO_TODO");
		const Symbol CBaseClientState_Disconnect = Symbol::FromSignature("TODO_TODO_TODO");
		const Symbol CClientState_FullConnect = Symbol::FromSignature("TODO_TODO_TODO");
		const Symbol GMEntityByIndex = Symbol::FromSignature("\x55\x85\xFF\x48\x89\xE5\x74\x08\x5D\xE9****\x66\x90\x5D\xE9****");
#endif
#endif
	}

	PhysicsGameSystem_t PhysicsGameSystem()
	{
		static SourceSDK::FactoryLoader server_loader("server");
		return SigResolve<PhysicsGameSystem_t>(server_loader, Symbols::PhysicsGameSystem, "PhysicsGameSystem");
	}

	PhysOnCleanupDeleteList_t PhysOnCleanupDeleteList()
	{
		static SourceSDK::FactoryLoader server_loader("server");
		return SigResolve<PhysOnCleanupDeleteList_t>(server_loader, Symbols::PhysOnCleanupDeleteList, "PhysOnCleanupDeleteList");
	}

	PhysIsInCallback_t PhysIsInCallback()
	{
		static SourceSDK::FactoryLoader server_loader("server");
		return SigResolve<PhysIsInCallback_t>(server_loader, Symbols::PhysIsInCallback, "PhysIsInCallback");
	}

	CCollisionEvent_ShouldFreezeContacts_t CCollisionEvent_ShouldFreezeContacts()
	{
		static SourceSDK::FactoryLoader server_loader("server");
		return SigResolve<CCollisionEvent_ShouldFreezeContacts_t>(server_loader, Symbols::CCollisionEvent_ShouldFreezeContacts, "CCollisionEvent::ShouldFreezeContacts");
	}

	UTIL_Remove_t UTIL_Remove()
	{
		static SourceSDK::FactoryLoader server_loader("server");
		return SigResolve<UTIL_Remove_t>(server_loader, Symbols::UTIL_Remove, "UTIL_Remove");
	}

	UTIL_PlayerDecalTrace_t UTIL_PlayerDecalTrace()
	{
		static SourceSDK::FactoryLoader server_loader("server");
		return SigResolve<UTIL_PlayerDecalTrace_t>(server_loader, Symbols::UTIL_PlayerDecalTrace, "UTIL_PlayerDecalTrace");
	}

	expand_tree_t expand_tree()
	{
#if SYSTEM_WINDOWS
		static SourceSDK::FactoryLoader vphys_loader("vphysics");
#elif SYSTEM_LINUX
		static SourceSDK::FactoryLoader vphys_loader("vphysics_srv");
#endif

		return SigResolve<expand_tree_t>(vphys_loader, Symbols::expand_tree, "IVP_OV_Tree_Manager::expand_tree");
	}

	CBaseClientState_SetSignonState_t CBaseClientState_SetSignonState()
	{
#if SYSTEM_WINDOWS
		static SourceSDK::FactoryLoader engine_loader("engine");
#elif SYSTEM_LINUX
		static SourceSDK::FactoryLoader engine_loader("engine_client");
#endif
		return SigResolve<CBaseClientState_SetSignonState_t>(engine_loader, Symbols::CBaseClientState_SetSignonState, "CBaseClientState::SetSignonState");
	}

	CBaseClientState_Disconnect_t CBaseClientState_Disconnect()
	{
#if SYSTEM_WINDOWS
		static SourceSDK::FactoryLoader engine_loader("engine");
#elif SYSTEM_LINUX
		static SourceSDK::FactoryLoader engine_loader("engine_client");
#endif
		return SigResolve<CBaseClientState_Disconnect_t>(engine_loader, Symbols::CBaseClientState_Disconnect, "CBaseClientState::Disconnect");
	}

	CClientState_FullConnect_t CClientState_FullConnect()
	{
#if SYSTEM_WINDOWS
		static SourceSDK::FactoryLoader engine_loader("engine");
#elif SYSTEM_LINUX
		static SourceSDK::FactoryLoader engine_loader("engine_client");
#endif
		return SigResolve<CClientState_FullConnect_t>(engine_loader, Symbols::CClientState_FullConnect, "CClientState::FullConnect");
	}

	GMEntityByIndex_t GMEntityByIndex()
	{
		static SourceSDK::FactoryLoader server_loader("server");
		return SigResolve<GMEntityByIndex_t>(server_loader, Symbols::GMEntityByIndex, "GMEntityByIndex");
	}
}