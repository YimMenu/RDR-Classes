#pragma once

class CEvent
{
public:
	virtual ~CEvent() = default;
	virtual CEvent* Clone() { return nullptr; }
	virtual bool operator==(CEvent& other) { return false; }
	virtual int _0x18() { return 0; }
	virtual float _0x20() { return 0.0f; }
	virtual float _0x28() { return 0.0f; }
	virtual bool IsEventScriptCommand() { return false; }
	virtual bool ExtractData(void* data, int size) { return false; }

	char m_pad[0x58];
};
static_assert(sizeof(CEvent) == 0x60);