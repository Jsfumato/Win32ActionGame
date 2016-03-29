#pragma once
#include "Scene.h"
#include "Character.h"

class GameScene : public Scene
{
public:
	GameScene(std::wstring bgName)
		:Scene(bgName)
	{
		InitScene();
	};
	
	void AddCharacter(Character* character);

//	Scene의 method 재정의
	virtual void InitScene();
	virtual void DrawScene(HDC hdc) const;
	virtual void DoAction(int keyInput);

private:
	std::vector<Character*> characterList;
};