#pragma once
#include "Scene.h"
#include "Label.h"

class StartScene : public Scene
{
public:
	StartScene() :Scene(){};
	StartScene(std::wstring bgName)
		:Scene(bgName)
	{
		InitScene();
	};

	void InitScene();

private:

};