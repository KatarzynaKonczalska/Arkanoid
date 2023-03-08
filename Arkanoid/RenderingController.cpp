#include "RenderingController.h"

RenderingController::RenderingController()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	m_window = SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, RESOLUTION_WIDTH, RESOLUTION_HEIGHT, 0);
	m_renderer = SDL_CreateRenderer(m_window, -1, 0);
}

void RenderingController::RenderLevel(Level const& level)
{
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_renderer);

	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);

	std::vector<RenderableObject> objects = level.GetObjectsToRender();
	for_each(objects.begin(), objects.end(), [&](auto& object)
		{
			SDL_Rect rect = { object.x, object.y, object.w, object.h };
			SDL_RenderFillRect(m_renderer, &rect);
		});
	SDL_RenderPresent(m_renderer);
	SDL_Delay(25);
}


