#include <Windows.h>
#include <iostream>

LRESULT CALLBACK WndProc(
    _In_  HWND hwnd,
    _In_  UINT uMsg,
    _In_  WPARAM wParam,
    _In_  LPARAM lParam
);

void ammo() {
    LPCUWSTR gameWindow = L"Call of Duty®: BlackOps";
    HWND weed = FindWindow(0, gameWindow);
    DWORD process_ID;
    GetWindowThreadProcessId(weed, &process_ID);
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, process_ID);
    int based_value = 999999;
    DWORD based_client0 = sizeof(based_value);
    if (WriteProcessMemory(hProcess, (LPVOID)0x01C0A6C8, &based_value, based_client0, NULL))
        printf("yay");
    else
        printf("welp");
}

void god_mode() {
    LPCUWSTR gameWindow = L"Call of Duty®: BlackOps";
    HWND weed = FindWindow(0, gameWindow);
    DWORD process_ID;
    GetWindowThreadProcessId(weed, &process_ID);
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, process_ID);
    int based_value = 999999;
    DWORD based_client0 = sizeof(based_value);
    if (WriteProcessMemory(hProcess, (LPVOID)0x01A7987C, &based_value, based_client0, NULL))
        printf("yay");
    else
        printf("welp");
}

int WINAPI WinMain
(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow
)
{
    WNDCLASS WindowClass;
    WindowClass.style = 0;
    WindowClass.lpfnWndProc = (WNDPROC)WndProc;
    WindowClass.cbClsExtra = 0;
    WindowClass.cbWndExtra = 0;
    WindowClass.hInstance = hInstance;
    WindowClass.hIcon = LoadIcon(hInstance,
        (LPCTSTR)IDI_APPLICATION);
    WindowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    WindowClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    WindowClass.lpszMenuName = 0;
    WindowClass.lpszClassName = TEXT("Class");

    RegisterClass(&WindowClass);

    HWND hWnd;


    hWnd = CreateWindow(TEXT("Class"), TEXT("Public Cheater GUI BO 1 Zombie"),
        WS_OVERLAPPEDWINDOW, 0, 0, 500, 300, NULL, NULL, hInstance, NULL);

    //DeSiGn
    HWND cash_button;
    HWND gm_button;
    
    
    
    cash_button = CreateWindow(TEXT("button"), TEXT("CASH"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        10, 10, 80, 30, hWnd, (HMENU)10000, hInstance, NULL);

    gm_button = CreateWindow(TEXT("button"), TEXT("God Mode"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        100, 10, 80, 30, hWnd, (HMENU)20000, hInstance, NULL);

    ShowWindow(hWnd, nCmdShow);

    UpdateWindow(hWnd);

    MSG msg;

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wparam, LPARAM lParam)
{
    PAINTSTRUCT PS;
    switch (message)
    {
    case WM_CREATE:
       
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_PAINT:
        BeginPaint(hWnd, &PS);
        EndPaint(hWnd, &PS);
        break;
    case WM_COMMAND:
        if (LOWORD(wparam) == 10000)
            ammo();
        else if (LOWORD(wparam) == 20000)
            god_mode();


        
    default:
        return DefWindowProc(hWnd, message, wparam, lParam);
    }
    return 0;
}