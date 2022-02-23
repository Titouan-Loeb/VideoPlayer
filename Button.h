#pragma once

#include "SFML/Graphics.hpp"
#include "AGUI.h"
#include "SceneEvents.h"

class Button : public AGUI
{
public:
	Button(const sf::Texture &texture, const sf::IntRect &rect, const sf::Vector2f &pos);
	~Button();
	void draw(sf::RenderWindow& window);
	bool isMouseOn(const sf::Vector2i& mousePos, const SceneEvents::mouseEventType& mouseEvent);

private:
	sf::Sprite _sprite;
	sf::IntRect _rect;
	sf::Vector2f _pos;
};

