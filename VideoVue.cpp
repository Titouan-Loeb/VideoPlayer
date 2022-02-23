
#include "VideoVue.h"
#include "CheckBox.h"
#include "ProgressBar.h"

VideoVue::VideoVue(const sf::Vector2f& windowSize) : _video("")
{
	_timeCode = 0;
	_fullScreen = false;
	sf::Texture texture;
	sf::Texture texture2;
	_clock.restart();
	_textures.push_back(texture);
	_textures.push_back(texture2);
	_textures[0].loadFromFile("play_pause.png");
	_textures[1].loadFromFile("full_small_screen.png");
	_GUIs.push_back(std::unique_ptr<CheckBox> {new CheckBox(_textures[0], { 48, 0, 48, 48 }, { 0.01f * windowSize.x, 0.99f * windowSize.y - 48}, false)});
	_GUIs.push_back(std::unique_ptr<CheckBox> {new CheckBox(_textures[1], { 48, 0, 48, 48 }, { windowSize.x - 58, 0.99f * windowSize.y - 48 }, false)});
	_GUIs.push_back(std::unique_ptr<ProgressBar> {new ProgressBar(sf::Vector2f(0.01f * windowSize.x, windowSize.y - 75), sf::Vector2f(0.98f * windowSize.x, 5), sf::Color(220, 220, 220), sf::Color(255, 55, 55))});
}

VideoVue::~VideoVue()
{
}

void VideoVue::sceneEvents(sf::RenderWindow& window, const sf::Event& event)
{
	if (event.type == sf::Event::MouseButtonPressed) {
		for (int i = 0; i < _GUIs.size(); i++) {
			if (_GUIs[i]->isMouseOn({event.mouseButton.x, event.mouseButton.y}, SceneEvents::mouseEventType::pushed))
				callBackUI((UIObjects)i, window);
		}
	}
}

void VideoVue::compute(sf::RenderWindow& window, sceneId& currentScene)
{
	int duration = 0;

	if (_video.isVideoRunning()) {
		if (_clock.getElapsedTime().asSeconds() >= 1) {
			_timeCode += (int)_clock.getElapsedTime().asSeconds();
			_clock.restart();
			duration = _video.getDuration();
			if (_timeCode > duration)
				_timeCode = 0;
			_GUIs[progressBar]->setValue(_timeCode * 100 / duration);
		}
	}
}

void VideoVue::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < _GUIs.size(); i++) {
		_GUIs[i]->draw(window);
	}
}

void VideoVue::playStopVideo(sf::RenderWindow& window)
{
	if (_video.isVideoRunning())
		_video.stop();
	else {
		_video.play();
		_clock.restart();
	}
}

void VideoVue::replaceElements(const sf::Vector2f& windowSize)
{
	_GUIs[playCheckBox]->setPosition({ 0.01f * windowSize.x, 0.99f * windowSize.y - 48 });
	_GUIs[fullScreenCheckBox]->setPosition({ windowSize.x - 58, 0.99f * windowSize.y - 48 });
	_GUIs[progressBar]->setPosition({ 0.01f * windowSize.x, windowSize.y - 75 });
	_GUIs[progressBar]->setSize({ 0.98f * windowSize.x, 5 });
}

void VideoVue::changeSizeScreen(sf::RenderWindow& window)
{
	if (_fullScreen) {
		window.close();
		window.create(sf::VideoMode(900, 600, 32), "Arcade", sf::Style::Close);
	}
	else {
		window.close();
		window.create(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height, 32), "Arcade", sf::Style::Fullscreen);
	}
	replaceElements(sf::Vector2f((float)window.getSize().x, (float)window.getSize().y));
	_fullScreen = !_fullScreen;
}

void VideoVue::setTimerVideo(sf::RenderWindow& window)
{
	int value = _GUIs[progressBar]->getValue();
	_timeCode = _video.getDuration() * value / 100;
	_video.setTime(_timeCode);
}

void VideoVue::callBackUI(const UIObjects& objectLabel, sf::RenderWindow& window)
{
	UIOCallBackType callBacks[] = { &VideoVue::playStopVideo, &VideoVue::changeSizeScreen, &VideoVue::setTimerVideo };

	(this->*callBacks[objectLabel])(window);
}

