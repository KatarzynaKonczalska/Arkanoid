#include "Palette.h"

Palette::Palette(int x, int y, int width, int height) : m_x(x), m_y(y), m_width(width), m_height(height)
{

}

void Palette::ChangeDirection(PaletteDirection paletteDirection)
{
	if (paletteDirection == PaletteDirection::Left)
	{
		m_paletteDirection = PaletteDirection::Left;
	}
	else if (paletteDirection == PaletteDirection::Right)
	{
		m_paletteDirection = PaletteDirection::Right;
	}
}

void Palette::Move()
{
	if (m_paletteDirection == PaletteDirection::Left)
	{
		m_x -= 5;
	}
	else if (m_paletteDirection == PaletteDirection::Right)
	{
		m_x += 5;
	}
}

int Palette::GetX() const
{
	return m_x;
}

int Palette::GetY() const
{
	return m_y;
}

int Palette::GetWidth() const
{
	return m_width;
}

int Palette::GetHeight() const
{
	return m_height;
}

