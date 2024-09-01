#pragma once

class CAnimSceneSerializedVariable
{
public:
	enum class Type
	{
		Bool = 5,
		Float = 10,
		Int = 19
	};

	std::uint32_t m_VariableName;
	Type m_Type;
	union
	{
		int m_Int;
		bool m_Bool;
		float m_Float;
	};
};
static_assert(sizeof(CAnimSceneSerializedVariable) == 0xC);

class CAnimSceneSerializedEntityBase
{
public:
	virtual void Serialize(void*) {};
	virtual void Reset() {};

	std::uint32_t m_EntityName;
	bool m_TransferOwnership;
};
static_assert(sizeof(CAnimSceneSerializedEntityBase) == 0x10);

class CAnimSceneSerializedEntity : public CAnimSceneSerializedEntityBase
{
public:
	std::uint16_t m_ObjectId;
	bool m_Abort;
};
static_assert(sizeof(CAnimSceneSerializedEntity) == 0x18);

class CAnimSceneSerializedDoor : public CAnimSceneSerializedEntityBase
{
public:
	std::uint32_t m_DoorHash;
};
static_assert(sizeof(CAnimSceneSerializedDoor) == 0x18);

class CAnimSceneSerializedPlaybackList
{
public:
	virtual void Serialize(void*) {};
	virtual void Reset() {};

	std::uint32_t m_PlaybackList;
	float m_Time;
};
static_assert(sizeof(CAnimSceneSerializedPlaybackList) == 0x10);

class CAnimSceneInfrequentData
{
public:
	std::uint16_t m_NumEntities;
	std::uint16_t m_NumDoors;
	std::uint16_t m_NumVariables;
	std::uint16_t m_NumPlaybackLists;
	char m_Pad[0x50]; // origin, rotation, scene attachments
	CAnimSceneSerializedEntity m_Entities[32];
	CAnimSceneSerializedDoor m_Doors[5];
	CAnimSceneSerializedVariable m_Variables[32];
	CAnimSceneSerializedPlaybackList m_PlaybackLists[9];
}; //Size: 0x05E0
static_assert(sizeof(CAnimSceneInfrequentData) == 0x5E0);