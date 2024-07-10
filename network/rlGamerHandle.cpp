#include "rlGamerHandle.hpp"
#include "rage/datBitBuffer.hpp"

bool rage::rlGamerHandle::Serialize(rage::datBitBuffer& buf) const
{
	buf.Write<int>(m_Platform, 8);
	if (m_Platform != 3)
		return false;
	buf.Write<std::uint64_t>(m_RockstarId, 64);
	buf.Write<std::uint16_t>(m_UnkData, 16);
	return true;
}

bool rage::rlGamerHandle::Deserialize(rage::datBitBuffer& buf)
{
	m_Platform = buf.Read<int>(8);
	if (m_Platform != 3)
		return false;
	m_RockstarId = buf.Read<std::uint64_t>(64);
	m_UnkData = buf.Read<std::uint16_t>(16);
	return true;
}
