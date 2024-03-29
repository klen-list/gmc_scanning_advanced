#include "scanning/scanadv.h"

namespace ScanningAdvanced
{
	namespace Symbols {
#ifdef SYSTEM_WINDOWS
#ifdef ARCHITECTURE_X86
		const Symbol UTIL_Remove = Symbol::FromSignature("TODO_TODO_TODO");
		const Symbol CCollisionEvent_ShouldFreezeContacts = Symbol::FromSignature("\x55\x8B\xEC\x8B\x15\x58\x2C**\x56\x8B\xF1\x8B\x42\x18\x8B\x8E\x5C\x01\x00\x00\x3B\xC8\x7F*\x48\x3B\xC8\x7D*");
		const Symbol PhysicsGameSystem = Symbol::FromSignature("\xB8\x30\xC7**\xC3");
		const Symbol PhysOnCleanupDeleteList = Symbol::FromSignature("\xB9\xC8\xC5**\xE8\x46\xD7**\x8B\x0D\x58\xAF**\x85\xC9\x74*\x8B\x01\xFF\xA0\xC4\x00\x00\x00\xC3");
		const Symbol PhysIsInCallback = Symbol::FromSignature("\x8B\x0D\x58\xAF**\x85\xC9\x74*\x8B\x01\x8B\x80\x8C\x00\x00\x00\xFF\xD0\x84\xC0\x75*\x83\x3D\x24***\x00\x7E*\xB0\x01\xC3\x32\xC0\xC3");
		const Symbol expand_tree = Symbol::FromSignature("\x55\x8B\xEC\x83\xEC\x08\x53\x56\x8B\xF1\x8B\x46\x34\x8B\x40\x10\x57\x89*\xF8\x83\xF8\x28\x7E*\x50\x68\x48***\xE8\x74***\x83\xC4\x08");
		const Symbol GMEntityByIndex = Symbol::FromSignature("\x55\x8B\xEC\x8B\x45\x08\x85\xC0\x75\x06\x5D\xE9****\x89\x45\x08\x5D\xE9****\xCC");
		const Symbol CBaseClient_ProcessStringCmd = Symbol::FromSignature("\x55\x8B\xEC\x8B\x45\x08\x83\xC1\xFC");
		const Symbol CMultiplayRules_ClientCommandKeyValues = Symbol::FromSignature("TODO_TODO_TODO");
		const Symbol GModAutoRefresh_HandleLuaFileChange = Symbol::FromSignature("\x55\x8B\xEC\x83\xEC\x4C\x53\x8B\x5D\x08\x8D\x45\xE8\x56\x50\x53\xC7\x45*****\xC7\x45");
		const Symbol GModDataPack_GetHashFromDatatable = Symbol::FromSignature("TODO_TODO_TODO");
		const Symbol PhysFrame = Symbol::FromSignature("\x55\x8B\xEC\x83\xEC\x14\x83\x3D*****\x53\x56\x57\x0F\x84****\x80\x3D*****\x0F\x85");
#elif ARCHITECTURE_X86_64
		const Symbol UTIL_Remove = Symbol::FromSignature("\x48\x83\xEC\x28\x48\x85\xC9\x0F\x84****\x48\x89\x5C\x24\x30\x48\x8D\x59\x18\x48\x85\xDB\x74*\x48\x8B\xCB\xE8****\x84\xC0\x75\x67\xE8****");
		const Symbol CCollisionEvent_ShouldFreezeContacts = Symbol::FromSignature("\x40\x53\x48\x83\xEC\x20\x48\x8B\x15****\x48\x8B\xD9\x8B\x89\x04\x02\x00\x00\x8B\x42\x18\x3B\xC8\x7F*\xFF\xC8\x3B\xC8\x7D*");
		const Symbol PhysicsGameSystem = Symbol::FromSignature("TODO_TODO_TODO");
		const Symbol PhysOnCleanupDeleteList = Symbol::FromSignature("TODO_TODO_TODO");
		const Symbol PhysIsInCallback = Symbol::FromName("?PhysIsInCallback@@YA_NXZ");
		const Symbol expand_tree = Symbol::FromSignature("TODO_TODO_TODO");
		const Symbol GMEntityByIndex = Symbol::FromSignature("\x85\xC9\x0F\x84****\xE9****\xCC");
		const Symbol CBaseClient_ProcessStringCmd = Symbol::FromSignature("TODO_TODO_TODO");
		const Symbol CMultiplayRules_ClientCommandKeyValues = Symbol::FromSignature("TODO_TODO_TODO");
		const Symbol GModDataPack_GetHashFromDatatable = Symbol::FromSignature("TODO_TODO_TODO");
		const Symbol PhysFrame = Symbol::FromSignature("TODO_TODO_TODO");
#endif
#elif SYSTEM_LINUX
#ifdef ARCHITECTURE_X86
		const Symbol UTIL_Remove = Symbol::FromName("_Z11UTIL_RemoveP11CBaseEntity");
		const Symbol CCollisionEvent_ShouldFreezeContacts = Symbol::FromName("_ZN15CCollisionEvent20ShouldFreezeContactsEPP14IPhysicsObjecti");
		const Symbol PhysicsGameSystem = Symbol::FromName("_Z17PhysicsGameSystemv");
		const Symbol PhysOnCleanupDeleteList = Symbol::FromName("_Z23PhysOnCleanupDeleteListv");
		const Symbol PhysIsInCallback = Symbol::FromName("_Z16PhysIsInCallbackv");
		const Symbol expand_tree = Symbol::FromName("_ZN19IVP_OV_Tree_Manager11expand_treeEPK11IVP_OV_Node");
		const Symbol GMEntityByIndex = Symbol::FromName("_Z15GMEntityByIndexi");
		const Symbol CBaseClient_ProcessStringCmd = Symbol::FromName("_ZN11CBaseClient16ProcessStringCmdEP13NET_StringCmd");
		const Symbol CMultiplayRules_ClientCommandKeyValues = Symbol::FromName("_ZN15CMultiplayRules22ClientCommandKeyValuesEP7edict_tP9KeyValues");
		const Symbol GModAutoRefresh_HandleLuaFileChange = Symbol::FromName("_ZN9GarrysMod11AutoRefresh16HandleChange_LuaERKSsS2_S2_");
		const Symbol GModDataPack_GetHashFromDatatable = Symbol::FromName("_ZN12GModDataPack20GetHashFromDatatableEi");
		const Symbol PhysFrame = Symbol::FromName("_ZL9PhysFramef");
#elif ARCHITECTURE_X86_64
		const Symbol UTIL_Remove = Symbol::FromName("TODO_TODO_TODO");
		const Symbol CCollisionEvent_ShouldFreezeContacts = Symbol::FromName("TODO_TODO_TODO");
		const Symbol PhysicsGameSystem = Symbol::FromName("TODO_TODO_TODO");
		const Symbol PhysOnCleanupDeleteList = Symbol::FromName("TODO_TODO_TODO");
		const Symbol PhysIsInCallback = Symbol::FromName("TODO_TODO_TODO");
		const Symbol expand_tree = Symbol::FromName("TODO_TODO_TODO");
		const Symbol GMEntityByIndex = Symbol::FromSignature("\x55\x85\xFF\x48\x89\xE5\x74\x08\x5D\xE9****\x66\x90\x5D\xE9****");
		const Symbol CBaseClient_ProcessStringCmd = Symbol::FromSignature("TODO_TODO_TODO");
		const Symbol CMultiplayRules_ClientCommandKeyValues = Symbol::FromSignature("TODO_TODO_TODO");
		const Symbol GModDataPack_GetHashFromDatatable = Symbol::FromSignature("TODO_TODO_TODO");
		const Symbol PhysFrame = Symbol::FromSignature("TODO_TODO_TODO");
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
		// TODO: Use physics interface and (*(IPhysicsEnvironment) + 104) + 12 instead sigscan
		static SourceSDK::FactoryLoader server_loader("server");
		return SigResolve<CCollisionEvent_ShouldFreezeContacts_t>(server_loader, Symbols::CCollisionEvent_ShouldFreezeContacts, "CCollisionEvent::ShouldFreezeContacts");
	}

	UTIL_Remove_t UTIL_Remove()
	{
		static SourceSDK::FactoryLoader server_loader("server");
		return SigResolve<UTIL_Remove_t>(server_loader, Symbols::UTIL_Remove, "UTIL_Remove");
	}

	expand_tree_t expand_tree()
	{
		static SourceSDK::FactoryLoader vphys_loader(TYPEDIFF_WIN("vphysics", "vphysics_srv"));
		return SigResolve<expand_tree_t>(vphys_loader, Symbols::expand_tree, "IVP_OV_Tree_Manager::expand_tree");
	}

	GMEntityByIndex_t GMEntityByIndex()
	{
		static SourceSDK::FactoryLoader server_loader("server");
		return SigResolve<GMEntityByIndex_t>(server_loader, Symbols::GMEntityByIndex, "GMEntityByIndex");
	}

	CBaseClient_ProcessStringCmd_t CBaseClient_ProcessStringCmd()
	{
		static SourceSDK::FactoryLoader engine_loader("engine");
		return SigResolve<CBaseClient_ProcessStringCmd_t>(engine_loader, Symbols::CBaseClient_ProcessStringCmd, "CBaseClient::ProcessStringCmd");
	}

	CMultiplayRules_ClientCommandKeyValues_t CMultiplayRules_ClientCommandKeyValues()
	{
		static SourceSDK::FactoryLoader server_loader("server");
		return SigResolve<CMultiplayRules_ClientCommandKeyValues_t>(server_loader, Symbols::CMultiplayRules_ClientCommandKeyValues, "CMultiplayRules::ClientCommandKeyValues");
	}

	GModAutoRefresh_HandleLuaFileChange_t GModAutoRefresh_HandleLuaFileChange()
	{
		static SourceSDK::FactoryLoader server_loader("server");
		return SigResolve<GModAutoRefresh_HandleLuaFileChange_t>(server_loader, Symbols::GModAutoRefresh_HandleLuaFileChange, "GModAutoRefresh::HandleLuaFileChange");
	}
	
	GModDataPack_GetHashFromDatatable_t GModDataPack_GetHashFromDatatable()
	{
		static SourceSDK::FactoryLoader server_loader("server");
		return SigResolve<GModDataPack_GetHashFromDatatable_t>(server_loader, Symbols::GModDataPack_GetHashFromDatatable, "GModDataPack::GetHashFromDatatable");
	}

	PhysFrame_t PhysFrame()
	{
		static SourceSDK::FactoryLoader server_loader("server");
		return SigResolve<PhysFrame_t>(server_loader, Symbols::PhysFrame, "PhysFrame");
	}
}