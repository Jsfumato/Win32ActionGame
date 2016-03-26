#pragma once
#include <atlimage.h>
#include <string>

class Character
{
public:
	virtual bool	HitCheck() = 0;
	virtual bool	IsHit();
	virtual ~Character();
	
	int			HitPoint;
	CImage		CharacterSprite;
	std::string name;

private:
	
};