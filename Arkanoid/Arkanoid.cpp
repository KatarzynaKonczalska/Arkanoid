#include <iostream>
#include <vector>
#include <algorithm>

#include "Level.h"
#include "RenderingController.h"
#include "CollisionController.h"

//3rd party
#include <SDL2/SDL.h>
#undef main

#define RESOLUTION_WIDITH 700
#define RESOLUTION_HEIGHT 600

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	auto window = SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, RESOLUTION_WIDITH, RESOLUTION_HEIGHT, 0);
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

	auto rc = RenderingController(renderer);
	auto cc = CollisionController(palette, bricks);

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

		//ball movement
		//ball.x += ball_dir_x;
		//ball.y += ball_dir_y;

		//collisions ball <> palette
		//if (ball.y >= palette.y - palette.h
		//	&& ball.x >= palette.x - ball.w && ball.x <= palette.x + palette.w)
		//{
		//	ball_dir_x *= (-1);
		//	ball_dir_y *= (-1);
		//}

		//left wall
		//if (ball.x <= 0)
		//{
		//	ball_dir_x *= (-1);
		//}

		////right wall
		//if (ball.x + ball.w >= RESOLUTION_WIDITH)
		//{
		//	ball_dir_x *= (-1);
		//}

		////up wall
		//if (ball.y <= 0)
		//{
		//	ball_dir_y *= (-1);
		//}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		rc.RenderLevel(level);

		SDL_RenderPresent(renderer);
		SDL_Delay(25);
	}

	return 0;
}


