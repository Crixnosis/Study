#include "ProgressBar.hpp"

#include <SFML/Graphics/RenderTarget.hpp>

ProgressBar::ProgressBar():
	mCompletionPercentage{ 0.f }
{
}

void ProgressBar::setSize( const sf::Vector2f size )
{
	mBackgroundBar.setSize( size );
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

void ProgressBar::setOutlineThickness( const float thickness )
{
	mBackgroundBar.setOutlineThickness( thickness );
}

void ProgressBar::setCompletion( const float value )
{
	mCompletionPercentage = value;
	mCompletionPercentage = std::min( 1.f, std::max( mCompletionPercentage, 0.f ) );

	mFillBar.setSize( sf::Vector2f( mBackgroundBar.getSize().x * mCompletionPercentage, mBackgroundBar.getSize().y ) );
}

void ProgressBar::increase( const float value )
{
	mCompletionPercentage += value;
	mCompletionPercentage = std::min( 1.f, std::max( mCompletionPercentage, 0.f ) );

	mFillBar.setSize( sf::Vector2f( mBackgroundBar.getSize().x * mCompletionPercentage, mBackgroundBar.getSize().y ) );
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
}
