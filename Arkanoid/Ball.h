#pragma once
class Ball
{
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int m_speedX;
	int m_speedY;

public:
	Ball(int x = 250, int y = 450, int width = 10, int height = 10, int m_speedX = 4, int m_speedY = 4);

	int GetX() const;
	int GetY() const;
	int GetWidth() const;
	int GetHeight() const;
	void ChangeDirection(bool X, bool Y);
	void Move();
};

