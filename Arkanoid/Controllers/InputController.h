#pragma once
#include <vector>

#include "../Events/IEventPublisher.h"
#include <SDL2/SDL_events.h>

enum class InputType
{
	Left,
	Right,
	None
};

class InputEvent : public IEvent
{
public:
	explicit InputEvent(InputType inputType);
	InputType inputType;

	EventType GetType() const override;
};

class InputController : public IEventPublisher
{
public:
	void Subscribe(std::shared_ptr<ISubscriber> subscriber) override;
	void Unsubscribe(std::shared_ptr<ISubscriber> subscriber) override;
	void HandleUserInput();
private:
	void SendEvent(std::shared_ptr<IEvent> event) override;
	InputEvent CheckForInputs();

	SDL_Event m_event;
	std::vector<std::shared_ptr<ISubscriber>> m_subscribers;
};

