#pragma once
#include "Scene.h"

class StartScene : public Scene
{
public:
	StartScene(std::wstring bgName)
		:Scene(bgName)
	{
		InitScene();
	};
	void DoAction(int keyInput);
	void InitScene();

private:
	
};