#include "stdafx.h"
#include "StartScene.h"
#include "SelectScene.h"
#include "SceneManager.h"
#include "Label.h"

void StartScene::InitScene()
{
	Scene::InitScene();

	Label* startText = new Label(L"Start");
	AppendObject(startText);
	
	/*startText->SetDestPosition(
		config::WindowWidth / 2, 
		config::WindowHeight / 2
	);*/

	startText->SetDestPosition(
		400,
		300
		);
}

void StartScene::DoAction(int keyInput)
{
	//추후 map 등 여타 방법을 통해 각 key가 무엇인지 가독성을 높일 예정
	//if (keyInput == playerKey::Player1CommandList[5])
	if (keyInput == 'A')
		SceneManager::GetInstance()->PushScene(new SelectScene(L"SelectScene.png"));
}