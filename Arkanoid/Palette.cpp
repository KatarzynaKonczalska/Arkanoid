#include "Palette.h"

Palette::Palette(int x, int y, int width, int height)
{
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
}

void Palette::Move(int x)
{
	m_x += x;
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

