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

	virtual void DrawScene(HDC hdc) const;
	virtual void DoAction(int keyInput);
	virtual void InitScene();

	bool SetBackgroundImage(std::wstring bgName);
	bool AppendObject(Object* object);

	

private:
	CImage backgroundImage;
	std::vector<Object*> ObjectList;
};