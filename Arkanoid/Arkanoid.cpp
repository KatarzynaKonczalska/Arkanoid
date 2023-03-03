#include <iostream>
#include <vector>
#include <algorithm>

#include "Constants.h"
#include "Level.h"
#include "RenderingController.h"
#include "CollisionController.h"
#include "PhysicsController.h"

//3rd party
#include <SDL2/SDL.h>
#undef main

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	auto window = SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, RESOLUTION_WIDTH, RESOLUTION_HEIGHT, 0);
	auto renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Event e;

	enum Direction
	{
		DOWN,
		LEFT,
		RIGHT,
		UP
	};

	auto level = Level(AvailableLevel::Level1);
	Palette* palette = level.GetPalettePtr();
	std::vector<Brick>* bricks = level.GetBricksPtr();
	Ball* ball = level.GetBallPtr();

	auto renderingController = RenderingController(renderer);
	auto collisionController = CollisionController(palette, bricks, ball);
	auto physicsController = PhysicsController(palette, ball);

	collisionController.Subscribe(std::make_shared<PhysicsController>(physicsController));

	bool running = true;
	int dir = 0;

	while (running)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT) { running = false; }
			if (e.type == SDL_KEYDOWN) {
				if (e.key.keysym.sym == SDLK_RIGHT) { dir = RIGHT; }
				if (e.key.keysym.sym == SDLK_LEFT) { dir = LEFT; }
			}
		}

		switch (dir)
		{
		case LEFT:
			level.MovePalette(-5); break;
		case RIGHT:
			level.MovePalette(5); break;
		}

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


