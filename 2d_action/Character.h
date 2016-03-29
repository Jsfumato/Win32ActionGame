#pragma once
#include <atlimage.h>
#include <string>
#include "Object.h"

class Character : public Object
{
public:
	//virtual bool	HitCheck() = 0;
	//virtual bool	IsHit();
	
	std::string name;

	Character(std::string cName, std::wstring fileName, int HitPoint)
		:characterName(cName), hitPoint(HitPoint)
	{
		SetSprite(fileName, L"Character");
	}

	void DrawProfile(HDC hdc, int xDest, int yDest);
	
	virtual void MoveCharacter(int direction);

protected:
	CImage profileImage;
	
	std::string	characterName;
	int	hitPoint;
	bool SetProfile(std::wstring fileName, std::wstring folderName);
};