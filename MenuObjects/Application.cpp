#include "Application.hpp"

#include <SFML/Window/Event.hpp>

const sf::Time Application::TimePerFrame{ sf::seconds( 1.f / 60.f ) };

Application::Application():
	mWindow{ sf::VideoMode( 640, 480 ), "Menu-Objects", sf::Style::Close },
	mShape{ 100.f }
{
	mShape.setFillColor( sf::Color::Green );
}

void Application::run()
/*
	Main application loop, runs until the window is closed
*/
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate{ sf::Time::Zero };

	while( mWindow.isOpen() )
	{
		timeSinceLastUpdate += clock.restart();
		while( timeSinceLastUpdate > TimePerFrame )
		{
			timeSinceLastUpdate -= TimePerFrame;
			processInput();
			update( TimePerFrame );
		}
		render();
	}
}

void Application::processInput()
{
	sf::Event ev;

	while( mWindow.pollEvent( ev ) )
	{
		if( ev.type == sf::Event::Closed )
			mWindow.close();
	}
}

void Application::update( const sf::Time dt )
{
}

void Application::render()
{
	mWindow.clear();

	mWindow.draw( mShape );

	mWindow.display();
}
