#ifndef SCANADV_ADVPROXY
#define SCANADV_ADVPROXY

#ifdef SYSTEM_WINDOWS
	#pragma once
#endif

#include <detouring/classproxy.hpp>
#include <functional>

struct _VTable
{
	size_t size = 0;
	void** pointer = nullptr;
	Detouring::CacheMap cache;
};

class __vtable_SharedState
{
public:
	_VTable target_vtable;
	std::vector<void*> original_vtable;
	_VTable substitute_vtable;
	Detouring::HookMap hooks;
};

typedef std::shared_ptr<__vtable_SharedState>(*func_GetSharedState)(const bool create_if_needed);

namespace ScanningAdvanced {
	template<typename Target, typename Substitute>
	class ClassProxyAdv : public Detouring::ClassProxy<Target, Substitute>
	{
	protected:
		ClassProxyAdv() : ClassProxy()
		{
			InitHookAccessor();
		}

		ClassProxyAdv(Target* instance) : ClassProxy(instance)
		{
			InitHookAccessor();
		}

		virtual ~ClassProxyAdv() = default;

	public:
		template<typename Definition>
		bool EnableHook(Definition original)
		{
			void* address = reinterpret_cast<void*>(original);
			if (address == nullptr)
				return false;

			const auto it = adv_shared_state->hooks.find(address);
			if (it != adv_shared_state->hooks.end())
				return it->second.Enable();

			return false;
		}

		template<typename Definition>
		bool DisableHook(Definition original)
		{
			void* address = reinterpret_cast<void*>(original);
			if (address == nullptr)
				return false;

			const auto it = adv_shared_state->hooks.find(address);
			if (it != adv_shared_state->hooks.end())
				return it->second.Disable();

			return false;
		}

		template<typename Definition>
		bool HookIsEnabled(Definition original)
		{
			void* address = reinterpret_cast<void*>(original);
			if (address == nullptr)
				return false;

			const auto it = adv_shared_state->hooks.find(address);
			if (it != adv_shared_state->hooks.end())
				return it->second.IsEnabled();

			return false;
		}

	private:
		// Dirty hack to catch SharedState while waiting methods from danielga
		void InitHookAccessor()
		{
			bool (*InitializeFunc)(Target*, Substitute*) = &ClassProxyAdv::Initialize;
			uint8_t* ptr = reinterpret_cast<uint8_t*>(std::addressof(*InitializeFunc));

			// Initialize is tailcall, so just check for JMP
			if (*reinterpret_cast<uint8_t*>(ptr) != 0xE9)
				return;

			uint32_t jmp_offset = *reinterpret_cast<int32_t*>(ptr + 1);
			ptr += static_cast<int32_t>(jmp_offset) + 5;

			// search for first CALL (GetSharedState)
			for (uint8_t offset = 0; offset < 64; offset++)
			{
				uint8_t byte = *(ptr + offset);
				if (byte != 0xE8) continue;

				uint32_t call_offset = *reinterpret_cast<int32_t*>(ptr + offset + 1);
				uintptr_t getstate_addr = reinterpret_cast<uintptr_t>(ptr + offset + 5 + static_cast<int32_t>(call_offset));

				adv_shared_state = reinterpret_cast<func_GetSharedState>(getstate_addr)(true);
			}
		}

	public:
		std::shared_ptr<__vtable_SharedState> adv_shared_state;
	};
}

#endif