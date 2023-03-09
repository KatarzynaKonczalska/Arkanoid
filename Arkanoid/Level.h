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
	explicit Level(AvailableLevel level);
	std::vector<RenderableObject> GetObjectsToRender() const;
	Palette& GetPaletteRef();
	std::vector<Brick>& GetBricksRef();
	Ball& GetBallRef();

private:
	std::vector<Brick> m_bricks;
	Palette m_palette;
	Ball m_ball;

};

