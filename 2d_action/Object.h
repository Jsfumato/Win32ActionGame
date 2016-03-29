#pragma once
#include <atlimage.h>
#include <string>

class Object
{
public:
	virtual void Draw(HDC hdc);
	
	Object(){}

	Object(int sizeWidth, int sizeHeight)
		:m_spriteWidth(sizeWidth), m_spriteHeight(sizeHeight),
		m_xDest(0), m_yDest(0), m_nDestWidth(sizeWidth), m_nDestHeight(sizeHeight),
		m_xSrc(0), m_ySrc(0), m_nSrcWidth(sizeWidth), m_nSrcHeight(sizeHeight), 
		m_dwROP(SRCCOPY), m_transColor(RGB(128, 255, 0))
	{}

	void SetObjectImageAttr(int xDest, int yDest, int nDestWidth, int nDestHeight, int xSrc, int ySrc, int nSrcWidth, int nSrcHeight, COLORREF transColor);
	void SetDestPosition(int xDest, int yDest);
	bool SetSprite(std::wstring fileName, std::wstring folderName);

	virtual ~Object()
	{
		objectImage.Destroy();
	};
	
protected:
	CImage objectImage;

	int m_spriteWidth;
	int m_spriteHeight;

	int m_xDest;
	int m_yDest;
	int m_nDestWidth;
	int m_nDestHeight;
	int m_xSrc;
	int m_ySrc;
	DWORD m_dwROP;

	int m_nSrcWidth;
	int m_nSrcHeight;
	COLORREF m_transColor;
};