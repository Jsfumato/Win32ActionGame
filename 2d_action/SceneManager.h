#pragma once
#include <vector>
#include "Singleton.h"
#include "Scene.h"
#include "StartScene.h"
#include "SelectScene.h"
#include "GameScene.h"

class SceneManager : public Singleton<SceneManager>
{
public:
	void	PushScene(Scene* scene);
	Scene*	GetCurrentScene();
	void	PopScene();
	void	ReplaceScene(Scene* scene);
	void	Init();

private:
	std::vector<Scene*> SceneStack;
};