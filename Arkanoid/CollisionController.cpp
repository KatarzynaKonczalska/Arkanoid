#include "CollisionController.h"

CollisionEvent::CollisionEvent(CollisionType collisionType) : collisionType(collisionType)
{
}

CollisionController::CollisionController(Palette* palette, std::vector<Brick>* bricks, Ball* ball) : m_palette(palette), m_bricks(bricks), m_ball(ball)
{
}

void CollisionController::DetectCollissions()
{
	auto collision = FindCollision();
	if (collision != CollisionType::None)
	{
		auto collisionEvent = CollisionEvent(collision);
		SendEvent(std::make_shared<CollisionEvent>(collisionEvent));
	}
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

CollisionType CollisionController::FindCollision() const
{
	if (m_ball->GetY() >= m_palette->GetY() - m_palette->GetHeight()
		&& m_ball->GetX() >= m_palette->GetX() - m_ball->GetWidth() && m_ball->GetX() <= m_palette->GetX() + m_palette->GetWidth())
	{
		return CollisionType::Palette;
	}
	else if ((m_ball->GetX() <= 0) || (m_ball->GetX() + m_ball->GetWidth() >= RESOLUTION_WIDTH))
	{
		return CollisionType::Wall;
	}
	if (m_ball->GetY() <= 0)
	{
		return CollisionType::Ceilling;
	}
	else
	{
		return CollisionType::None;
	}
}
