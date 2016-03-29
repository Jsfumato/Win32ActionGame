#include "stdafx.h"
#include "GameScene.h"

void GameScene::AddCharacter(Character* character)
{
	characterList.push_back(character);
}

void GameScene::InitScene()
{
	Scene::InitScene();
	characterList.clear();
}

void GameScene::DrawScene(HDC hdc) const
{
	Scene::DrawScene(hdc);

	for (auto iter : characterList)
		iter->Draw(hdc);
}

void GameScene::DoAction(int keyInput)
{
	if (keyInput == VK_RIGHT)
		characterList[0]->MoveCharacter(1);

	if (keyInput == VK_LEFT)
		characterList[0]->MoveCharacter(-1);
}