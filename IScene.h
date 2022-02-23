#pragma once

#include <memory>

#include "SFML/Graphics.hpp"

class IScene
{
public:

	enum sceneId {
		VideoVue
	};

	virtual ~IScene() = default;
	virtual void compute(sf::RenderWindow& window, sceneId &currentScene) = 0;
	virtual void draw(sf::RenderWindow &window) = 0;
	virtual void sceneEvents(sf::RenderWindow& window, const sf::Event& event) = 0;
};

