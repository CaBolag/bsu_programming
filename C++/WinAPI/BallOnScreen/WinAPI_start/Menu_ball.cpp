#ifndef UNICODE
#define UNICODE
#endif
#include <windows.h>
#include "resource.h"
#include<string>
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void SelectColor(HWND hwndDlg, COLORREF& color);
BOOL CALLBACK Edit_R(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
static size_t n = 20;
static HINSTANCE hInst;



int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PWSTR pCmdLine, int nCmdShow) {
    // Register the window class.
    const wchar_t CLASS_NAME[] = L"Sample Window Class";
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
    HWND hMainWindow = NULL;
    RegisterClass(&wc);
    // Create the window.
    HWND hwnd =
        CreateWindowEx(0,                            // Optional window styles.
            CLASS_NAME,                   // Window class
            L"Learn to Program Windows",  // Window text
            WS_OVERLAPPEDWINDOW,          // Window style
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
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam,
    LPARAM lParam) {
    static HBRUSH brush;
    static COLORREF Color;
    static int size_x, size_y, x, y;
   
    static HWND hListBox;
    switch (uMsg) {
    /*case WM_CREATE:
        hListBox = CreateWindow(L"LISTBOX", NULL, WS_CHILD | WS_VISIBLE|WS_BORDER, 100, 150, 200, 300, hwnd, NULL, NULL, NULL);
        SendMessage(hListBox, LB_ADDSTRING, NULL, (LPARAM)TEXT("Item1"));
        break;*/
    case WM_DESTROY:
        KillTimer(hwnd, 1);
        PostQuitMessage(0);
        return 0;
    case WM_COMMAND: {
        HMENU hMenu = GetMenu(hwnd);
        switch (LOWORD(wParam)) {
        case ID_MENU_CHANGECOLOR:
            EnableMenuItem(hMenu, ID_MENU_CHANGECOLOR, MF_ENABLED);
            SelectColor(hwnd, Color);
            InvalidateRect(hwnd, 0, 1);
            break;
        case ID_MENU_DIALOG:
        {
            static bool check = true;
            if (check) {
                CheckMenuItem(hMenu, ID_MENU_DIALOG, MF_UNCHECKED);
                check = false;
            }
            else {
                CheckMenuItem(hMenu, ID_MENU_DIALOG, MF_UNCHECKED);
                check = true;
                if (DialogBox(hInst, MAKEINTRESOURCE(IDD_DIOLOG1), hwnd, Edit_R)) {
                    InvalidateRect(hwnd, 0, 1);
                }
            }
            break;
        }
        
        }
        break;
    }

    case WM_SIZE:
        size_x = LOWORD(lParam);
        size_y = HIWORD(lParam);
        break;
    case WM_CREATE:
        SetTimer(hwnd, 1, 1000, NULL);
        break;
    case WM_TIMER:
        x = rand() % size_x;
        y = rand() % size_y;
        InvalidateRect(hwnd, NULL, TRUE);
        break;
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
        brush = CreateSolidBrush(Color);
        SelectObject(hdc, brush);
        Ellipse(hdc, x - 20, y - 20, x + 20, y + 20);
        DeleteObject(brush);
        EndPaint(hwnd, &ps);
        break;
    }
                 UpdateWindow(hwnd);
                 return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}



void SelectColor(HWND hwndDlg, COLORREF& color) {
    static CHOOSECOLOR ccs;
    static COLORREF acrCustClr[16];
    ccs.lStructSize = sizeof(CHOOSECOLOR);
    ccs.hwndOwner = hwndDlg;
    ccs.rgbResult = color;
    ccs.Flags = CC_RGBINIT | CC_FULLOPEN;
    ccs.lpCustColors = (LPDWORD)acrCustClr;
    if (ChooseColor(&ccs) == TRUE) {
        color = ccs.rgbResult;
    }
}


BOOL CALLBACK Edit_R(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_INITDIALOG:
        SetDlgItemText(hwndDlg, IDC_EDIT1, L"Enter number");
        break;
    case WM_COMMAND: {
        switch (LOWORD(wParam)) {
        case IDC_BUTTON1: {
            TCHAR text[10];
            GetDlgItemText(hwndDlg, IDC_EDIT1, text, sizeof(text));
            n = _wtoi(text);
            break;
        }
                        return TRUE;
        }
        break;
    }
    case WM_CLOSE:
        EndDialog(hwndDlg, 0);
        break;

    default:
        return false;
    }
}
