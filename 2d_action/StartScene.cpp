#include "stdafx.h"
#include "StartScene.h"
#include "GameConfig.h"

void StartScene::InitScene()
{
	Scene::InitScene();

	Label* startText = new Label(L"Start");
	AppendObject(startText);
	
	startText->SetDestPosition(
		config::WindowWidth / 2, 
		config::WindowHeight / 2
	);
}