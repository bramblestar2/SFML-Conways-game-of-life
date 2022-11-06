#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Rules
{
public:
	Rules();
	~Rules();

	sf::Vector2i updatePositions(std::map<int, std::map<int, bool>>);
private:



	int cellsNear;
};

