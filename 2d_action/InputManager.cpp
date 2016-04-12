#include "stdafx.h"
#include "InputManager.h"
#include "GameConfig.h"

void InputManager::InputCommand()
{
	myInput->KeyboardProcess();

//	키가 눌린 순간 CommandQueue에 입력

//	키가 눌린 순간과 눌려있는 순간을 구분하는 방법을 찾아야 함
	for (auto& keyNum : playerKey::Player1CommandList)
	{
		bool isKeyInput = myInput->GetKeyDown(keyNum);
				
		if (isKeyInput == false)
			continue;

		//CommandWithTimeQueue.push_back(std::make_tuple(keyNum, 0));
		CommandWithTimeQueue.emplace_back(keyNum, 0);
	}

//	Closure 디자인 패턴 사용
//	각 Command의 입력으로부터 경과한 시간을 체크한다
	CommandValidTimeCheck(
		[](int CommandTime){ return CommandTime > 2000; }
	);
}

const int InputManager::GetLastCommand()
{
	if (CommandWithTimeQueue.size() == 0)
		return -1;

	if (std::get<1>(CommandWithTimeQueue.back()) == 0)
		return std::get<0>(CommandWithTimeQueue.back());
}

const void InputManager::GetCommandList()
{
	
}

void InputManager::CommandValidTimeCheck(std::function<bool(int)> closure)
{
	if (CommandWithTimeQueue.size() == 0)
		return;

	auto iter = CommandWithTimeQueue.begin();

//	순환 중에 item 삭제시 뒤의 순서가 엉킴...
//	erase 하는 경우 바로 iterator를 빠져나가서 위의 상황을 방지
	for (iter; iter < CommandWithTimeQueue.end(); ++iter)
	{
		if (closure(std::get<1>(*iter)))
		{
			CommandWithTimeQueue.erase(iter);
			break;
		}
	}
}

void InputManager::AddClockCommendTime()
{
	//	각 Command의 입력으로부터 경과한 시간을 갱신한다
	for (auto& iter : CommandWithTimeQueue)
	{
		std::get<1>(iter) += 1;
	}
}