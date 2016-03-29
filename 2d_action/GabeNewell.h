#pragma once
#include "Character.h"

class CharacterGabeNewell : public Character
{
public:
	CharacterGabeNewell()
		:Character("GabeNewell", L"GabeNewell_0.png", 20000)
	{
		SetProfile(L"profile_GabeNewell.png", L"Character");
	};

private:

};