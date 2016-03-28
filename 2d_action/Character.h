#pragma once
#include <atlimage.h>
#include <string>
#include "Object.h"

class Character : public Object
{
public:
	virtual bool	HitCheck() = 0;
	virtual bool	IsHit();
	
	CImage		CharacterSprite;
	std::string name;

	Character(std::string cName, std::wstring fileName, int HitPoint)
		:characterName(cName), hitPoint(HitPoint)
	{
		SetSprite(fileName, L"Character");
	}

private:
	std::string	characterName;
	int	hitPoint;
};