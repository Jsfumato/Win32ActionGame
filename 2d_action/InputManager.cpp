#include "stdafx.h"
#include "InputManager.h"
#include "GameConfig.h"

void InputManager::InputCommand()
{
	myInput->KeyboardProcess();

//	Ű�� ���� ���� CommandQueue�� �Է�
	for each (auto& keyNum in playerKey::Player1CommandList)
	{
		bool isKeyInput = myInput->GetKeyDown(keyNum);
		
		if (isKeyInput == false)
			continue;

		CommandWithTimeQueue.push_back(std::make_pair(keyNum, 0));
	}
	
//	�� Command�� �Է����κ��� ����� �ð��� �����Ѵ�
	for (auto& iter : CommandWithTimeQueue)
	{
		iter.second += 1;
	}

//	Closure ������ ���� ���
//	�� Command�� �Է����κ��� ����� �ð��� üũ�Ѵ�
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

//	��ȯ �߿� item ������ ���� ������ ��Ŵ...
//	erase �ϴ� ��� �ٷ� iterator�� ���������� ���� ��Ȳ�� �����Ѵ�
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

	���� ���� iterator ���� �����Ͽ� for ���� ������ ��쿡�� ���� ���ó�� �� ���ư��ϴٸ�
	�� auto�� �̿��� ĳ������ �Ϸ��ϸ� ���ϴ� Ÿ������ ���� �߷��� ���� �������
	�̹� EMC++ item 1, 2���� �� �����Դϴٸ� å���� �� ���� ������
	std::pair�� ���ؼ��� ���ܰ� �����ϴ� �ǰ���???
*/
