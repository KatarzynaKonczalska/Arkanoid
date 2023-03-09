#pragma once
class Brick
{
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int m_lives = 1;

public:
	Brick(int x, int y, int width, int height);
	void Hit();

	int GetX() const;
	int GetY() const;
	int GetWidth() const;
	int GetHeight() const;
	bool IsAlive() const;
};

