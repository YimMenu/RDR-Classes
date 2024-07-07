#pragma once

class CEvent
{
public:
	virtual ~CEvent() = default;
	virtual CEvent* Clone() = 0;
	virtual bool operator==(CEvent& other) = 0;
	virtual int _0x18() = 0;
	virtual float _0x20() = 0;
	virtual float _0x28() = 0;
	virtual bool IsEventScriptCommand() = 0;
	virtual bool ExtractData(void* data, int size) = 0;

	char m_pad[0x58];
};
static_assert(sizeof(CEvent) == 0x60);