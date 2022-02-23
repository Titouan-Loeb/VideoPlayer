#include "AGUI.h"

AGUI::AGUI()
{
}

AGUI::~AGUI()
{
}

void AGUI::setVisibleState(const bool& state)
{
	_visible = state;
}

void AGUI::setActiveState(const bool& state)
{
	_active = state;
}

const bool &AGUI::getVisibleValue()
{
	return _visible;
}

const bool &AGUI::getActiveValue()
{
	return _active;
}

const AGUI::UIObjectType& AGUI::getType()
{
	return _type;
}

void AGUI::reset()
{
}

void AGUI::draw(sf::RenderWindow& window)
{
}