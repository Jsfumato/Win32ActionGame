#pragma once
#include <vector>
#include "Scene.h"
#include "Character.h"

class SelectScene : public Scene
{
public:
	SelectScene() :Scene(){};
	SelectScene(std::wstring bgName)
		:Scene(bgName)
	{
		InitScene();
	};
	void DoAction(int keyInput);
	void InitScene();

	//Scene의 DrawScene 재정의
	virtual void DrawScene(HDC hdc) const;

private:
	Character* selectedCharacter;
	std::vector<Character*> characterList;
	
	void MoveSelecter(int num);
	void ShowCharacterList(HDC hdc) const;
};