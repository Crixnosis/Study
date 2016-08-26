#include "ProgressBar.hpp"

#include <SFML/Graphics/RenderTarget.hpp>

ProgressBar::ProgressBar()
{
	// Default Size and Default Colors
	setSize( sf::Vector2f( 200, 10 ) );
	setBarColors( sf::Color::White, sf::Color::Green );
}

ProgressBar::ProgressBar( const sf::Vector2f size )
{
	setSize( size );
	setBarColors( sf::Color::White, sf::Color::Green );
}

void ProgressBar::setText( const sf::Font& font, const sf::Color color )
{
	mPercentageText.setFont( font );
	mPercentageText.setColor( color );

	mPercentageText.setString( "0.00 %" );

	sf::FloatRect textBounds{ mPercentageText.getLocalBounds() };
	mPercentageText.setScale( mBackgroundBar.getSize().y / textBounds.height * 2.f / 3.f, mBackgroundBar.getSize().y / textBounds.height * 2.f / 3.f );

	mShowPercentage = true;
}

void ProgressBar::setOutline( const float thickness, const sf::Color color )
{
	setOutlineThickness( thickness );
	setOutlineColor( color );
}

void ProgressBar::setBarColors( const sf::Color background, const sf::Color fill )
{
	setBackgroundColor( background );
	setFillColor( fill );
}

void ProgressBar::setSize( const sf::Vector2f size )
{
	mBackgroundBar.setSize( size );
}

void ProgressBar::setOutlineThickness( const float thickness )
{
	mBackgroundBar.setOutlineThickness( thickness );
}

void ProgressBar::setTextColor( const sf::Color color )
{
	mPercentageText.setColor( color );
}

void ProgressBar::setFillColor( const sf::Color color )
{
	mFillBar.setFillColor( color );
}

void ProgressBar::setOutlineColor( const sf::Color color )
{
	mBackgroundBar.setOutlineColor( color );
}

void ProgressBar::setBackgroundColor( const sf::Color color )
{
	mBackgroundBar.setFillColor( color );
}

void ProgressBar::setCompletion( const float value )
{
	mCompletionPercentage = value;
	mCompletionPercentage = std::min( 1.f, std::max( mCompletionPercentage, 0.f ) );

	mFillBar.setSize( sf::Vector2f( mBackgroundBar.getSize().x * mCompletionPercentage, mBackgroundBar.getSize().y ) );
	updateText();
}

void ProgressBar::increase( const float value )
{
	mCompletionPercentage += value;
	mCompletionPercentage = std::min( 1.f, std::max( mCompletionPercentage, 0.f ) );

	mFillBar.setSize( sf::Vector2f( mBackgroundBar.getSize().x * mCompletionPercentage, mBackgroundBar.getSize().y ) );
	updateText();
}

float ProgressBar::getCompletion() const
{
	return mCompletionPercentage;
}

void ProgressBar::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	states.transform *= getTransform();

	target.draw( mBackgroundBar, states );
	target.draw( mFillBar, states );
	
	if( mShowPercentage )
	{
		sf::FloatRect bounds{ mPercentageText.getGlobalBounds() };
		states.transform.translate( mBackgroundBar.getSize().x / 2.f - bounds.width / 2.f, mBackgroundBar.getSize().y / 2.f - bounds.height );

		target.draw( mPercentageText, states );
	}
}

void ProgressBar::updateText()
{
	if( mShowPercentage )
	{
		const float percent{ mCompletionPercentage * 100.f };
		mPercentageText.setString( toString( floor( percent * 100 ) / 100 ) + " %" );
	}
}
