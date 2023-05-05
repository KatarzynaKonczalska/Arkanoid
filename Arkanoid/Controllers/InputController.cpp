#include "InputController.h"

EventType InputEvent::GetType() const
{
	return EventType::Input;
}

InputEvent::InputEvent(InputType inputType) : inputType(inputType)
{
}

void InputController::Subscribe(std::shared_ptr<ISubscriber> subscriber)
{
	m_subscribers.emplace_back(subscriber);
}

void InputController::Unsubscribe(std::shared_ptr<ISubscriber> subscriber)
{
	m_subscribers.push_back(subscriber);
}

void InputController::HandleUserInput()
{
	auto inputEvent = CheckForInputs();
	if (inputEvent.inputType != InputType::None)
	{
		SendEvent(std::make_shared<InputEvent>(inputEvent));
	}
}

void InputController::SendEvent(std::shared_ptr<IEvent> event)
{
	for (auto subscriber : m_subscribers)
	{
		subscriber->OnEvent(event);
	}
}

InputEvent InputController::CheckForInputs()
{
	while (SDL_PollEvent(&m_event))
	{
		if (m_event.type == SDL_KEYDOWN)
		{
			if (m_event.key.keysym.sym == SDLK_RIGHT) { return InputEvent(InputType::Right); }
			if (m_event.key.keysym.sym == SDLK_LEFT) { return InputEvent(InputType::Left); }
			else { return InputEvent(InputType::None); }
		}
	}
	return InputEvent(InputType::None);
}
