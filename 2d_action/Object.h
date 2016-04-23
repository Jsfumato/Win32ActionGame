#pragma once
#include <atlimage.h>
#include <string>
#include "json.hpp"

class Object
{
public:
	virtual void Draw(HDC hdc);
	
	Object(){}

	Object(std::wstring folderName, std::wstring fileName)
	{
		SetSprite(folderName, fileName);
		SetJsonFile(folderName, L"Sprite-0004.json");

		m_spriteWidth = jsonFile["frames"][spriteIndex]["sourceSize"]["w"];
		m_spriteHeight = jsonFile["frames"][spriteIndex]["sourceSize"]["h"];
		
		m_nDestWidth = m_spriteWidth;
		m_nDestHeight = m_spriteHeight;
		m_nSrcWidth = m_spriteWidth;
		m_nSrcHeight = m_spriteHeight;
	}

	void SetObjectImageAttr(int xDest, int yDest, int nDestWidth, int nDestHeight, int xSrc, int ySrc, int nSrcWidth, int nSrcHeight, COLORREF transColor);
	void SetDestPosition(int xDest, int yDest);
	bool SetSprite(std::wstring folderName, std::wstring fileName);
	bool SetJsonFile(std::wstring folderName, std::wstring fileName);

	virtual ~Object()
	{
		objectImage.Destroy();
	};
	
protected:
	CImage objectImage;
	nlohmann::json jsonFile;

	int spriteIndex = 0;

	int m_spriteWidth;
	int m_spriteHeight;
	int m_nDestWidth;
	int m_nDestHeight;

	int m_xDest = 0;
	int m_yDest = 0;
	int m_xSrc = 0;
	int m_ySrc = 0;

	DWORD m_dwROP = SRCCOPY;

	int m_nSrcWidth;
	int m_nSrcHeight;
	COLORREF m_transColor = RGB(128, 255, 0);
};