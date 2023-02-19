#include "RenderingController.h"

RenderingController::RenderingController(SDL_Renderer* renderer)
{
	m_renderer = renderer;
}

void RenderingController::RenderLevel(Level level)
{
	std::vector<RenderableObject> objects = level.GetObjectsToRender();
	for_each(objects.begin(), objects.end(), [&](auto& object)
		{
			SDL_Rect rect = { object.x, object.y, object.w, object.h };
			SDL_RenderFillRect(m_renderer, &rect);
		});
}
