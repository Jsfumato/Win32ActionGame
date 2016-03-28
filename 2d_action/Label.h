#pragma once
#include <string>
#include "Object.h"

class Label : public Object
{
public:
	Label(std::wstring text)
		:Object(), innerText(text){};
	
	void Draw(HDC hdc);
	void SetInnerText(std::wstring text);

	~Label(){};

private:
	std::wstring innerText;
};