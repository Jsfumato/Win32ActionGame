#pragma once
#include "stdafx.h"
#include "Character.h"
#include "json.hpp"

namespace std
{
	static Character& MakeCharacter(std::wstring name)
	{
		std::ifstream ifs("Sprite/Character/gabe.json");
		nlohmann::json characterData(ifs);
	}
}