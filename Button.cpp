#include "Button.h"

Button::Button(const sf::Texture& texture, const sf::IntRect& rect, const sf::Vector2f& pos) : _sprite(texture), _rect(rect), _pos(pos)
{
	_sprite.setTextureRect(rect);
	_sprite.setPosition(pos);
}

Button::~Button()
{
}

void Button::draw(sf::RenderWindow& window)
{
	if (_visible)
		window.draw(_sprite);
}

bool Button::isMouseOn(const sf::Vector2i& mousePos, const SceneEvents::mouseEventType& mouseEvent)
{
	if (mousePos.x >= _pos.x && mousePos.x <= _pos.x + _rect.width &&
		mousePos.y >= _pos.y && mousePos.y <= _pos.y + _rect.height)
		return true;
	return false;
}