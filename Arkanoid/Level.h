#pragma once
#include "Brick.h"
#include <vector>
#include <algorithm>

enum AvailableLevel
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
	std::vector<RenderableObject> GetObjectsToRender();

private:
	std::vector<Brick> m_bricks;
};
