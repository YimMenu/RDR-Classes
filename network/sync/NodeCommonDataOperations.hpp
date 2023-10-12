#pragma once

namespace rage
{
	class datBitBuffer;
}

class NodeCommonDataOperations
{
public:
	virtual ~NodeCommonDataOperations() = default;
	virtual void ReadFromBuffer(rage::datBitBuffer* buffer, void* log) {};                              // 0x08
	virtual void WriteToBuffer(void* data_base, rage::datBitBuffer* buffer, void* log, bool cache) {};  // 0x10
	virtual void Unk() {};                                                                              // 0x18
	// TODO:
	virtual int CalculateSize(rage::datBitBuffer* buffer) { return 0; };                                // 0x20
	virtual int CalculateSize2(rage::datBitBuffer* buffer) { return 0; };                               // 0x28
	virtual void LogSyncData(rage::datBitBuffer* buffer) {};                                            // 0x30
	virtual void LogSyncData2(rage::datBitBuffer* buffer) {};                                           // 0x38
	rage::datBitBuffer* m_Buffer; // 0x8
};
static_assert(sizeof(NodeCommonDataOperations) == 0x10);