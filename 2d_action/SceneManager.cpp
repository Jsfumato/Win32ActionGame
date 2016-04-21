#include "stdafx.h"
#include "SceneManager.h"
#include "StartScene.h"
#include "SelectScene.h"
#include "GameScene.h"

void SceneManager::Init()
{
	StartScene* startScene = new StartScene(L"StartScene.png");
	SceneStack.clear();
	PushScene(startScene);
}

//Scene�� ��ӹ��� �پ��� Scene class���� ���ٵ�
//emplace_back�� ����� �� ������?
void SceneManager::PushScene(Scene* scene)
{
	SceneStack.push_back(scene);
}

Scene* SceneManager::GetCurrentScene()
{
	return SceneStack.back();
}

void SceneManager::PopScene()
{
	Scene* popedScene = SceneStack.back();
	SceneStack.pop_back();
	delete popedScene;
}

void SceneManager::ReplaceScene(Scene* scene)
{
	PopScene();
	SceneStack.push_back(scene);
}