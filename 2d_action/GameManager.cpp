#include "stdafx.h"
#include "GameManager.h"
#include "SceneManager.h"

GameManager* GameManager::instance = nullptr;

void GameManager::GetKeyInput()
{
	inputManager->InputCommand();
}

void GameManager::DoAction()
{
	int keyInput = inputManager->GetLastCommand();
	Scene* curScene = SceneManager::GetInstance()->GetCurrentScene();

	curScene->DoAction(keyInput);
	inputManager->AddClockCommendTime();
}