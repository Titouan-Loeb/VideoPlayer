#include "ProgressBar.h"

#include <iostream>

ProgressBar::ProgressBar(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Color& colorFullBar, const sf::Color& colorProgressBar)
{
	_lenght = 0;
	_purcent = 0;
	_pos = pos;
	_size = size;
	_colorFullBar = colorFullBar;
	_colorProgressBar = colorProgressBar;
	_type = AGUI::UIObjectType::ProgressBar;
	_fullBar.setSize(size);
	_progressBar.setSize(sf::Vector2f(_purcent * size.x / 100, size.y));
	_fullBar.setFillColor(colorFullBar);
	_progressBar.setFillColor(colorProgressBar);
	_fullBar.setPosition(_pos);
	_progressBar.setPosition(_pos);
}

ProgressBar::~ProgressBar()
{
}

void ProgressBar::draw(sf::RenderWindow& window)
{
	if (_visible) {
		window.draw(_fullBar);
		window.draw(_progressBar);
	}
}

void ProgressBar::setPosition(const sf::Vector2f &position)
{
	_pos = position;
	_fullBar.setPosition(_pos);
	_progressBar.setPosition(_pos);
}

void ProgressBar::setSize(const sf::Vector2f& size)
{
	_fullBar.setSize(size);
	_progressBar.setSize({ size.x * _purcent / 100, size.y });
}

bool ProgressBar::isMouseOn(const sf::Vector2i& mousePos, const SceneEvents::mouseEventType& mouseEvent)
{
	if (mousePos.x >= _pos.x && mousePos.x <= _pos.x + _size.x &&
		mousePos.y >= _pos.y && mousePos.y <= _pos.y + _size.y) {
		_purcent = 100 * (mousePos.x - (int)_pos.x) / (int)_size.x;
		_lenght = mousePos.x - (int)_pos.x;
		_progressBar.setSize(sf::Vector2f((float)_lenght, _size.y));
		return true;
	}
}

const int ProgressBar::getValue()
{
	return _purcent;
}

void ProgressBar::setValue(const int& value)
{
	_purcent = value;
	_progressBar.setSize({ _size.x * _purcent / 100, _size.y });
}