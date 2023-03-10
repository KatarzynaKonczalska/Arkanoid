#include "Ball.h"

Ball::Ball(int x, int y, int width, int height, int speedX, int speedY)
	: m_x(x), m_y(y), m_width(width), m_height(height), m_speedX(speedX), m_speedY(speedY)
{
}

int Ball::GetX() const
{
	return m_x;
}

int Ball::GetY() const
{
	return m_y;
}

int Ball::GetWidth() const
{
	return m_width;
}

int Ball::GetHeight() const
{
	return m_height;
}

void Ball::ChangeDirection(bool X, bool Y)
{
	if (X) m_speedX *= (-1);
	if (Y) m_speedY *= (-1);
}

void Ball::Move()
{
	m_x += m_speedX;
	m_y += m_speedY;
}
