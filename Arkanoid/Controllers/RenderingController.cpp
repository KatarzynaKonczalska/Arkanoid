#include "RenderingController.h"

RenderingController::RenderingController(UserConfig& userConfig) : m_userConfig(userConfig)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init(); 

	m_window = SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, RESOLUTION_WIDTH, RESOLUTION_HEIGHT, 0);
	m_renderer = SDL_CreateRenderer(m_window, -1, 0);

    LoadFonts();

}

void RenderingController::RenderLevel(Level const& level, int score)
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
    DisplayScore(score);
	SDL_Delay(25);
}

RenderingController::~RenderingController()
{
    TTF_CloseFont(m_font);
}

void RenderingController::DisplayScore(int score)
{
    SDL_Color color = { 255, 255, 255, 0 }; // white
    std::string scoreStr = "Level 1, Score: " + std::to_string(score); // Convert score to string
    SDL_Surface* scoreSurface = TTF_RenderText_Solid(m_font, scoreStr.c_str(), color); // Pass C-style string to TTF_RenderText_Solid
    SDL_Texture* scoreTexture = SDL_CreateTextureFromSurface(this->m_renderer, scoreSurface);

    // Set the position of the score text
    SDL_Rect scoreRect;
    scoreRect.x = 20;
    scoreRect.y = 650;
    scoreRect.w = scoreSurface->w;
    scoreRect.h = scoreSurface->h;

    // Free the score surface
    SDL_FreeSurface(scoreSurface);
    SDL_RenderCopy(this->m_renderer, scoreTexture, NULL, &scoreRect);

    SDL_RenderPresent(m_renderer);
    SDL_DestroyTexture(scoreTexture);
}

void RenderingController::LoadFonts()
{
    m_font = TTF_OpenFont(m_userConfig.font_fullPath.c_str(), 32);
    if (m_font == nullptr)
    {
        std::string defaultFont = "C:\\Windows\\Fonts\\Arial.ttf";
        m_font = TTF_OpenFont(defaultFont.c_str(), 32);
    }
    if (m_font == nullptr)
        throw std::runtime_error(R"(Unable to load fonts.)");
    
}



