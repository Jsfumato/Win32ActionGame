#pragma once
#include <string>
#include "Object.h"

class Label : public Object
{
public:
	Label(std::wstring text)
		:Object(), innerText(text)
	{
		SetRect(&rectOfText, m_xDest, m_yDest, m_nDestWidth, m_nDestHeight);
	};
	
	void Draw(HDC hdc);
	void SetInnerText(std::wstring text);

	~Label(){};

private:
	std::wstring innerText;
	RECT rectOfText;
};