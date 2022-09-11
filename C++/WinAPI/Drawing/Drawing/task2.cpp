#define _CRT_SECURE_NO_WARNINGS
#ifndef UNICODE
#define UNICODE
#endif 
#define COLORREF_BASE

#include <windows.h>
#include <xstring>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    // Register the window class.
    const wchar_t CLASS_NAME[] = L"Sample Window Class";
    WNDCLASS wc = { };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    HWND hMainWindow = NULL;
    RegisterClass(&wc);
    // Create the window.
    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Learn to Program Windows",    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style
        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
    );
    /*if (hwnd == NULL)
    {
     return 0;
    }*/
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    // Run the message loop.
    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static HBRUSH brush;
    static int size_x, size_y, x_scr, y_scã,r,g,b,radius,h; 
    static double x, y;
   // BYTE byRed, byGreen, byBlue;
    switch (uMsg)
    {
    case WM_DESTROY:
        
        PostQuitMessage(0);
        return 0;
    case WM_SIZE:
        size_x = LOWORD(lParam);
        size_y = HIWORD(lParam);
       
        break;
    case  WM_CREATE:
        break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        
        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
        //Oxy
        x_scr = size_x / 2;
        y_scã = size_y / 2;
        TCHAR text[10];
        int radix = 10;

        for (int i = 0, x = size_x, y = size_y; i != 10; y -= (size_y / 10), i++) {
            r = rand() * 255 / RAND_MAX;
            g = rand() * 255 / RAND_MAX;
            b = rand() * 255 / RAND_MAX;
            brush = CreateSolidBrush(RGB(r,g,b));
            SelectObject(hdc, brush);
            Ellipse(hdc, size_x / 2 - y / 2, size_y / 2 - y / 2, size_x / 2 + y / 2,
                size_y / 2 + y / 2);
            TextOut(hdc, size_x / 2, size_y / 2 - y / 2,
                _itow(i + 1, text, radix), wcslen(_itow(i + 1, text, radix)));
        }
      
        DeleteObject(brush);
        EndPaint(hwnd, &ps);
        break;
    }
    case WM_RBUTTONDOWN:
        KillTimer(hwnd, 1);
        PostQuitMessage(0);
        return 0;

        UpdateWindow(hwnd);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

