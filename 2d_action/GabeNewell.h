#pragma once
#include "Character.h"

class CharacterGabeNewell : public Character
{
public:
	CharacterGabeNewell()
		:Character(L"sprite_gabe.png")
	{
		SetProfile(L"profile_GabeNewell.png", L"Character");
	};

private:

};