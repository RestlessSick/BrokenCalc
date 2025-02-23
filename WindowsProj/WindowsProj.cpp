// WindowsProj.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "winWindow.h"

// Глобальные переменные:

HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окнаstd::vector<HWND> hHandlers;
TCHAR buffer[MAX_LOADSTRING];


std::vector<HWND> hHandlers;
int LastAddedSimb = 0; 
std::wstring parse;
int szBuffer = 0;
const LPTSTR lpszText = new TCHAR[MAX_LOADSTRING];
int LastElemPosX = 30;
int LastElemPosY = 30;
RECT *tmp = new RECT;

// Отправить объявления функций, включенных в этот модуль кода:
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
BOOL AddElem(wchar_t*, wchar_t*, HMENU);

DWORD WINAPI refreshthread(LPVOID param) {
    while (1) {
        //SendMessage(hHandlers[0], WM_PAINT, 0, (LPARAM)L"bubilibu");
        Sleep(10000);
    }
    return 0;
}


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{


    // TODO: Разместите код здесь.

    // Инициализация глобальных строк

    // Выполнить инициализацию приложения:

    winWindow Wnd(hInstance, hPrevInstance, lpCmdLine, nCmdShow, WndProc);
    Wnd.Update();
    //HACCEL hAccelTable = LoadAccelerators(Wnd.getInst(), MAKEINTRESOURCE(IDC_WINDOWSPROJ));
    Wnd.AddElem(BUTTON, (wchar_t*)L"Del", (HMENU)DEL, 350, 80, 60, 35);         //hHandlers[1]
    Wnd.AddElem(EDIT, NULL, (HMENU)ID_TEXTBOX, 60, 30, 300, 35);                //hHandlers[2]


    Wnd.AddElem(BUTTON, (wchar_t*)L"1", (HMENU)BUT_1, 60, 80, 25, 20);          //hHandlers[3]
    Wnd.AddElem(BUTTON, (wchar_t*)L"2", (HMENU)BUT_2, 90, 80, 25, 20);          //hHandlers[4]
    Wnd.AddElem(BUTTON, (wchar_t*)L"3", (HMENU)BUT_3, 120, 80, 25, 20);         //hHandlers[5]
    Wnd.AddElem(BUTTON, (wchar_t*)L"4", (HMENU)BUT_4, 60, 110, 25, 20);         //hHandlers[6]
    Wnd.AddElem(BUTTON, (wchar_t*)L"5", (HMENU)BUT_5, 90, 110, 25, 20);         //hHandlers[7]
    Wnd.AddElem(BUTTON, (wchar_t*)L"6", (HMENU)BUT_6, 120, 110, 25, 20);        //hHandlers[8]
    Wnd.AddElem(BUTTON, (wchar_t*)L"7", (HMENU)BUT_7, 60, 140, 25, 20);         //hHandlers[9]
    Wnd.AddElem(BUTTON, (wchar_t*)L"8", (HMENU)BUT_8, 90, 140, 25, 20);         //hHandlers[10]
    Wnd.AddElem(BUTTON, (wchar_t*)L"9", (HMENU)BUT_9, 120, 140, 25, 20);        //hHandlers[11]
    Wnd.AddElem(BUTTON, (wchar_t*)L"0", (HMENU)BUT_0, 90, 170, 25, 20);         //hHandlers[12]


    Wnd.AddElem(BUTTON, (wchar_t*)L"+", (HMENU)BUT_PLUS, 170, 80, 25, 20);      //hHandlers[13]
    Wnd.AddElem(BUTTON, (wchar_t*)L"-", (HMENU)BUT_MINUS, 200, 80, 25, 20);     //hHandlers[14]
    Wnd.AddElem(BUTTON, (wchar_t*)L"/", (HMENU)BUT_DEVIDE, 230, 80, 25, 20);    //hHandlers[15]
    Wnd.AddElem(BUTTON, (wchar_t*)L"*", (HMENU)BUT_MULTIPLY, 170, 110, 25, 20); //hHandlers[16]
    Wnd.AddElem(BUTTON, (wchar_t*)L"^", (HMENU)BUT_DEGREE, 200, 110, 25, 20);   //hHandlers[17]
    Wnd.AddElem(BUTTON, (wchar_t*)L"s", (HMENU)BUT_ROOT, 230, 110, 25, 20);     //hHandlers[18]

    Wnd.AddElem(BUTTON, (wchar_t*)L"(", (HMENU)BUT_LEFT_BRASKET, 60, 170, 25, 20);     //hHandlers[19]
    Wnd.AddElem(BUTTON, (wchar_t*)L")", (HMENU)BUT_RIGHT_BRASKET, 120, 170, 25, 20);   //hHandlers[20]
    Wnd.AddElem(EDIT, NULL, (HMENU)ID_OUTPUT, 370, 30, 60, 35);                    //hHandlers[21]
    Wnd.AddElem(BUTTON, (wchar_t*)L"Solve", (HMENU)SOLVE, 280, 80, 60, 35);         //hHandlers[22]
    MSG msg;

    //SendMessage(hHandlers[0], WM_PAINT, 0, LPARAM(L"="));
    //HANDLE hThread = CreateThread(NULL, NULL, refreshthread, NULL, NULL, NULL);

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, Wnd.getAccelTable(), &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    //CloseHandle(hThread);
    return (int) msg.wParam;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)

{
    switch (message)
    {

    case WM_COMMAND:
    {
           
        int wmId = LOWORD(wParam);
        wchar_t* temp = new wchar_t[LastAddedSimb + 1];
        int i = 0;
        std::wfstream _input;
        std::wstring ans;
        // Разобрать выбор в меню:
        switch (wmId)
        {
            
        case DEL:
            if (parse.length() == 0) break;

            parse.pop_back();
            
            
            for (i; i < parse.length(); i++) {
                temp[i] = parse[i];
            }
            temp[i] = '\0';
            SendMessage(hHandlers[2], WM_SETTEXT, 0, (LPARAM)temp);
            break;

        case SOLVE:
            if (parse.length() == 0) break;
            STARTUPINFO si;
            PROCESS_INFORMATION pi;
            ZeroMemory(&si, sizeof(si));
            si.cb = sizeof(si);
            ZeroMemory(&pi, sizeof(pi));

            if (!CreateProcess(L"Testing_labwork_2.exe",
                (wchar_t*)std::wstring(L"Testing_labwork_2.exe " + parse).c_str(),
                NULL,
                NULL,
                NULL,
                CREATE_NO_WINDOW,
                NULL,
                NULL,
                &si,
                &pi)) {
                MessageBoxW(hHandlers[0], L"Плохо \nЛучше чем у тебя \nПошёл в жопу \nНадо будет с тобой ещё поболтать.", L"Как дела?", NULL);
                SendMessageW(hHandlers[0], WM_DESTROY, NULL, NULL);
            }
            else {
                WaitForSingleObject(pi.hProcess, INFINITE);
            }
            if (parse.length() == 0) break;

            parse.clear();


            for (i; i < parse.length(); i++) {
                temp[i] = parse[i];
            }
            temp[i] = '\0';
            SendMessage(hHandlers[2], WM_SETTEXT, 0, (LPARAM)temp);
            
            _input.open("ans.tmp", std::wfstream::in);
            _input >> ans;
            _input.close();
            remove("ans.tmp");
            SendMessage(hHandlers[21], WM_SETTEXT, 0, (LPARAM)ans.c_str());

            CloseHandle(pi.hProcess);

            break;
        
        case BUT_1:
            parse += L'1';
            for (i; i < parse.length(); i++) {
                temp[i] = parse[i];
            }
            temp[i] = '\0';
            SendMessage(hHandlers[2], WM_SETTEXT, 0, (LPARAM)temp);
            break;
        case BUT_2:
            parse += L'2';
            for (i; i < parse.length(); i++) {
                temp[i] = parse[i];
            }
            temp[i] = '\0';
            SendMessage(hHandlers[2], WM_SETTEXT, 0, (LPARAM)temp);
            break;
        case BUT_3:
            parse += L'3';
            for (i; i < parse.length(); i++) {
                temp[i] = parse[i];
            }
            temp[i] = '\0';
            SendMessage(hHandlers[2], WM_SETTEXT, 0, (LPARAM)temp);
            break;
        case BUT_4:
            parse += L'4';
            for (i; i < parse.length(); i++) {
                temp[i] = parse[i];
            }
            temp[i] = '\0';
            SendMessage(hHandlers[2], WM_SETTEXT, 0, (LPARAM)temp);
            break;
        case BUT_5:
            parse += L'5';
            for (i; i < parse.length(); i++) {
                temp[i] = parse[i];
            }
            temp[i] = '\0';
            SendMessage(hHandlers[2], WM_SETTEXT, 0, (LPARAM)temp);
            break;
        case BUT_6:
            parse += L'6';
            for (i; i < parse.length(); i++) {
                temp[i] = parse[i];
            }
            temp[i] = '\0';
            SendMessage(hHandlers[2], WM_SETTEXT, 0, (LPARAM)temp);
            break;
        case BUT_7:
            parse += L'7';
            for (i; i < parse.length(); i++) {
                temp[i] = parse[i];
            }
            temp[i] = '\0';
            SendMessage(hHandlers[2], WM_SETTEXT, 0, (LPARAM)temp);
            break;
        case BUT_8:
            parse += L'8';
            for (i; i < parse.length(); i++) {
                temp[i] = parse[i];
            }
            temp[i] = '\0';
            SendMessage(hHandlers[2], WM_SETTEXT, 0, (LPARAM)temp);
            break;
        case BUT_9:
            parse += L'9';
            for (i; i < parse.length(); i++) {
                temp[i] = parse[i];
            }
            temp[i] = '\0';
            SendMessage(hHandlers[2], WM_SETTEXT, 0, (LPARAM)temp);
            break;
        case BUT_0:
            parse += L'0';
            for (i; i < parse.length(); i++) {
                temp[i] = parse[i];
            }
            temp[i] = '\0';
            SendMessage(hHandlers[2], WM_SETTEXT, 0, (LPARAM)temp);
            break;
        case BUT_PLUS:
            parse += L'+';
            for (i; i < parse.length(); i++) {
                temp[i] = parse[i];
            }
            temp[i] = '\0';
            SendMessage(hHandlers[2], WM_SETTEXT, 0, (LPARAM)temp);
            break;
        case BUT_MINUS:
            parse += L'-';
            for (i; i < parse.length(); i++) {
                temp[i] = parse[i];
            }
            temp[i] = '\0';
            SendMessage(hHandlers[2], WM_SETTEXT, 0, (LPARAM)temp);
            break;
        case BUT_MULTIPLY:
            parse += L'*';
            for (i; i < parse.length(); i++) {
                temp[i] = parse[i];
            }
            temp[i] = '\0';
            SendMessage(hHandlers[2], WM_SETTEXT, 0, (LPARAM)temp);
            break;
        case BUT_DEVIDE:
            parse += L'/';
            for (i; i < parse.length(); i++) {
                temp[i] = parse[i];
            }
            temp[i] = '\0';
            SendMessage(hHandlers[2], WM_SETTEXT, 0, (LPARAM)temp);
            break;
        case BUT_DEGREE:
            parse += L'^';
            for (i; i < parse.length(); i++) {
                temp[i] = parse[i];
            }
            temp[i] = '\0';
            SendMessage(hHandlers[2], WM_SETTEXT, 0, (LPARAM)temp);
            break;
        case BUT_ROOT:
            parse += L's';
            for (i; i < parse.length(); i++) {
                temp[i] = parse[i];
            }
            temp[i] = '\0';
            SendMessage(hHandlers[2], WM_SETTEXT, 0, (LPARAM)temp);
            break;
        case BUT_LEFT_BRASKET:
            parse += L'(';
            for (i; i < parse.length(); i++) {
                temp[i] = parse[i];
            }
            temp[i] = '\0';
            SendMessage(hHandlers[2], WM_SETTEXT, 0, (LPARAM)temp);
            break;
        case BUT_RIGHT_BRASKET:
            parse += L')';
            for (i; i < parse.length(); i++) {
                temp[i] = parse[i];
            }
            temp[i] = '\0';
            SendMessage(hHandlers[2], WM_SETTEXT, 0, (LPARAM)temp);
            break;

        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;

        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;        

        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;


    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            TextOutW(hdc, 500, 500, (LPCWSTR)lParam, 10);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            EndPaint(hWnd, &ps);
        }
        break;


    case WM_CHAR:
    {
        int wmId = LOWORD(wParam);
        switch (wmId)

        {
        case 0x30:
            MessageBoxW(hHandlers[0], (wchar_t*)L"WORK", (wchar_t*)L"cap", NULL);
            break;
        default:
            break;
        }
    }
    break;


    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
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
