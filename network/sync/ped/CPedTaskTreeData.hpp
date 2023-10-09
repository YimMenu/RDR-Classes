#pragma once
#include <cstdint>

class CPedTaskData
{
public:
	uint32_t m_TaskType; //0x0000
	char pad_0004[16]; //0x0004
}; //Size: 0x0014
static_assert(sizeof(CPedTaskData) == 0x14);

class CPedTaskTree
{
public:
	uint32_t m_TreeType; //0x0000
	char pad_0004[4]; //0x0004 unused
	uint32_t m_NumTasks; //0x0008
	bool m_SequenceTree; //0x000C
	class CPedTaskData m_Tasks[12]; //0x0010
	char pad_0100[16]; //0x0100 unused
}; //Size: 0x0110
static_assert(sizeof(CPedTaskTree) == 0x110);

class CPedTaskTreeData
{
public:
	class CPedTaskTree m_Trees[5]; //0x0000
	char pad_0550[4]; //0x0550 unused
	uint32_t m_ScriptCommand; //0x0554
	uint32_t m_ScriptTaskStage; //0x0558

	int GetNumTaskTrees()
	{
		switch (m_Trees[0].m_TreeType)
		{
		case 0: return 5;
		case 1: return 2;
		case 2: return 0;
		case 3: return 1;
		}

		return 0;
	}
}; //Size: 0x055C
static_assert(sizeof(CPedTaskTreeData) == 0x55C);
