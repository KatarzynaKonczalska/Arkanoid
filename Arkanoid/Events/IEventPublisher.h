#pragma once
#include<memory>

#include "ISubscriber.h"
#include "IEvent.h"


class IEventPublisher
{
public:
	virtual ~IEventPublisher() = default;
	virtual void Subscribe(std::shared_ptr<ISubscriber> subscriber) = 0;
	virtual void Unsubscribe(std::shared_ptr<ISubscriber> subscriber) = 0;
private:
	virtual void SendEvent(std::shared_ptr<IEvent> event) = 0;
};

