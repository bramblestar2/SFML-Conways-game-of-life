#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Rules
{
public:
	Rules();
	~Rules();

	std::vector<sf::Vector2i> updatePositions(std::vector<sf::Vector2i>);
private:
	int cellsNear;
	int checkNearbyCells(std::vector<sf::Vector2i>&, int, int);
};

