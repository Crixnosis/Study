#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>

class Application
{
public:
	Application();
	void run();

private:
	void processInput();
	void update( const sf::Time dt );
	void render();

private:
	static const sf::Time TimePerFrame;
	sf::RenderWindow mWindow;
	sf::CircleShape mShape;
};