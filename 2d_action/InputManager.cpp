#include "stdafx.h"
#include "InputManager.h"
#include "GameConfig.h"

void InputManager::InputCommand()
{
	myInput->KeyboardProcess();

//	Ű�� ���� ���� CommandQueue�� �Է�

//	Ű�� ���� ������ �����ִ� ������ �����ϴ� ����� ã�ƾ� ��
	for (auto& keyNum : playerKey::Player1CommandList)
	{
		bool isKeyInput = myInput->GetKeyDown(keyNum);
				
		if (isKeyInput == false)
			continue;

		//CommandWithTimeQueue.push_back(std::make_tuple(keyNum, 0));
		CommandWithTimeQueue.emplace_back(keyNum, 0);
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

//	��ȯ �߿� item ������ ���� ������ ��Ŵ...
//	erase �ϴ� ��� �ٷ� iterator�� ���������� ���� ��Ȳ�� ����
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
	//	�� Command�� �Է����κ��� ����� �ð��� �����Ѵ�
	for (auto& iter : CommandWithTimeQueue)
	{
		std::get<1>(iter) += 1;
	}
}