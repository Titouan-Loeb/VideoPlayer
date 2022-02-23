#pragma once

#include <vector>
#include <memory>
#include "IScene.h"

class Window
{

public:
	Window();
	~Window();
	void loop();
private:
	std::vector<std::unique_ptr<IScene>> _scenes;
	sf::RenderWindow _window;
	sf::VideoMode _videoMode;
	sf::Event _event;
	IScene::sceneId _currentScene;
};

