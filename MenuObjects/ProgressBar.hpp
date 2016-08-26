#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Time.hpp>

class ProgressBar : public sf::Drawable, public sf::Transformable
{
public:
	ProgressBar();

	void setSize( const sf::Vector2f size );
	
	void setFillColor( const sf::Color color );
	void setBackgroundColor( const sf::Color color );
	void setOutlineColor( const sf::Color );

	void setOutlineThickness( const float thickness );

	void setCompletion( const float value );
	void increase( const float value );
	
	float getCompletion() const;

private:
	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const override;

private:
	sf::RectangleShape mBackgroundBar;
	sf::RectangleShape mFillBar;
	float mCompletionPercentage;

	/*
	bool mShowPercentage;
	sf::Text mPercentageText;
	*/
};