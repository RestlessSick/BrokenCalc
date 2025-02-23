#include "winWindow.h"
//extern std::vector<HWND> hHandlers;

winWindow::winWindow(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPWSTR lpCmdLine,
	int nCmdShow,
	LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM))
{

	
	hInst = hInstance;
	hPrevInst = hPrevInstance;
	this->lpCmdLine = lpCmdLine;
	this->nCmdShow = nCmdShow;
	UNREFERENCED_PARAMETER(hPrevInst);
	UNREFERENCED_PARAMETER(this->lpCmdLine);

	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_WINDOWSPROJ, szWindowClass, MAX_LOADSTRING);
	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJ));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINDOWSPROJ);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	RegisterClassExW(&wcex);


	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJ));

	hHandlers.push_back(CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, 500, 300, nullptr, nullptr, hInstance, nullptr));

	//hHandlers.push_back(CreateWindow(BUTTON , _T("Not_Ok"), (WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON),
	//	10, 10, 80, 25, hHandlers[0], (HMENU)ID_BUTTON_NOT_OK, ((HINSTANCE)GetWindowLongPtr(hHandlers[0], GWLP_HINSTANCE)), NULL));
}

void winWindow::Update()
{
	ShowWindow(hHandlers[0], nCmdShow);
	UpdateWindow(hHandlers[0]);
}

void winWindow::setWcex(WNDCLASSEXW tmp) { wcex = tmp; }
WNDCLASSEXW winWindow::getWcex() { return wcex; }

void winWindow::setInst(HINSTANCE tmp) { hInst = tmp; }
HINSTANCE winWindow::getInst() { return hInst; }

void winWindow::setPrevInst(HINSTANCE tmp) { hPrevInst = tmp; }
HINSTANCE winWindow::getPrevInst() { return hPrevInst; }

void winWindow::setCmdLine(LPWSTR tmp) { lpCmdLine = tmp; }
LPWSTR winWindow::getCmdLine() { return lpCmdLine; }

void winWindow::setCmdShow(int tmp) { nCmdShow = tmp; }
int winWindow::getCmdShow() { return nCmdShow; }

void winWindow::setTitle(WCHAR* tmp) { memcpy(szTitle, tmp, MAX_LOADSTRING); }
WCHAR* winWindow::getTitle() { return szTitle; }

void winWindow::setWndClass(WCHAR* tmp) { memcpy(szWindowClass, tmp, MAX_LOADSTRING); };
WCHAR* winWindow::getWndClass() { return szWindowClass; }

void winWindow::setAccelTable(HACCEL tmp) { hAccelTable = tmp; }
HACCEL winWindow::getAccelTable() { return hAccelTable; }

void winWindow::setMsg(MSG tmp) { msg = tmp; }
MSG winWindow::getMsg() { return msg; }

BOOL winWindow::AddElem(wchar_t* type, wchar_t* text, HMENU hmId)
{
	if (type == BUTTON) {
		if (hHandlers.size() > 1)
		{
			hHandlers.push_back(CreateWindow(type, text, (WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON),
				LastElemPosX, LastElemPosY, 80, 25, hHandlers.at(0), hmId, ((HINSTANCE)GetWindowLongPtr(hHandlers[0], GWLP_HINSTANCE)), NULL));
			if (!hHandlers.back()) return FALSE;
			LastElemPosX += 30; LastElemPosY += 30;
			return TRUE;

		}
		else
		{
			hHandlers.push_back(CreateWindow(type, text, (WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON),
				LastElemPosX, LastElemPosY, 80, 25, hHandlers.at(0), hmId, ((HINSTANCE)GetWindowLongPtr(hHandlers[0], GWLP_HINSTANCE)), NULL));
			if (!hHandlers.back()) return FALSE;
			return TRUE;
		}
	}
	if (type == EDIT) {
		hHandlers.push_back(CreateWindow(L"Edit", text, WS_EX_CLIENTEDGE | WS_BORDER | WS_CHILD | WS_VISIBLE, LastElemPosX + 90, LastElemPosY, 100, 25, hHandlers.at(0),
			hmId, ((HINSTANCE)GetWindowLongPtr(hHandlers[0], GWLP_HINSTANCE)), NULL));
		if (!hHandlers.back()) return FALSE;
		LastElemPosX += 30; LastElemPosY += 30;
		return TRUE;
	}
}


BOOL winWindow::AddElem(wchar_t* type, wchar_t* text, HMENU hmId, int x, int y)
{
	if (type == BUTTON) {
		if (hHandlers.size() > 1)
		{
			hHandlers.push_back(CreateWindow(type, text, (WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON),
				x, y, 80, 25, hHandlers.at(0), hmId, ((HINSTANCE)GetWindowLongPtr(hHandlers[0], GWLP_HINSTANCE)), NULL));
			if (!hHandlers.back()) return FALSE;
			return TRUE;

		}
		else
		{
			hHandlers.push_back(CreateWindow(type, text, (WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON),
				x, y, 80, 25, hHandlers.at(0), hmId, ((HINSTANCE)GetWindowLongPtr(hHandlers[0], GWLP_HINSTANCE)), NULL));
			if (!hHandlers.back()) return FALSE;
			return TRUE;
		}
	}
	if (type == EDIT) {
		hHandlers.push_back(CreateWindow(L"Edit", text, WS_EX_CLIENTEDGE | WS_BORDER | WS_CHILD | WS_VISIBLE, x, y, 100, 25, hHandlers.at(0),
			hmId, ((HINSTANCE)GetWindowLongPtr(hHandlers[0], GWLP_HINSTANCE)), NULL));
		if (!hHandlers.back()) return FALSE;
		return TRUE;
	}
}

BOOL winWindow::AddElem(wchar_t* type, wchar_t* text, HMENU hmId, int x, int y, int l, int h)
{
	if (type == BUTTON) {
		if (hHandlers.size() > 1)
		{
			hHandlers.push_back(CreateWindow(type, text, (WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON),
				x, y, l, h, hHandlers.at(0), hmId, ((HINSTANCE)GetWindowLongPtr(hHandlers[0], GWLP_HINSTANCE)), NULL));
			if (!hHandlers.back()) return FALSE;
			return TRUE;

		}
		else
		{
			hHandlers.push_back(CreateWindow(type, text, (WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON),
				x, y, l, h, hHandlers.at(0), hmId, ((HINSTANCE)GetWindowLongPtr(hHandlers[0], GWLP_HINSTANCE)), NULL));
			if (!hHandlers.back()) return FALSE;
			return TRUE;
		}
	}
	if (type == EDIT) {
		hHandlers.push_back(CreateWindow(L"Edit", text, WS_EX_CLIENTEDGE | WS_BORDER | WS_CHILD | WS_VISIBLE, x, y, l, h, hHandlers.at(0),
			hmId, ((HINSTANCE)GetWindowLongPtr(hHandlers[0], GWLP_HINSTANCE)), NULL));
		if (!hHandlers.back()) return FALSE;
		return TRUE;
	}
}