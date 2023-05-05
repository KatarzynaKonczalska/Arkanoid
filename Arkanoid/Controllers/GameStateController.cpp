#include "GameStateController.h"

GameStateController::GameStateController(int score) : m_score(score)
{
}

void GameStateController::OnEvent(std::shared_ptr<IEvent> event)
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
}

int GameStateController::GetScore() const
{
	//std::cout << "This m_score " << m_score;
	return this->m_score;
}

void GameStateController::ManageCollision(std::shared_ptr<CollisionEvent> collisionEvent)
{
	if (collisionEvent->collisionType == CollisionType::Brick)
	{
		m_score++;
		std::cout << m_score << "\n";
	}
}

void GameStateController::ManageInput(std::shared_ptr<InputEvent> inputEvent)
{
	//TODO
}
