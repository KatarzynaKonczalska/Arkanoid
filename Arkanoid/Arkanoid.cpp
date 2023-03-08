#include <iostream>
#include <vector>
#include <algorithm>

#include "Constants.h"
#include "Level.h"
#include "RenderingController.h"
#include "CollisionController.h"
#include "PhysicsController.h"
#include "InputController.h"

#undef main

int main()
{
	auto level = Level(AvailableLevel::Level1);
	Palette* palette = level.GetPalettePtr();
	std::vector<Brick>* bricks = level.GetBricksPtr();
	Ball* ball = level.GetBallPtr();

	auto renderingController = RenderingController();
	auto collisionController = CollisionController(palette, bricks, ball);
	auto physicsController = PhysicsController(palette, ball);
	auto inputController = InputController();

	collisionController.Subscribe(std::make_shared<PhysicsController>(physicsController));
	inputController.Subscribe(std::make_shared<PhysicsController>(physicsController));

	bool running = true;

	while (running)
	{
		inputController.HandleUserInput();
		collisionController.DetectCollissions();
		physicsController.Move();
		renderingController.RenderLevel(level);
	}

	return 0;
}


