#pragma once
#include "Character.h"

class CharacterGabe : public Character
{
public:
	CharacterGabe()
		:Character("GabeNewell", L"GabeNewell.png", 20000)
	{
		SetProfile(L"profile_GabeNewell.png", L"Character");
	};

private:

};