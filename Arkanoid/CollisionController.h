#pragma once
#include<vector>

#include "Brick.h"
#include "Palette.h"
#include "Events/IEvent.h"
#include "Events/IEventPublisher.h"
#include "Events/ISubscriber.h"

enum class CollisionType
{
	Wall,
	Ceilling,
	Brick,
	Floor
};

class CollisionEvent : public IEvent
{
public: 
	CollisionType collisionType;
};

class CollisionController : public IEventPublisher
{
public:
	CollisionController(Palette* Palette, std::vector<Brick>* bricks);
	void Subscribe(std::shared_ptr<ISubscriber> subscriber) override;
	void Unsubscribe(std::shared_ptr<ISubscriber> subscriber) override;
	void SendEvent(std::shared_ptr<IEvent> event) override;

private:
	Palette* m_palette;
	std::vector<Brick>* m_bricks;
	std::vector<std::shared_ptr<ISubscriber>> m_subscribers;
};

//typy kolizji: pilka z paletka, pilka ze sciana, pilka z podloga, pilka z brick
// zmiana kierunku: pilka z paletka, pilka ze sciana
// przegrana: pilka z podloga
// punkt: pilka z brick

