#pragma once

class CEvent;
class CEventGroup
{
public:
	virtual ~CEventGroup() = default;
	virtual void AddEvent(CEvent* event, bool) = 0;
	virtual void Cleanup() = 0;
	virtual int GetEventGroupType() = 0;
};

class CEventGroupNetwork : public CEventGroup
{
};