#pragma once
#include <vector>
#include <iterator>
#include "Singleton.h"
#include "InputManager.h"
#include "ActionManager.h"
#include "Scene.h"

class GameManager : public Singleton<GameManager>
{
public:
	~GameManager()
	{
		delete inputManager;
		delete actionManager;
	}

	void	GetKeyInput();
	void	DoAction();

	GameManager()
		:inputManager(new InputManager), actionManager(new ActionManager){};

private:
	void SceneAction(Scene* scene, int keyInput);

	InputManager*	inputManager;
	ActionManager*	actionManager;
};