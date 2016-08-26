#pragma once

#include "Utility.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Time.hpp>

class ProgressBar : public sf::Drawable, public sf::Transformable
{
public:
	ProgressBar();
	explicit ProgressBar( const sf::Vector2f size );

	void setText( const sf::Font& font, const sf::Color color );
	void setOutline( const float thickness, const sf::Color color );
	void setBarColors( const sf::Color background, const sf::Color fill );

	void setSize( const sf::Vector2f size );
	void setOutlineThickness( const float thickness );

	void setTextColor( const sf::Color color );
	void setFillColor( const sf::Color color );
	void setOutlineColor( const sf::Color color );
	void setBackgroundColor( const sf::Color color );

public:
	void setCompletion( const float value );
	void increase( const float value );
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