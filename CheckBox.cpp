#include "CheckBox.h"

CheckBox::CheckBox(const sf::Texture& texture, const sf::IntRect& rect, const sf::Vector2f& pos, const bool& state) : _sprite(texture), _rect(rect), _pos(pos)
{
	_state = state;
	_type = AGUI::UIObjectType::CheckBox;
	_sprite.setTextureRect(rect);
	_sprite.setPosition(pos);
}

CheckBox::~CheckBox()
{
}

void CheckBox::draw(sf::RenderWindow& window)
{
	window.draw(_sprite);
}


void CheckBox::setPosition(const sf::Vector2f &position)
{
	_pos = position;
	_sprite.setPosition(_pos);
}

void CheckBox::setSize(const sf::Vector2f& size)
{
}

bool CheckBox::isMouseOn(const sf::Vector2i& mousePos, const SceneEvents::mouseEventType& mouseEvent)
{
	if (mousePos.x >= _pos.x && mousePos.x <= _pos.x + _rect.width &&
		mousePos.y >= _pos.y && mousePos.y <= _pos.y + _rect.height) {
		if (mouseEvent == SceneEvents::mouseEventType::pushed) {
			_state = !_state;
			if (_state)
				_rect.left = 0;
			else
				_rect.left = _rect.width;
			_sprite.setTextureRect(_rect);
		}
		return true;
	}
	return false;
}

void CheckBox::setValue(const int& value)
{
}

const int CheckBox::getValue()
{
	return 0;
}
