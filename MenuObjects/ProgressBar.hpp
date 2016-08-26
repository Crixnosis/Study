#pragma once

#include "Utility.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Time.hpp>

class ProgressBar : public sf::Drawable, public sf::Transformable
{
public:
	ProgressBar();

	void setFont( const sf::Font& font );

	void setSize( const sf::Vector2f size );
	void setOutlineThickness( const float thickness );

	void setFillColor( const sf::Color color );
	void setBackgroundColor( const sf::Color color );
	void setOutlineColor( const sf::Color color );
	void setTextColor( const sf::Color color );

	void setCompletion( const float value );
	void increase( const float value );
	
	void showText( const bool isShown );
	float getCompletion() const;

private:
	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const override;
	void updateText();

private:
	sf::RectangleShape mBackgroundBar;
	sf::RectangleShape mFillBar;
	float mCompletionPercentage;

	bool mShowPercentage;
	sf::Text mPercentageText;
};