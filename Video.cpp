#include "Video.h"

Video::Video(const std::string& path)
{
	_time = 0;
	_path = path;
	_videoRunning = true;
	_duration = 40;
}

Video::~Video()
{
}

void Video::reset()
{
}

void Video::stop()
{
	_videoRunning = false;
}

void Video::play()
{
	_videoRunning = true;
}

const int &Video::getTime()
{
	return _time;
}

const int& Video::getDuration()
{
	return _duration;
}

void Video::setTime(const int &time)
{
	_time = time;
}

void Video::setPosition(const sf::Vector2f& pos)
{
}

void Video::setSize(const sf::Vector2f& size)
{
}

void Video::draw(sf::RenderWindow& window)
{
}

bool Video::isMouseOn(const sf::Vector2i& mousePos, const SceneEvents::mouseEventType& mouseEvent)
{
	return false;
}

const bool& Video::isVideoRunning()
{
	return _videoRunning;
}

const int Video::getValue()
{
	return 0;
}

void Video::setValue(const int& value)
{
}