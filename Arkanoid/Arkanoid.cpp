#include <iostream>
#include <vector>
#include <algorithm>

#include "Constants.h"
#include "Level.h"
#include "RenderingController.h"
#include "CollisionController.h"
#include "PhysicsController.h"
#include "InputController.h"

//3rd party
#include <SDL2/SDL.h>
#undef main

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	auto window = SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, RESOLUTION_WIDTH, RESOLUTION_HEIGHT, 0);
	auto renderer = SDL_CreateRenderer(window, -1, 0);

	auto level = Level(AvailableLevel::Level1);
	Palette* palette = level.GetPalettePtr();
	std::vector<Brick>* bricks = level.GetBricksPtr();
	Ball* ball = level.GetBallPtr();

	auto renderingController = RenderingController(renderer);
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
		physicsController.BallMovement();

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		renderingController.RenderLevel(level);

		SDL_RenderPresent(renderer);
		SDL_Delay(25);
	}

	return 0;
}


