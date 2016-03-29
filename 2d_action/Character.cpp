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