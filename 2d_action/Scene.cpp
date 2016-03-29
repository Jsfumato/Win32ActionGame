#include "stdafx.h"
#include "Scene.h"

void Scene::DrawScene(HDC hdc) const
{
	backgroundImage.BitBlt(hdc, 0, 0, 800, 600, 0, 0, SRCCOPY);

	for (auto iter : ObjectList)
	{
		iter->Draw(hdc);
	}
}

void Scene::DoAction(int keyInput)
{

}

bool Scene::SetBackgroundImage(std::wstring bgName)
{
	WCHAR	szPath[256];
	GetCurrentDirectory(sizeof(szPath), szPath);

	wcscat_s(szPath, L"/Sprite/BackgroundImage/");
	wcscat_s(szPath, bgName.c_str());

	backgroundImage.Load(szPath);

	if (backgroundImage == NULL)
		return false;

	return true;
}

bool Scene::AppendObject(Object* object)
{
	ObjectList.push_back(object);

	if (ObjectList.back() != object)
		return false;

	return true;
}

void Scene::InitScene()
{
	//Scene 기본 초기화 작업 명시
}