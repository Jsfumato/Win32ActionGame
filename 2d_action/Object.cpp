#include "stdafx.h"
#include "Object.h"

void Object::Draw(HDC hdc)
{
	if (objectImage == NULL)
		return;

	//objectImage.BitBlt(hdc, m_xDest, m_yDest, m_nDestWidth, m_nDestHeight, m_xSrc, m_ySrc, m_dwROP);
	objectImage.TransparentBlt(hdc, m_xDest, m_yDest, m_nDestWidth, m_nDestHeight, m_xSrc, m_ySrc, m_nSrcWidth, m_nSrcHeight, m_transColor);
}																								   

bool Object::SetSprite(std::wstring fileName, std::wstring folderName)
{
	WCHAR	szPath[256];
	GetCurrentDirectory(sizeof(szPath), szPath);

	wcscat_s(szPath, L"/Sprite/");
	wcscat_s(szPath, folderName.c_str());
	wcscat_s(szPath, L"/");
	wcscat_s(szPath, fileName.c_str());

	objectImage.Load(szPath);

	if (objectImage == NULL)
		return false;

	return true;
}

void Object::SetObjectImageAttr(int xDest, int yDest, int nDestWidth, int nDestHeight, int xSrc, int ySrc, int nSrcWidth, int nSrcHeight, COLORREF transColor)
{
	m_xDest = xDest;
	m_yDest = yDest;
	m_nDestWidth = nDestWidth;
	m_nDestHeight = nDestHeight;
	m_xSrc = xSrc;
	m_ySrc = ySrc;
	m_nSrcWidth = nSrcWidth;
	m_nSrcHeight = nSrcHeight;
	m_transColor = transColor;
}

void Object::SetDestPosition(int xDest, int yDest)
{
	m_xDest = xDest;
	m_yDest = yDest;
}