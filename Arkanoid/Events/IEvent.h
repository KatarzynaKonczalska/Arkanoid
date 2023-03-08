#pragma once

enum class EventType
{
	Collision,
	Input
};

class IEvent
{
public:
	virtual EventType GetType() const = 0;
};

