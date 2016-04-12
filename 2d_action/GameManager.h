#pragma once
#include <vector>
#include <iterator>
#include <memory>
#include "Singleton.h"
#include "InputManager.h"
#include "Scene.h"

class GameManager : public Singleton<GameManager>
{
public:
	~GameManager()
	{
		inputManager.release();
	}

	void	GetKeyInput();
	void	DoAction();

	GameManager(){};

private:
	void SceneAction(Scene* scene, int keyInput);
	std::unique_ptr<InputManager> inputManager = std::make_unique<InputManager>();
};