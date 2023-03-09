#pragma once
#include<vector>

#include "Constants.h"
#include "Brick.h"
#include "Ball.h"
#include "Palette.h"
#include "Events/IEvent.h"
#include "Events/IEventPublisher.h"
#include "Events/ISubscriber.h"

enum class CollisionType
{
	Palette,
	Wall,
	Ceilling,
	Brick,
	Floor,
	None
};

class CollisionEvent : public IEvent
{
public: 
	explicit CollisionEvent(CollisionType collisionType, Brick* hitBrick = nullptr);
	CollisionType collisionType;
	Brick* hitBrick;

	EventType GetType() const override;
};

class CollisionController : public IEventPublisher
{
public:
	CollisionController(Palette* palette, std::vector<Brick>* bricks, Ball* ball);
	void DetectCollissions();

	void Subscribe(std::shared_ptr<ISubscriber> subscriber) override;
	void Unsubscribe(std::shared_ptr<ISubscriber> subscriber) override;

private:
	void SendEvent(std::shared_ptr<IEvent> event) override;
	CollisionType FindCollision() const;
	Brick* FindBrickCollision() const;

	Palette* m_palette;
	std::vector<Brick>* m_bricks;
	Ball* m_ball;
	std::vector<std::shared_ptr<ISubscriber>> m_subscribers;
};


