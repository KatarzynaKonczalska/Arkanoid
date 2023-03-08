#pragma once
#include "Palette.h"
#include "Ball.h"
#include "Events/ISubscriber.h"
#include "CollisionController.h"
#include "InputController.h"

class PhysicsController : public ISubscriber
{
public: 
	PhysicsController(Palette* palette, Ball* ball);
	void Move();
	void OnEvent(std::shared_ptr<IEvent> event) override;

private:
	void ManageCollision(std::shared_ptr<CollisionEvent> collisionEvent);
	void ManageInput(std::shared_ptr<InputEvent> inputEvent);

	Palette* m_palette;
	Ball* m_ball;
};

