#pragma once
#include <vector>
#include <iterator>
#include <utility>
#include <functional>
#include <memory>
#include "MyInput.h"

class InputManager
{
public:
	void	InputCommand();
	InputManager(){};

	const void GetCommandList();
	const int GetLastCommand();
	void AddClockCommendTime();

private:
	std::unique_ptr<CMyInput> myInput = std::make_unique<CMyInput>();

	std::vector<std::tuple<int, int>> CommandWithTimeQueue;
	void CommandValidTimeCheck(std::function<bool(int)> closure);
};