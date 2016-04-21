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

//Scene을 상속받은 다양한 Scene class들이 들어갈텐데
//emplace_back을 사용할 수 있을까?
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