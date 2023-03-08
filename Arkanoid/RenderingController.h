#pragma once
#include <SDL2/SDL.h>
#include "Level.h"
#include "Constants.h"

class RenderingController
{
public:
	explicit RenderingController();
	void RenderLevel(Level const& level);

private:
	SDL_Renderer* m_renderer;
	SDL_Window* m_window;
};

