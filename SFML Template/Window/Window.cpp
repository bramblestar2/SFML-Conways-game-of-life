#include "Window.h"

Window::Window()
{
	initWindow();
	mouseInWindow = false;
}

Window::~Window()
{
	delete window;
}

void Window::run()
{
	while (window->isOpen())
	{
		update();
		updateDt();
		updateSFMLEvents();
		render();
	}
}

void Window::render()
{
	window->clear();
	
	cellGrid.render(window);

	window->display();
}

void Window::update()
{
	cellGrid.update(dt);
}

void Window::updateDt()
{
	dt = dtClock.restart().asSeconds();
}

void Window::updateSFMLEvents()
{
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed ||
			event.key.code == sf::Keyboard::Escape)
			window->close();

		if (event.type == sf::Event::MouseButtonPressed && mouseInWindow)
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
			int size = 20;
			
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				std::cout << mousePos.x/size << " - " << mousePos.y/size << std::endl;
				cellGrid.addCell(((mousePos.x + (size / 2)) / size), ((mousePos.y + (size / 2)) / size), size);
			}
		}

		if (event.type == sf::Event::MouseEntered)
			mouseInWindow = true;
		if (event.type == sf::Event::MouseLeft)
			mouseInWindow = false;

		cellGrid.updateEvents(event);
	}
}

void Window::initWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(600, 600), "TITLE", sf::Style::Default);
	window->setFramerateLimit(60);
}
