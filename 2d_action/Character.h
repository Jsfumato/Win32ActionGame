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
	Character(std::wstring fileName)
		:Object(L"Character", fileName)
	{
		SetState(state::DEFAULT);
		numOfState = stateMax - stateMin;
	}

	void DrawProfile(HDC hdc, int xDest, int yDest);
	void SetState(state state);

	virtual void Draw(HDC hdc);
	virtual void MoveCharacter(int direction);
	
protected:
	CImage profileImage;
	int spriteIndex;
	int stateMin = 0;
	int stateMax = 0;
	int numOfState = 0;

	state currentState = state::MAX_STATE;

	std::string	characterName;
	bool SetProfile(std::wstring fileName, std::wstring folderName);
};