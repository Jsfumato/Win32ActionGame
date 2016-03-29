#include "stdafx.h"
#include "InputManager.h"
#include "GameConfig.h"

void InputManager::InputCommand()
{
	myInput->KeyboardProcess();

//	키가 눌린 순간 CommandQueue에 입력
	for each (auto& keyNum in playerKey::Player1CommandList)
	{
		bool isKeyInput = myInput->GetKeyDown(keyNum);
		
		if (isKeyInput == false)
			continue;

		CommandWithTimeQueue.push_back(std::make_pair(keyNum, 0));
	}
	
//	각 Command의 입력으로부터 경과한 시간을 갱신한다
	for (auto& iter : CommandWithTimeQueue)
	{
		iter.second += 1;
	}

//	Closure 디자인 패턴 사용
//	각 Command의 입력으로부터 경과한 시간을 체크한다
	CommandValidTimeCheck(
		[](int CommandTime){ return CommandTime > 2000; }
	);
}

const int InputManager::GetLastCommand()
{
	if (CommandWithTimeQueue.size() != 0)
		return CommandWithTimeQueue.back().first;
}

const void InputManager::GetCommandList()
{
	
}

void InputManager::CommandValidTimeCheck(std::function<bool(int)> closure)
{
	if (CommandWithTimeQueue.size() == 0)
		return;

	std::vector<std::pair<int, int>>::iterator iter = CommandWithTimeQueue.begin();

//	순환 중에 item 삭제시 뒤의 순서가 엉킴...
//	erase 하는 경우 바로 iterator를 빠져나가서 위의 상황을 방지한다
	for (iter; iter < CommandWithTimeQueue.end(); ++iter)
	{
		if (closure(iter->second))
		{
			CommandWithTimeQueue.erase(iter);
			break;
		}
	}
}

/*

for (auto& iter : CommandWithTimeQueue)
{
	if (iter.second > 10)
		
}

Question

	제가 직접 iterator 형을 선언하여 for 문을 돌리는 경우에는 위의 경우처럼 잘 돌아갑니다만
	왜 auto를 이용해 캐스팅을 하려하면 원하는 타입으로 형식 추론이 되지 않을까요
	이번 EMC++ item 1, 2에서 한 내용입니다만 책에서 못 본것 같은데
	std::pair에 대해서도 예외가 존재하는 건가요???
*/
