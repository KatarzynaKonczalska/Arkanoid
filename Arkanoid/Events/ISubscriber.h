#pragma once
#include <memory>

#include "IEvent.h"

class ISubscriber
{
public:
	virtual void OnEvent(std::shared_ptr<IEvent> event) = 0;
};

