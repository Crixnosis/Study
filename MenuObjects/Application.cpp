#include "Application.hpp"

#include <SFML/Window/Event.hpp>

const sf::Time Application::TimePerFrame{ sf::seconds( 1.f / 60.f ) };

Application::Application():
	mWindow{ sf::VideoMode( 640, 480 ), "Menu-Objects", sf::Style::Close },
	mBar{ sf::Vector2f( 200, 20 ) }
{
	mFont.loadFromFile( "../Resources/Fonts/LinLibertine_DRah.ttf" );

	mBar.setBarColors( sf::Color( 220, 220, 220 ), sf::Color::Green );
	mBar.setOutline( 5.f, sf::Color( 128, 128, 128 ) );
	mBar.setText( mFont, sf::Color::Red );

	mBar.setPosition( ( mWindow.getDefaultView().getSize() / 2.f ) - sf::Vector2f( 200, 20 ) / 2.f );
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

		handleEvents( ev );
	}
}

void Application::update( const sf::Time dt )
{
}

void Application::render()
{
	mWindow.clear();

	mWindow.draw( mBar );

	mWindow.display();
}

void Application::handleEvents( const sf::Event& ev )
{
	if( ev.type == sf::Event::KeyPressed )
		switch( ev.key.code )
		{
		case sf::Keyboard::Right:
			mBar.increase( 0.001f );
			break;

		case sf::Keyboard::Left:
			mBar.increase( -0.001f );
			break;

		case sf::Keyboard::Num0:
			mBar.setCompletion( 0.f );
			break;

		case sf::Keyboard::Num1:
			mBar.setCompletion( 1.f );
			break;
		}
}
