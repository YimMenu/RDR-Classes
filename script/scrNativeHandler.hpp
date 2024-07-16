#pragma once
#include <cstddef>
#include <cstdint>
#include <utility>

namespace rage
{
	class scrNativeCallContext
	{
	public:
		constexpr void reset()
		{
			m_ArgCount = 0;
			m_DataCount = 0;
		}

		template <typename T>
		constexpr void PushArg(T&& value)
		{
			static_assert(sizeof(T) <= sizeof(std::uint64_t));
			*reinterpret_cast<std::remove_cv_t<std::remove_reference_t<T>>*>(reinterpret_cast<std::uint64_t*>(m_Args) + (m_ArgCount++)) = std::forward<T>(value);
		}

		template <typename T>
		constexpr T& GetArg(std::size_t index)
		{
			static_assert(sizeof(T) <= sizeof(std::uint64_t));
			return *reinterpret_cast<T*>(reinterpret_cast<std::uint64_t*>(m_Args) + index);
		}

		template <typename T>
		constexpr void SetArg(std::size_t index, T&& value)
		{
			static_assert(sizeof(T) <= sizeof(std::uint64_t));
			*reinterpret_cast<std::remove_cv_t<std::remove_reference_t<T>>*>(reinterpret_cast<std::uint64_t*>(m_Args) + index) = std::forward<T>(value);
		}

		template <typename T>
		constexpr T* GetReturnValue()
		{
			return reinterpret_cast<T*>(m_ReturnValue);
		}

		template <typename T>
		constexpr void SetReturnValue(T&& value)
		{
			*reinterpret_cast<std::remove_cv_t<std::remove_reference_t<T>>*>(m_ReturnValue) = std::forward<T>(value);
		}
	protected:
		void* m_ReturnValue;
		std::uint32_t m_ArgCount;
		void* m_Args;
		std::int32_t m_DataCount;
		std::uint32_t m_Data[48];
	};
	static_assert(sizeof(scrNativeCallContext) == 0xE0);

	using scrNativeHash = std::int64_t;
	using scrNativePair = std::pair<scrNativeHash, scrNativeHash>;
	using scrNativeHandler = void(*)(scrNativeCallContext*);
}