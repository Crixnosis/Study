#pragma once

#include "ProgressBar.hpp"

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

	void handleEvents( const sf::Event& ev );

private:
	static const sf::Time TimePerFrame;
	
	sf::RenderWindow mWindow;
	
	sf::Font mFont;
	ProgressBar mBar;
};