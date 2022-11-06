#include "Grid.h"

Grid::Grid(const sf::Vector2u WINDOW_SIZE)
{
    windowSize = WINDOW_SIZE;
    paused = true;
}

Grid::Grid()
{
    paused = true;
    windowSize = {0,0};
}

Grid::~Grid()
{
    for (int i = 0; i < cells.size(); i++)
        delete cells.at(i);
}

void Grid::addCell(int x, int y, float size)
{
    cells.push_back(new Cell(x, y, size));
}

void Grid::render(sf::RenderWindow* window)
{
    for (int i = 0; i < cells.size(); i++)
        window->draw(*cells.at(i));
}

void Grid::update(const double dt)
{
    if (!paused)
        rules.updatePositions(getCells());

    for (int i = 0; i < cells.size(); i++)
    {
        cells.at(i)->update(dt);

        if (cells.at(i)->getSize().x == 0)
        {
            delete cells.at(i);
            cells.erase(cells.begin() + i);
        }
    }
}

void Grid::updateEvents(const sf::Event event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            paused = paused ? false : true;
    }
}

std::vector<sf::Vector2i> Grid::getCells()
{
    positions.clear();
    for (int i = 0; i < cells.size(); i++)
        positions.push_back(cells.at(i)->get_position());
    return positions;
}
