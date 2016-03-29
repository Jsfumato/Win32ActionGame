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
		:myInput(new CMyInput){};

	const void GetCommandList();
	const int GetLastCommand();

private:
	//int Player1CommandList[8];
	CMyInput* myInput;

	std::vector<std::pair<int, int>> CommandWithTimeQueue;
	void CommandValidTimeCheck(std::function<bool(int)> closure);
};