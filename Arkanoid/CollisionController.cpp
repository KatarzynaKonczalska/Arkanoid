#include "CollisionController.h"

CollisionController::CollisionController(Palette* palette, std::vector<Brick>* bricks) : m_palette(palette), m_bricks(bricks)
{
}

void CollisionController::Subscribe(std::shared_ptr<ISubscriber> subscriber)
{
	m_subscribers.emplace_back(subscriber);
}

void CollisionController::Unsubscribe(std::shared_ptr<ISubscriber> subscriber)
{
	m_subscribers.push_back(subscriber);
}

void CollisionController::SendEvent(std::shared_ptr<IEvent> event)
{
	for (auto subscriber : m_subscribers)
	{
		subscriber->OnEvent(event);
	}
}
