#pragma once
#include<vector>

#include "Brick.h"
#include "Palette.h"

class CollisionController
{
public:
	CollisionController(Palette *Palette, std::vector<Brick>* bricks);

private:
	std::vector<Brick>* m_bricks;
	Palette* m_palette;
};
