#include "stdafx.h"
#include "Character.h"

bool Character::SetProfile(std::wstring fileName, std::wstring folderName)
{
	WCHAR	szPath[256];
	GetCurrentDirectory(sizeof(szPath), szPath);

	wcscat_s(szPath, L"/Sprite/");
	wcscat_s(szPath, folderName.c_str());
	wcscat_s(szPath, L"/");
	wcscat_s(szPath, fileName.c_str());

	profileImage.Load(szPath);

	if (profileImage == NULL)
		return false;

	return true;
}

void Character::DrawProfile(HDC hdc, int xDest, int yDest)
{
	profileImage.BitBlt(hdc, xDest, yDest, 200, 300, 0, 0, SRCCOPY);
}

void Character::MoveCharacter(int direction)
{
	int dir = direction / abs(direction);

	int newXDest = m_xDest + 30 * dir;
	
	//후에 상수화 하여 window 크기를 변경해도 무리없도록 변경
	if ((newXDest < 0) || (newXDest > 500))
		return;

	m_xDest = newXDest;
}