#pragma once
#include <vector>
#include <iterator>
#include "InputManager.h"
#include "ActionManager.h"
#include "Scene.h"

class GameManager
{
public:
	static GameManager* GetInstance()
	{
		if (instance == nullptr)
			instance = new GameManager();
		return instance;
	};

	~GameManager()
	{
		delete inputManager;
		delete actionManager;
		delete instance;
	}

	void	GetKeyInput();
	void	DoAction();

private:
	static GameManager* instance;
	GameManager()
		:inputManager(new InputManager), actionManager(new ActionManager){};

	void SceneAction(Scene* scene, int keyInput);

	InputManager*	inputManager;
	ActionManager*	actionManager;
};