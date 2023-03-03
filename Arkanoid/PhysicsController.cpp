#include "PhysicsController.h"
#include <iostream>

PhysicsController::PhysicsController(Palette* palette, Ball* ball) : m_palette(palette), m_ball(ball)
{
}

void PhysicsController::BallMovement()
{
	m_ball->Move();
}

void PhysicsController::OnEvent(std::shared_ptr<IEvent> event)
{
	if (event->GetType() == EventType::Collision)
	{
		auto collisionEvent = std::static_pointer_cast<CollisionEvent>(event);
		ManageCollision(collisionEvent);
	}
	else
	{
		std::cout << "Incorrect event type. \n";
	}
}

void PhysicsController::ManageCollision(std::shared_ptr<CollisionEvent> collisionEvent)
{
	switch (collisionEvent->collisionType)
	{
	case CollisionType::Wall:
		m_ball->ChangeDirection(true, false);
		break;
	case CollisionType::Palette:
		m_ball->ChangeDirection(false, true);
		break;
	case CollisionType::Ceilling:
		m_ball->ChangeDirection(false, true);
		break;
	case CollisionType::Brick:
		m_ball->ChangeDirection(true, true);
		break;
	default:
		break;
	}
}

