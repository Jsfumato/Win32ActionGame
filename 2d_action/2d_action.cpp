// 2d_action.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include <memory>
#include "2d_action.h"
#include "GameManager.h"
#include "SceneManager.h"
#include "MyTime.h"

/*
	::	131088 Hwang JongSung
	::	Win32 API�� �̿��� action game ������ ��ǥ
*/

#define MAX_LOADSTRING 100

// Global Variables:
const int MAX_FPS = 40;
int			hardwareFps;

HINSTANCE hInst;								// current instance
HWND hWnd;
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

//	custom class
std::unique_ptr<CMyTime>		MyTime = nullptr;
std::unique_ptr<CMyInput>		MyInput = nullptr;

GameManager*	GameRuleManager = nullptr;
SceneManager*	SceneStackManager = nullptr;

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_MY2D_ACTION, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY2D_ACTION));

	//fps ������ ���� �ڵ�
	
	MyTime->ProcessTime();
	float time = MyTime->GetElapsedTime();
	hardwareFps = 1000 / time;

	float frameDelayed = hardwareFps / MAX_FPS;
	float currentFrame = 0;

	// Main message loop:
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			//Game Logic�� �ִ��� Win32�� �и��ϴ� ���� ����
			//�Ŀ� �ٸ� Game Engine�� �̽İ����� �������� ������ �� �־��...
			if (currentFrame++ < frameDelayed*30000)
				continue;

			HDC hdc = GetDC(hWnd);

			//�޸� ���� ����
			HDC		memoryDC = CreateCompatibleDC(hdc);
			HBITMAP memoryBitmap = CreateCompatibleBitmap(hdc, 800, 600);
			SelectObject(memoryDC, memoryBitmap);

			//Manager���� logic
			//���� SceneStack�� �ֻ��� Scene�� draw
			SceneStackManager->GetCurrentScene()->DrawScene(memoryDC);
			
			//GameManager�� �Է��� �ް�, �Է¿� ���� action�� ����
			GameRuleManager->GetKeyInput();
			GameRuleManager->DoAction();

			//double buffering
			BitBlt(hdc, 0, 0, 800, 600, memoryDC, 0, 0, SRCCOPY);

			DeleteObject(memoryBitmap);
			DeleteDC(memoryDC);

			ReleaseDC(hWnd, hdc);
			currentFrame = 0;
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY2D_ACTION));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_MY2D_ACTION);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   MyTime = std::make_unique<CMyTime>();
   MyTime->Init();
   MyInput = std::make_unique<CMyInput>();
   
   GameRuleManager = GameManager::GetInstance();
   SceneStackManager = SceneManager::GetInstance();
   SceneStackManager->Init();
   
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
