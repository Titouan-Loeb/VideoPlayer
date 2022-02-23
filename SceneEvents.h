#pragma once
class SceneEvents
{
public:

	enum mouseEventType {
		pushed,
		released,
		down,
		up,
	};

	enum sceneEventType {
		pause,
		play,
		fullScreen,
		smallScreen,
		changeTimeCode,
		ajustVolume,
		mute,
		unmute,
	};

	//sceneEventType type;
	//int purcentBot;
	//int purcentRight;
};

