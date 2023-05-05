#pragma once
#include <memory>
#include <iostream>
#include "CollisionController.h"
#include "../Events/IEvent.h"
#include "InputController.h"

class GameStateController : public ISubscriber
{
public:
	explicit GameStateController(int score=0);
	void OnEvent(std::shared_ptr<IEvent> event) override;
	int GetScore() const;

private:
	void ManageCollision(std::shared_ptr<CollisionEvent> collisionEvent);
	void ManageInput(std::shared_ptr<InputEvent> inputEvent);
	int m_score;
};

