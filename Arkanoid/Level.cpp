#include "Level.h"

Level::Level(AvailableLevel level)
{
	if (level == Level1)
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

std::vector<RenderableObject> Level::GetObjectsToRender()
{
	std::vector<RenderableObject> objectsToRender;

	std::for_each(m_bricks.begin(), m_bricks.end(), [&](auto& brick)
	{
			objectsToRender.emplace_back(RenderableObject{ brick.GetX(), brick.GetY(), brick.GetWidth(), brick.GetHeight() });
	});
	return objectsToRender;
}