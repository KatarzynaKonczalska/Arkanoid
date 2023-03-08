#include "PhysicsController.h"
#include <iostream>

PhysicsController::PhysicsController(Palette* palette, Ball* ball) : m_palette(palette), m_ball(ball)
{
}

void PhysicsController::Move()
{
	m_ball->Move();
	m_palette->Move();
}

void PhysicsController::OnEvent(std::shared_ptr<IEvent> event)
{
	if (event->GetType() == EventType::Collision)
	{
		auto collisionEvent = std::static_pointer_cast<CollisionEvent>(event);
		ManageCollision(collisionEvent);
	}
	if (event->GetType() == EventType::Input)
	{
		auto inputEvent = std::static_pointer_cast<InputEvent>(event);
		ManageInput(inputEvent);
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

void PhysicsController::ManageInput(std::shared_ptr<InputEvent> inputEvent)
{
	switch (inputEvent->inputType)
	{
	case InputType::Left:
		m_palette->ChangeDirection(PaletteDirection::Left);
		break; 
	case InputType::Right:
		m_palette->ChangeDirection(PaletteDirection::Right);
		break;
	default:
		break;
	}
}



