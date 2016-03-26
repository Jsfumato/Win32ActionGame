#include "stdafx.h"
#include "GameManager.h"

GameManager* GameManager::instance = nullptr;

void GameManager::GetKeyInput()
{
	inputManager->InputCommand();
}

void GameManager::DoCharacterAction()
{

	actionManager;
}