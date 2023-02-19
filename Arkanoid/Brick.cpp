#include "Brick.h"

Brick::Brick(int x, int y, int width, int height)
{
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
}

int Brick::GetX() const
{
	return m_x;
}

int Brick::GetY() const
{
	return m_y;
}

int Brick::GetWidth() const
{
	return m_width;
}

int Brick::GetHeight() const
{
	return m_height;
}
