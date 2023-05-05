#include "CollisionController.h"

CollisionEvent::CollisionEvent(CollisionType collisionType, Brick* hitBrick) : collisionType(collisionType), hitBrick(hitBrick)
{
}

EventType CollisionEvent::GetType() const
{
	return EventType::Collision;
}

CollisionController::CollisionController(Palette& palette, std::vector<Brick>& bricks, Ball& ball) : m_palette(palette), m_bricks(bricks), m_ball(ball)
{
}

void CollisionController::DetectCollissions()
{
	auto brickCollided = FindBrickCollision();
	if (brickCollided != nullptr)
	{
		auto collisionEvent = std::make_shared<CollisionEvent>(CollisionType::Brick, brickCollided);
		SendEvent(collisionEvent);
	}
	else
	{
		auto collision = FindCollision();
		auto collisionEvent = std::make_shared<CollisionEvent>(collision);
		SendEvent(collisionEvent);
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

	if (m_ball.GetY() >= m_palette.GetY() - m_palette.GetHeight()
		&& m_ball.GetX() >= m_palette.GetX() - m_ball.GetWidth() && m_ball.GetX() <= m_palette.GetX() + m_palette.GetWidth())
	{
		return CollisionType::Palette;
	}
	else if ((m_ball.GetX() <= 0) || (m_ball.GetX() + m_ball.GetWidth() >= RESOLUTION_WIDTH))
	{
		return CollisionType::Wall;
	}
	else if (m_ball.GetY() <= 0)
	{
		return CollisionType::Ceilling;
	}
	else
	{
		return CollisionType::None;
	}
}

Brick* CollisionController::FindBrickCollision() const
{
	for (auto& brick : m_bricks) {
		if (m_ball.GetX() >= brick.GetX() && m_ball.GetX() <= (brick.GetX() + brick.GetWidth())
			&& m_ball.GetY() >= brick.GetY()
			&& m_ball.GetY() <= (brick.GetY() + brick.GetHeight())
			&& brick.IsAlive())
		{
			return &brick;
		}
	}
	return nullptr;
}
