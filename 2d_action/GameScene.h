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

//	Scene�� method ������
	virtual void InitScene();
	virtual void DrawScene(HDC hdc) const;
	virtual void DoAction(int keyInput);

private:
	std::vector<Character*> characterList;
};