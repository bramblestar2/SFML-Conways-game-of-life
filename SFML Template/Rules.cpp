#include "Rules.h"

Rules::Rules()
{
	cellsNear = 0;
}

Rules::~Rules()
{
}

std::vector<sf::Vector2i> Rules::updatePositions(std::vector<sf::Vector2i> frontEnd)
{
	std::vector<sf::Vector2i> newCells;

	for (int i = 0; i < frontEnd.size(); i++)
	{
		int count = checkNearbyCells(frontEnd, frontEnd.at(i).x, frontEnd.at(i).y);
	}

	return newCells;
}

int Rules::checkNearbyCells(std::vector<sf::Vector2i>& cells, int x, int y)
{
	int count = 0;

	for (int i = 0; i < cells.size(); i++)
	{
		sf::Vector2i pos = cells.at(i);

		//	Top row
		if (pos.y == y - 1)
		{
			//Left
			if (pos.x == x - 1)
				count++;
			//Middle
			if (pos.x == x)
				count++;
			//Right
			if (pos.x == x + 1)
				count++;
		}

		//	Center row
		if (pos.y == y)
		{
			//Left
			if (pos.x == x - 1)
				count++;
			//Right
			if (pos.x == x + 1)
				count++;
		}

		//	Bottom row
		if (pos.y == y + 1)
		{
			//Left
			if (pos.x == x - 1)
				count++;
			//Middle
			if (pos.x == x)
				count++;
			//Right
			if (pos.x == x + 1)
				count++;
		}
	}

	return 0;
}
