#pragma once
#include <SDL2/SDL.h>
#include "Level.h"

class RenderingController
{
public:
	explicit RenderingController(SDL_Renderer* renderer);
	void RenderLevel(Level const& level);

private:
	SDL_Renderer* m_renderer;
};

