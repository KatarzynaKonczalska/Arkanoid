#pragma once
#include "Palette.h"
#include "Ball.h"
#include "Events/ISubscriber.h"
#include "CollisionController.h"

class PhysicsController : public ISubscriber
{
public: 
	PhysicsController(Palette* palette, Ball* ball);
	void BallMovement();
	void OnEvent(std::shared_ptr<IEvent> event) override;

private:
	void ManageCollision(std::shared_ptr<CollisionEvent> event);

	Palette* m_palette;
	Ball* m_ball;
};

