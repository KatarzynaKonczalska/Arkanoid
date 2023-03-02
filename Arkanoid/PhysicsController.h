#pragma once
#include "Events/ISubscriber.h"

class PhysicsController : public ISubscriber
{
public: 
	PhysicsController() = default;

	void OnEvent(std::shared_ptr<IEvent> event) override;
};

