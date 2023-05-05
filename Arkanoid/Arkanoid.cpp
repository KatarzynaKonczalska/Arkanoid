#include <iostream>
#include <vector>
#include <algorithm>

#include "Constants.h"
#include "Level.h"
#include "Controllers/RenderingController.h"
#include "Controllers/CollisionController.h"
#include "Controllers/PhysicsController.h"
#include "Controllers/InputController.h"
#include "Config/UserConfig.h"

#undef main

int main()
{
	auto userConfig = UserConfig();

	auto level = Level(AvailableLevel::Level1);
	Palette& palette = level.GetPaletteRef();
	std::vector<Brick>& bricks = level.GetBricksRef();
	Ball& ball = level.GetBallRef();
	int score = 0;

	auto renderingController = RenderingController(userConfig);
	auto collisionController = CollisionController(palette, bricks, ball);
	auto physicsController = PhysicsController(palette, ball, bricks);
	auto inputController = InputController();

	collisionController.Subscribe(std::make_shared<PhysicsController>(physicsController));
	inputController.Subscribe(std::make_shared<PhysicsController>(physicsController));

	bool running = true;

	while (running)
	{
		inputController.HandleUserInput();
		collisionController.DetectCollissions();
		//physicsController.Move();
		renderingController.RenderLevel(level, score);
	}

	return 0;
}


