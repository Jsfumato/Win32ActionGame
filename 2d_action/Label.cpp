#include "stdafx.h"
#include "Label.h"

void Label::Draw(HDC hdc)
{
	const int BUFFER_SIZE = 256;
	WCHAR buf[BUFFER_SIZE];

	wsprintf(buf, innerText.c_str());
	TextOut(hdc, m_xDest, m_yDest, buf, lstrlenW(buf));

	//DrawText(hdc, buf, -1, &rectOfText, DT_CENTER);
}

void Label::SetInnerText(std::wstring text)
{
	innerText = text;
}