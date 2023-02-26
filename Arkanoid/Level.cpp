#include "Level.h"

Level::Level(AvailableLevel level)
{
	Palette m_Palette;
	Ball m_Ball;

	if (level == AvailableLevel::Level1)
	{
		m_bricks.emplace_back(Brick(10, 10, 70, 30));
		m_bricks.emplace_back(Brick( 90, 10, 70, 30 ));
		m_bricks.emplace_back(Brick( 100, 10, 70, 30 ));
		m_bricks.emplace_back(Brick( 180, 10, 70, 30));
		m_bricks.emplace_back(Brick( 260, 10, 70, 30));
		m_bricks.emplace_back(Brick( 340, 10, 70, 30));
		m_bricks.emplace_back(Brick( 420, 10, 70, 30));
	}
}

std::vector<RenderableObject> Level::GetObjectsToRender() const
{
	std::vector<RenderableObject> objectsToRender;

	std::for_each(m_bricks.begin(), m_bricks.end(), [&](auto& brick)
	{
			objectsToRender.emplace_back(RenderableObject{ brick.GetX(), brick.GetY(), brick.GetWidth(), brick.GetHeight() });
	});
	objectsToRender.emplace_back(RenderableObject{ m_palette.GetX(), m_palette.GetY(), m_palette.GetWidth(), m_palette.GetHeight() });
	objectsToRender.emplace_back(RenderableObject{ m_ball.GetX(), m_ball.GetY(), m_ball.GetWidth(), m_ball.GetHeight() });

	return objectsToRender;
}

void Level::MovePalette(int x)
{
	m_palette.Move(x);
}

Palette* Level::GetPalettePtr()
{
	return &m_palette;
}

std::vector<Brick>* Level::GetBricksPtr()
{
	return &m_bricks;
}

Ball* Level::GetBallPtr()
{
	return &m_ball;
}
