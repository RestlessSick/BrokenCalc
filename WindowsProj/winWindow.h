#include "framework.h"
#pragma once

extern int LastElemPosX;
extern int LastElemPosY;
extern std::vector<HWND> hHandlers;

class winWindow
{
private:

	WNDCLASSEXW wcex;
	HINSTANCE hInst;
	HINSTANCE hPrevInst;
	LPWSTR lpCmdLine;
	int nCmdShow;
	WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
	WCHAR szWindowClass[MAX_LOADSTRING];
	HACCEL hAccelTable /*= LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJ))*/;
	MSG msg;

public:
	//	Gettters and setters

	void setWcex(WNDCLASSEXW);
	WNDCLASSEXW getWcex();

	void setInst(HINSTANCE);
	HINSTANCE getInst();

	void setPrevInst(HINSTANCE);
	HINSTANCE getPrevInst();

	void setCmdLine(LPWSTR);
	LPWSTR getCmdLine();

	void setCmdShow(int);
	int getCmdShow();

	void setTitle(WCHAR *);
	WCHAR* getTitle();

	void setWndClass(WCHAR*);
	WCHAR* getWndClass();

	void setAccelTable(HACCEL);
	HACCEL getAccelTable();

	void setMsg(MSG);
	MSG getMsg();

	//	Constructors

	winWindow(HINSTANCE,
		HINSTANCE,
		LPWSTR,
		int,
		LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM));

	//	Main methods

	void Update();

	BOOL AddElem(wchar_t*, wchar_t*, HMENU);
	BOOL AddElem(wchar_t*, wchar_t*, HMENU, int x, int y);
	BOOL AddElem(wchar_t*, wchar_t*, HMENU, int x, int y, int l, int h);
};

