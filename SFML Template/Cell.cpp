#include "Cell.h"

Cell::Cell(int posX, int posY, float size)
{
	setup(posX, posY, size);
}

Cell::Cell()
{
	setup(0, 0, 0);
}

Cell::~Cell()
{
}

sf::Vector2i Cell::get_position()
{
	return pos;
}

void Cell::update(const double dt)
{
	smoothSizeChange();
}

void Cell::kill()
{
	size = 0;
}

void Cell::setup(int x, int y, float size)
{
	setPosition(x*size, y*size);
	this->size = size;
	setFillColor(sf::Color::White);
	setOrigin(size, size);
}

float Cell::lerp(float a, float b, float t)
{
	return a + t * (b - a);
}

void Cell::smoothSizeChange()
{
	float transition = 0.1f;

	setOrigin(getSize().x / 2, getSize().y / 2);

	setSize(sf::Vector2f(
						 lerp(getSize().x, size, transition),
						 lerp(getSize().y, size, transition)
	));
}
