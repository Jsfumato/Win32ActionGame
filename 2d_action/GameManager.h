#pragma once
#include <vector>
#include <iterator>
#include "InputManager.h"
#include "ActionManager.h"

class GameManager
{
public:
	static GameManager* GetInstance()
	{
		if (instance == nullptr)
			instance = new GameManager();
		return instance;
	};

	void	GetKeyInput();
	void	DoCharacterAction();

private:
	static GameManager* instance;
	GameManager()
		:inputManager(new InputManager), actionManager(new ActionManager){};

	InputManager*	inputManager;
	ActionManager*	actionManager;
};

//GameManager* GameManager::instance = nullptr;