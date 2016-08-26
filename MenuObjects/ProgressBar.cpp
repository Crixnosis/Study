#include "ProgressBar.hpp"

#include <SFML/Graphics/RenderTarget.hpp>

ProgressBar::ProgressBar():
	mCompletionPercentage{ 0.f },
	mShowPercentage{ false }
{
}

void ProgressBar::setFont( const sf::Font& font )
{
	mPercentageText.setFont( font );
	mShowPercentage = true;

	updateText();
}

void ProgressBar::setSize( const sf::Vector2f size )
{
	mBackgroundBar.setSize( size );
}

void ProgressBar::setOutlineThickness( const float thickness )
{
	mBackgroundBar.setOutlineThickness( thickness );
}

void ProgressBar::setFillColor( const sf::Color color )
{
	mFillBar.setFillColor( color );
}

void ProgressBar::setBackgroundColor( const sf::Color color )
{
	mBackgroundBar.setFillColor( color );
}

void ProgressBar::setOutlineColor( const sf::Color color )
{
	mBackgroundBar.setOutlineColor( color );
}

void ProgressBar::setTextColor( const sf::Color color )
{
	mPercentageText.setColor( color );
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
	sf::FloatRect textBounds{ mPercentageText.getLocalBounds() };

	mPercentageText.setString( toString( mCompletionPercentage * 100.f ) + " %" );
	mPercentageText.setScale( mBackgroundBar.getSize().y / textBounds.height * 2.f/3.f, mBackgroundBar.getSize().y / textBounds.height * 2.f / 3.f );
}
