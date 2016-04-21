#pragma once
#include <atlimage.h>
#include <string>
#include <fstream>
#include "json.hpp"
#include "Object.h"

enum class state {
	DEFAULT = 0, 
	MOVE,
	PUNCHbb,
	JUMP, 
	SITDOWN,
	MAX_STATE
};

class Character : public Object
{
public:
	Character(std::wstring fileName) : Object(100, 150)
	{
		SetSprite(fileName, L"Character");
		SetJsonFile(L"Sprite-0004.json", L"Character");
	
		spriteIndex = 0;
		currentState = state::DEFAULT;
	}

	void DrawProfile(HDC hdc, int xDest, int yDest);
	
	virtual void Draw(HDC hdc);
	virtual void MoveCharacter(int direction);

protected:
	CImage profileImage;
	int spriteIndex;
	state currentState;

	std::string	characterName;
	bool SetProfile(std::wstring fileName, std::wstring folderName);
};