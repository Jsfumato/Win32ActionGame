#pragma once
#include <atlimage.h>
#include <string>
#include "json.hpp"

class Object
{
public:
	virtual void Draw(HDC hdc);
	
	Object(){}

	Object(int sizeWidth, int sizeHeight)
		:m_spriteWidth(sizeWidth), m_spriteHeight(sizeHeight),
		m_nDestWidth(sizeWidth), m_nDestHeight(sizeHeight),
		m_nSrcWidth(sizeWidth), m_nSrcHeight(sizeHeight)
	{}

	void SetObjectImageAttr(int xDest, int yDest, int nDestWidth, int nDestHeight, int xSrc, int ySrc, int nSrcWidth, int nSrcHeight, COLORREF transColor);
	void SetDestPosition(int xDest, int yDest);
	bool SetSprite(std::wstring fileName, std::wstring folderName);
	bool SetJsonFile(std::wstring fileName, std::wstring folderName);

	virtual ~Object()
	{
		objectImage.Destroy();
	};
	
protected:
	CImage objectImage;
	nlohmann::json jsonFile;

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