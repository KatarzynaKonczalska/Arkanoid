#pragma once
#include "Brick.h"
#include "Palette.h"
#include "Ball.h"

#include <vector>
#include <algorithm>

enum class AvailableLevel
{
	Level1
};

struct RenderableObject
{
	int x;
	int y;
	int w;
	int h;
};

class Level
{
public:
	Level(AvailableLevel level);
	std::vector<RenderableObject> GetObjectsToRender() const;
	void MovePalette(int x);
	Palette* GetPalettePtr();
	std::vector<Brick>* GetBricksPtr();
	Ball* GetBallPtr();

private:
	std::vector<Brick> m_bricks;
	Palette m_palette;
	Ball m_ball;

};

