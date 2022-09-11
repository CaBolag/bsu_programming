#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>
#include <cmath>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    // Register the window class.
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

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

    if (hwnd == NULL)
    {
        return 0;
    }

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
    static HPEN pen;
    static RECT rect;
    static int size_x, size_y, x, y;
    int count = 0;
    static int points[1000][2];
  

    switch (uMsg)
    {
    case WM_DESTROY:
       //KillTimer(hwnd, 1);
        PostQuitMessage(0);
        return 0;

    case WM_SIZE:
        size_x = LOWORD(lParam);
        size_y = HIWORD(lParam);
        InvalidateRect(hwnd, &rect, 1);
    case WM_CREATE:
        //SetTimer(hwnd, 1, 1000, NULL);
        pen = CreatePen(PS_SOLID,5,RGB(0,0,0));
        brush = CreateSolidBrush(RGB(60, 179, 13));
        break;

    case WM_TIMER:
        x = rand() % size_x;//вычісляется сінусоіда
        y = rand() % size_y;
        InvalidateRect(hwnd, NULL, TRUE);
        break;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        //brush = CreateSolidBrush(RGB(60, 179, 13));
        SelectObject(hdc, brush);
        GetClientRect(hwnd, &rect);
        //FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
        //Ellipse(hdc, x - 20, y - 20, x + 20, y + 20);
        FillRect(hdc, &rect, brush);
        SelectObject(hdc, pen);
        MoveToEx(hdc, 0, size_y / 2,0);
        LineTo(hdc, size_x, size_y / 2);

        MoveToEx(hdc, size_x/2, size_y, 0);
        LineTo(hdc, size_x/2, 0);
        DeleteObject(brush);
        for (size_t i = 0; x < size_x; i++) {
            x = i * size_x / 1000;
            y = -tan((double)x / 100) * size_y/8 + size_y/2;
            if (x < size_x) {
                points[count][0] = x;
                points[count][1] = y;
                count++;
            }
        }
        SelectObject(hdc, pen);
        for (size_t i = 0; i < count; i++)
        {
            SetPixel(hdc, points[i][0], points[i][1], RGB(0, 0, 0));
        }
        EndPaint(hwnd, &ps);
       
        break;

    }
    UpdateWindow(hwnd);
    return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}