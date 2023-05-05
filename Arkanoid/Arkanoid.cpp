#include <iostream>
#include <vector>
#include <algorithm>

#include "Constants.h"
#include "Level.h"
#include "Controllers/RenderingController.h"
#include "Controllers/CollisionController.h"
#include "Controllers/PhysicsController.h"
#include "Controllers/InputController.h"
#include "Controllers/GameStateController.h"
#include "Config/UserConfig.h"

#undef main

int main()
{
	auto userConfig = UserConfig();

	auto level = Level(AvailableLevel::Level1);
	Palette& palette = level.GetPaletteRef();
	std::vector<Brick>& bricks = level.GetBricksRef();
	Ball& ball = level.GetBallRef();

	auto renderingController = RenderingController(userConfig);
	auto collisionController = CollisionController(palette, bricks, ball);
	auto physicsController = std::make_shared<PhysicsController>(palette, ball, bricks);

	auto inputController = InputController();
	auto gameStateController = std::make_shared<GameStateController>();

	collisionController.Subscribe(physicsController);
	inputController.Subscribe(physicsController);
	collisionController.Subscribe(gameStateController);
	inputController.Subscribe(gameStateController);

	bool running = true;

	while (running)
	{
		inputController.HandleUserInput();
		collisionController.DetectCollissions();
		renderingController.RenderLevel(level, gameStateController->GetScore());
	}

	return 0;
}


