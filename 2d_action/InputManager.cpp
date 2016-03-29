#include "stdafx.h"
#include "InputManager.h"
#include "GameConfig.h"

void InputManager::InputCommand()
{
	myInput->KeyboardProcess();

//	Ű�� ���� ���� CommandQueue�� �Է�

//	Ű�� ���� ������ �����ִ� ������ �����ϴ� ����� ã�ƾ� ��
	for each (auto& keyNum in playerKey::Player1CommandList)
	{
		bool isKeyInput = myInput->GetKeyDown(keyNum);
		//bool isKeyInput = myInput->GetKey(keyNum);
		
		if (isKeyInput == false)
			continue;

		CommandWithTimeQueue.push_back(std::make_pair(keyNum, 0));
	}

//	Closure ������ ���� ���
//	�� Command�� �Է����κ��� ����� �ð��� üũ�Ѵ�
	CommandValidTimeCheck(
		[](int CommandTime){ return CommandTime > 2000; }
	);
}

const int InputManager::GetLastCommand()
{
	if (CommandWithTimeQueue.size() == 0)
		return -1;

	if (CommandWithTimeQueue.back().second == 0)
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

//	��ȯ �߿� item ������ ���� ������ ��Ŵ...
//	erase �ϴ� ��� �ٷ� iterator�� ���������� ���� ��Ȳ�� ����
	for (iter; iter < CommandWithTimeQueue.end(); ++iter)
	{
		if (closure(iter->second))
		{
			CommandWithTimeQueue.erase(iter);
			break;
		}
	}
}

void InputManager::AddClockCommendTime()
{
	//	�� Command�� �Է����κ��� ����� �ð��� �����Ѵ�
	for (auto& iter : CommandWithTimeQueue)
	{
		iter.second += 1;
	}
}