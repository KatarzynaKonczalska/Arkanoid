#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include "Level.h"
#include "Constants.h"
#include "Config/UserConfig.h"

class RenderingController
{
public:
	explicit RenderingController(UserConfig& userConfig);
	void RenderLevel(Level const& level, int score);

private:
	UserConfig& userConfig;
	SDL_Renderer* m_renderer;
	SDL_Window* m_window;
	TTF_Font* m_font;

	void DisplayScore(int score);
	void LoadFonts();
};

