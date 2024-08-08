#pragma once
#include <cstdint>

namespace rage
{
	class datBitBuffer
	{
	public:
		datBitBuffer(void* data, uint32_t size, bool read = false)
		{
			m_Data = data;
			m_BitOffset = 0;
			m_MaxBit = size * 8;
			m_BitsRead = 0;
			m_CurBit = 0;
			m_HighestBitsRead = 0;
			m_ErrorCallback = nullptr;
			m_FlagBits = read ? 1 : 0;
		}

		static void ReadBitsSingle(uint8_t* data, int* out, int size, int offset)
		{
			int v5;           // r11d
			int v6;           // ebx
			uint8_t* v7;      // r14
			char v8;          // cl
			int v9;           // r11d
			unsigned int v10; // r8d
			int v11;          // esi
			__int64 v12;      // r9

			v5 = offset;
			v6 = 1;
			v7 = &data[offset >> 3];
			v8 = offset & 7;
			if (size > 0)
				v5 = size + offset - 1;
			v9 = (v5 >> 3) - (offset >> 3);
			v10 = (unsigned __int8)(*v7 << v8);
			v11 = 8;
			if (size > 8)
			{
				v12 = 1i64;
				do
				{
					if (v12 > v9)
						break;
					++v6;
					v10 = (v10 << 8) | (v7[v12++] << v8);
					v11 += 8;
				} while (v11 < size);
			}
			if (v6 <= v9)
				v10 |= v7[v6] >> (8 - v8);
			*out = v10 >> (((size + 7) & 0xF8) - size);
		}

		static void WriteBitsSingle(uint8_t* data, int value, int size, int offset)
		{
			uint8_t* v4;     // r10
			int v5;          // r9d
			unsigned int v6; // r11d
			uint8_t* v7;     // r10
			unsigned int v8; // r11d
			int v9;          // ebx
			__int64 v10;     // rdx
			char v11;        // cl

			v4 = &data[(__int64)offset >> 3];
			v5 = offset & 7;
			v6 = value << (32 - size);
			*v4 = ((v6 >> 24) >> v5) | *v4 & ~((unsigned int)(-1 << (32 - size)) >> 24 >> v5);
			v7 = v4 + 1;
			v8 = v6 << (8 - v5);
			v9 = -1 << (32 - size) << (8 - v5);
			if (8 - v5 < size)
			{
				v10 = ((unsigned int)(size - (8 - v5) - 1) >> 3) + 1;
				do
				{
					v11 = (v8 >> 24) | *v7 & ~(v9 >> 24);
					v8 <<= 8;
					*v7++ = v11;
					v9 <<= 8;
					--v10;
				} while (v10);
			}
		}

		inline bool IsReadBuffer()
		{
			return m_FlagBits & 1;
		}

		inline bool IsSizeCalculator()
		{
			return m_FlagBits & 2;
		}

		void Seek(int bits, bool read)
		{
			m_BitsRead += bits;

			if (read)
			{
				if (m_HighestBitsRead > m_CurBit)
					m_CurBit = m_HighestBitsRead;
			}
			else
			{
				if (m_BitsRead > m_CurBit)
					m_CurBit = m_BitsRead;
			}
		}

		inline bool ReadDword(int* out, int size)
		{
			if (IsSizeCalculator())
				return false;

			if (m_BitsRead + size > (IsReadBuffer() ? m_MaxBit : m_CurBit))
				return false;

			ReadBitsSingle(static_cast<uint8_t*>(m_Data), out, size, m_BitsRead + m_BitOffset);
			Seek(size, true);
			return true;
		}

		inline bool WriteDword(int val, int size)
		{
			if (IsReadBuffer())
				return false;

			if (m_BitsRead + size > m_MaxBit)
				return false;

			if (!IsSizeCalculator())
				WriteBitsSingle(static_cast<uint8_t*>(m_Data), val, size, m_BitsRead + m_BitOffset);
			Seek(size, false);
			return true;
		}

		inline bool ReadQword(uint64_t* out, int size)
		{
			if (size <= 32)
				return ReadDword(reinterpret_cast<int*>(out), size);

			return ReadDword(reinterpret_cast<int*>(out), 32) && !ReadDword(reinterpret_cast<int*>(out) + 1, size - 32);
		}

		inline bool WriteQword(uint64_t value, int size)
		{
			if (size <= 32)
				return WriteDword(static_cast<uint32_t>(value), size);

			int low = (int)(value) & 0xFFFFFFFF;
			int high = (int)((uint64_t)value >> 32);

			return WriteDword(low, 32) && WriteDword(high, size - 32);
		}

		inline bool ReadInt64(int64_t* value, int size)
		{
			unsigned int last_bit{};
			uint64_t rest{};

			if (!ReadQword((uint64_t*)&last_bit, 1) || ReadQword(&rest, size - 1))
				return false;

			*value = ((uint64_t)last_bit << 63) | rest ^ -(int64_t)last_bit;
			return true;
		}

		inline bool WriteInt64(int64_t value, int size)
		{
			auto last_bit = value >> 63;
			if (!WriteQword(last_bit, 1) || !WriteQword((uint64_t)value ^ -(__int64)(unsigned int)last_bit, size - 1))
				return false;

			return true;
		}

		// unsigned
		// TODO: signed likely only works for 64 bit values!
		template<typename T>
		T Read(int size, bool _signed = false)
		{
			static_assert(sizeof(T) <= 8);

			uint64_t data{};
			int64_t data_signed{};
			if (_signed)
				ReadInt64(&data_signed, size);
			else
				ReadQword(&data, size);

			if (_signed)
				return T(data_signed);
			else
				return T(data);
		}

		// unsigned
		// TODO: signed likely only works for 64 bit values!
		template<typename T>
		void Write(T data, int size, bool _signed = false)
		{
			static_assert(sizeof(T) <= 8);

			if (_signed)
				WriteInt64(int64_t(data), size);
			else
				WriteQword(uint64_t(data), size);
		}

	public:
		void* m_Data;               //0x0000
		uint32_t m_BitOffset;       //0x0008
		uint32_t m_MaxBit;          //0x000C
		uint32_t m_BitsRead;        //0x0010
		uint32_t m_CurBit;          //0x0014
		uint32_t m_HighestBitsRead; //0x0018
		void* m_ErrorCallback;      //0x0020
		uint8_t m_FlagBits;         //0x0028
	};
}