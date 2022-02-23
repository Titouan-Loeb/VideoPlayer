#pragma once
#include "AGUI.h"

class ProgressBar : public AGUI
{
public:
	ProgressBar(const sf::Vector2f &pos, const sf::Vector2f &size, const sf::Color& colorFullbar, const sf::Color &colorProgressBar);
	~ProgressBar();
	void draw(sf::RenderWindow& window);
	bool isMouseOn(const sf::Vector2i& mousePos, const SceneEvents::mouseEventType& mouseEvent);
	void setPosition(const sf::Vector2f& position);
	void setSize(const sf::Vector2f& size);
	const int getValue();
	void setValue(const int& value);

private:
	sf::Vector2f _pos;
	sf::Vector2f _size;
	sf::RectangleShape _fullBar;
	sf::RectangleShape _progressBar;
	sf::Color _colorFullBar;
	sf::Color _colorProgressBar;
	int _purcent;
	int _lenght;
};
