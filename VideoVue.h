#pragma once

#include <vector>
#include <memory>

#include "IScene.h"
#include "AGUI.h"
#include "Video.h"


class VideoVue : public IScene
{
public:
	typedef void (VideoVue::* UIOCallBackType)(sf::RenderWindow& window);

	enum UIObjects
	{
		playCheckBox,
		fullScreenCheckBox,
		progressBar,
	};

	VideoVue(const sf::Vector2f& windowSize);
	~VideoVue();
	void compute(sf::RenderWindow& window, sceneId& currentScene);
	void draw(sf::RenderWindow &window);
	void sceneEvents(sf::RenderWindow& window, const sf::Event& event);
	void replaceElements(const sf::Vector2f& window);

	void playStopVideo(sf::RenderWindow& window);
	void changeSizeScreen(sf::RenderWindow& window);
	void setTimerVideo(sf::RenderWindow& window);
	void callBackUI(const UIObjects& objectLabel, sf::RenderWindow& window);

private:
	std::vector<sf::Texture> _textures;
	std::vector<std::unique_ptr<AGUI>> _GUIs;
	int _timeCode;
	bool _fullScreen;
	Video _video;
	sf::Clock _clock;
};

