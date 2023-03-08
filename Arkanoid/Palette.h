#pragma once

enum class PaletteDirection
{
	Left,
	Right
};

class Palette
{
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	PaletteDirection m_paletteDirection;

public:
	Palette(int x = 250, int y = 550, int width = 100, int height = 10);
	void ChangeDirection(PaletteDirection paletteDirection);
	void Move();

	int GetX() const;
	int GetY() const;
	int GetWidth() const;
	int GetHeight() const;
};



