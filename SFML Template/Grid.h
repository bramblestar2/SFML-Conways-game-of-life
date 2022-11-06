#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <map>
#include "Cell.h"
#include "Rules.h"

class Grid
{
public:
	Grid(const sf::Vector2u WINDOW_SIZE);
	Grid();
	~Grid();

	void addCell(int, int, float);

	void render(sf::RenderWindow* window);
	void update(const double dt);
	void updateEvents(const sf::Event);

	std::map<int, std::map<int,bool>> getCells();

private:
	bool paused;

	std::map<int, std::map<int, bool>> positions;

	sf::Vector2u windowSize;
	std::vector<Cell*> cells;

	Rules rules;
};

