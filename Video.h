#pragma once

#include <string>
#include "AGUI.h"

class Video : public AGUI
{
public:
	Video(const std::string &path);
	~Video();
	void reset();
	void stop();
	void play();
	void setTime(const int& time);
	void setPosition(const sf::Vector2f& pos);
	void setSize(const sf::Vector2f& size);
	const int& getTime();
	const int& getDuration();
	const bool& isVideoRunning();
	void draw(sf::RenderWindow& window);
	bool isMouseOn(const sf::Vector2i& mousePos, const SceneEvents::mouseEventType& mouseEvent);
	const int getValue();
	void setValue(const int& value);

private:
	int _time;
	int _duration;
	std::string _path;
	bool _videoRunning;
};