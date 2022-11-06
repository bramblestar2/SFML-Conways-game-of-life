#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Cell : public sf::RectangleShape
{
public:
	Cell(int posX, int posY, float size);
	Cell();
	~Cell();


	sf::Vector2i get_position();

	void update(const double dt);
	void kill();

private:
	float size;
	sf::Vector2i pos;

	//position x, y
	void setup(int,int,float);

	//Smooth visuals
	float lerp(float,float,float);
	void smoothSizeChange();
};

