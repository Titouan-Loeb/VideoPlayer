#include "Window.h"
#include "VideoVue.h"

Window::Window()
{
	_videoMode = { 900, 600, 32 };
	_window.create(_videoMode, "Arcade", sf::Style::Close);
	_currentScene = IScene::VideoVue;
	_scenes.push_back(std::unique_ptr<VideoVue> {new VideoVue(sf::Vector2f((float)_window.getSize().x, (float)_window.getSize().y))});
}

Window::~Window()
{
}

void Window::loop()
{
	while (_window.isOpen()) {
		while (_window.pollEvent(_event)) {
			if (_event.type == sf::Event::Closed)
				_window.close();
			_scenes[_currentScene]->sceneEvents(_window, _event);
		}
		_scenes[_currentScene]->compute(_window, _currentScene);
		_window.clear();
		_scenes[_currentScene]->draw(_window);
		_window.display();
	}
}