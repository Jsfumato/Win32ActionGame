#pragma once
#include <atlimage.h>
#include <string>

class Object
{
public:
	virtual void Draw(HDC hdc);

	Object()
		:m_xDest(0), m_yDest(0), m_nDestWidth(800), m_nDestHeight(800), m_xSrc(0), m_ySrc(0), m_nSrcWidth(0), m_nSrcHeight(0), m_dwROP(SRCCOPY), m_transColor(RGB(128, 0, 128))
	{}

	void SetObjectImageAttr(int xDest, int yDest, int nDestWidth, int nDestHeight, int xSrc, int ySrc, int nSrcWidth, int nSrcHeight, COLORREF transColor);
	void SetDestPosition(int xDest, int yDest);
	bool SetSprite(std::wstring fileName, std::wstring folderName);

	virtual ~Object()
	{
		objectImage.Destroy();
	};

private:
	CImage objectImage;

protected:
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