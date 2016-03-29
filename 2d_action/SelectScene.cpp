#include "stdafx.h"
#include "SelectScene.h"
#include "SceneManager.h"
#include "Label.h"
#include "GabeNewell.h"

void SelectScene::InitScene()
{
	Scene::InitScene();

	Label* selectText = new Label(L"Select Character");
	AppendObject(selectText);

	/*startText->SetDestPosition(
	config::WindowWidth / 2,
	config::WindowHeight / 2
	);*/

	selectText->SetDestPosition(
		400,
		300
		);


	characterList.push_back(new CharacterGabeNewell());

	selectedCharacter = characterList.front();
}

void SelectScene::DoAction(int keyInput)
{
	//추후 map 등 여타 방법을 통해 각 key가 무엇인지 가독성을 높일 예정
	//if (keyInput == playerKey::Player1CommandList[5])
	if (keyInput == VK_RIGHT)
		MoveSelecter(1);

	if (keyInput == VK_LEFT)
		MoveSelecter(-1);

	if (keyInput == 'A')
	{
		GameScene* gameScene = new GameScene(L"SelectScene.png");
		if (selectedCharacter != nullptr)
			gameScene->AddCharacter(selectedCharacter);

		SceneManager::GetInstance()->PushScene(gameScene);
	}
}

//num이 양수면 오른쪽, 음수면 왼쪽으로 이동
//매개변수의 크기는 상관없습니다
void SelectScene::MoveSelecter(int num)
{
	auto iter = std::find(characterList.begin(), characterList.end(), selectedCharacter);
	if (iter == characterList.end())
		return;

	num = num / abs(num);
	auto currentIndex = std::distance(characterList.begin(), iter);
	int newIndex = (currentIndex + num) % characterList.size();

	selectedCharacter = characterList[newIndex];
}

void SelectScene::DrawScene(HDC hdc) const
{
	Scene::DrawScene(hdc);
	ShowCharacterList(hdc);
}

void SelectScene::ShowCharacterList(HDC hdc) const
{
	for (auto iter : characterList)
		iter->DrawProfile(hdc, 100, 100);
}