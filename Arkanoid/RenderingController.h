#pragma once
#include <SDL2/SDL.h>
#include "Level.h"

class RenderingController
{
public:
	RenderingController(SDL_Renderer* renderer);
	void RenderLevel(Level level);

private:
	SDL_Renderer* m_renderer;
};

