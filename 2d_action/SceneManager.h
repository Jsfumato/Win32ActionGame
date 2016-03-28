#pragma once
#include <vector>
#include "Scene.h"
#include "StartScene.h"
#include "SelectScene.h"
#include "GameScene.h"

class SceneManager
{
public:
	static SceneManager* GetInstance()
	{
		if (instance == nullptr)
			instance = new SceneManager();
		return instance;
	}

	void	PushScene(Scene* scene);
	Scene*	GetCurrentScene();
	void	PopScene();
	void	ReplaceScene(Scene* scene);
	void	Init();

private:
	static SceneManager* instance;
	std::vector<Scene*> SceneStack;
	
	SceneManager(){};
	~SceneManager()
	{
		delete instance;
	}
};