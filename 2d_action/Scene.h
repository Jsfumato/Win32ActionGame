#pragma once
#include <atlimage.h>
#include <string>
#include <vector>
#include "Object.h"

class Scene
{
public:
	Scene(){};
	Scene(std::wstring bgName)
	{
		SetBackgroundImage(bgName);
		InitScene();
	};
	virtual ~Scene()
	{
		backgroundImage.Destroy();
		
		for (auto iter : ObjectList)
			delete iter;
	};

	void DrawScene(HDC hdc);
	bool SetBackgroundImage(std::wstring bgName);
	bool AppendObject(Object* object);

	virtual void InitScene();

private:
	CImage backgroundImage;
	std::vector<Object*> ObjectList;
};