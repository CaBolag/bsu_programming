#ifndef UNICODE
#define UNICODE
#endif 
#define _USE_MATH_DEFINES
#include <cmath>
#include <windows.h>
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
    static HBRUSH brush, brush1;
    static HPEN pen;
    static RECT rect;
    static int size_x, size_y;
    static int a, b, x_scr, y_scг; //Ёкранные координаты
    static double x = -M_PI,y, h,x1,x2=-M_PI;
    switch (uMsg)
    {
    case WM_DESTROY:
        KillTimer(hwnd, 1);
        DeleteObject(pen);
        DeleteObject(brush);
        DeleteObject(brush1);

        PostQuitMessage(0);
        return 0;
    case WM_SIZE:
        size_x = LOWORD(lParam);
        size_y = HIWORD(lParam);
        a = size_x / 2;
        b = size_y / 2;
        h = M_PI / a;
        InvalidateRect(hwnd, &rect, 1);
        break;
    case  WM_CREATE:
        SetTimer(hwnd, 1, 1000, NULL);
        brush = CreateSolidBrush(RGB(60, 179, 13));
        brush1 = CreateSolidBrush(RGB(255, 255, 255));
        pen = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
        break;
    case WM_TIMER:
        if (x2 < M_PI || x2 <= -M_PI) {
            x2 += (h/100);
        }
        else {
            x2 -= (h/100);
        }
        InvalidateRect(hwnd, NULL, TRUE);
        break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        GetClientRect(hwnd, &rect);
        FillRect(hdc, &rect, brush1);
        SelectObject(hdc, pen);
        //Oxy
        MoveToEx(hdc, 0, b, NULL);
        LineTo(hdc, size_x, b);
        MoveToEx(hdc, a, 0, NULL);
        LineTo(hdc, a, size_y);
        MoveToEx(hdc, 0, b, NULL);
        //y=sin(x)
     
        //h = M_PI / a; //Ўаг по оси x
        for (x1 = -M_PI, x_scr = 0; x1 < M_PI; x1 += h)
        {
            x_scr = (x1 + M_PI) * a / M_PI;
            y_scг = b - b * sin(x1);
            LineTo(hdc, x_scr, y_scг);
        }

        SelectObject(hdc, brush);

        x = (x2 + M_PI) * a / M_PI;
        y = b - b * sin(x2);
        Ellipse(hdc, x - 20, y - 20, x + 20, y + 20);
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
