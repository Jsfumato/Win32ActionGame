#pragma once
#include <vector>
#include <iterator>
#include <utility>
#include <functional>
#include "MyInput.h"

class InputManager
{
public:
	void	InputCommand();

	InputManager() 
		:myInput(new CMyInput){

		Player1CommandList[0] = VK_UP;
		Player1CommandList[1] = VK_DOWN;
		Player1CommandList[2] = VK_LEFT;
		Player1CommandList[3] = VK_RIGHT;
		Player1CommandList[4] = VK_A;
		Player1CommandList[5] = VK_S;
		Player1CommandList[6] = VK_D;
		Player1CommandList[7] = VK_F;
	};

	const void GetCommandList();

private:
	int Player1CommandList[8];
	CMyInput* myInput;

	std::vector<std::pair<int, int>> CommandWithTimeQueue;
	void CommandValidTimeCheck(std::function<bool(int)> closure);
};