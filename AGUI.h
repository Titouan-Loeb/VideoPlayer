#pragma once
#include <vector>
#include <memory>

#include "SFML/Graphics.hpp"
#include "SceneEvents.h"

class AGUI
{
public:

	enum UIObjectType {
		CheckBox,
		Button,
		Image,
		Video,
		ProgressBar
	};

	AGUI();
	~AGUI();
	void setVisibleState(const bool &state);
	void setActiveState(const bool& state);
	const bool &getVisibleValue();
	const bool &getActiveValue();
	const UIObjectType& getType();
	virtual void reset();
	virtual const int getValue() = 0;
	virtual void setValue(const int& value) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual bool isMouseOn(const sf::Vector2i &mousePos, const SceneEvents::mouseEventType &mouseEvent) = 0;
	virtual void setPosition(const sf::Vector2f& position) = 0;
	virtual void setSize(const sf::Vector2f &size) = 0;

protected:
	bool _visible = true;
	bool _active = true;
	UIObjectType _type;
};

