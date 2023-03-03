#pragma once

enum class EventType
{
	Collision
};

class IEvent
{
public:
	virtual EventType GetType() const = 0;
};

