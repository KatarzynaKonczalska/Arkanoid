#pragma once
class Palette
{
	int m_x;
	int m_y;
	int m_width;
	int m_height;

public:
	Palette(int x = 250, int y = 550, int width = 100, int height = 10);
	void Move(int x);

	int GetX() const;
	int GetY() const;
	int GetWidth() const;
	int GetHeight() const;
};



