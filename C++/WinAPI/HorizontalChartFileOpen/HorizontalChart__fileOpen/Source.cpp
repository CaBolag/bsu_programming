#ifndef UNICODE
#define UNICODE
#endif
#include <windows.h>
#include"resource.h"
#include<string>
#include<fstream>
#include<map>
#include<sstream>
#include<vector>
#include<algorithm>
#include <iterator>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
//void SelectColor(HWND hwndDlg, COLORREF& color);
//BOOL CALLBACK Edit_R(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);

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

    HWND hWndButton = CreateWindow(L"button", L"Choose", WS_CHILD | WS_VISIBLE, 50, 0, 60, 20, hwnd, (HMENU)1001, hInst, NULL);
    CreateWindow(L"Edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER, 0, 0, 40, 20, hwnd, (HMENU)1002, NULL, NULL);
    //SetWindowText(hWndButton, "Click Me");


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

    static HDC hdc;
    static RECT rect;
    static HBRUSH brush;
    static HPEN pen, pen_old;
    static PAINTSTRUCT ps;
    static size_t number;
    static TCHAR str_number[2];
    static HWND hListBox;
    static std::map<char, int> symbols_frequance;
    static std::map<std::string, int> words_frequance;
    static std::vector<std::string> strings;

    switch (uMsg) {
    case WM_CREATE: {
        hListBox = CreateWindow(L"LISTBOX", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER, 0, 20, 300, 300, hwnd, NULL, NULL, NULL);
        pen = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
        brush = CreateSolidBrush(RGB(255, 255, 255));
        break;
    }

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_COMMAND: {

        HMENU hMenu = GetMenu(hwnd);
        switch (LOWORD(wParam)) {

        case IDC_BUTTON_CHOOSE: {

            GetDlgItemText(hwnd, IDC_EDIT_NUMBER, str_number, sizeof(str_number));
            number=std::stoi(str_number);
            std::string str = strings[number-1];
            std::stringstream in_str(str);
            std::string word;
            while (getline(in_str, word, ' ')) {
                words_frequance[word]++;
                for (int i = 0; i < word.size(); i++) {
                    char symbol = word[i];
                    symbols_frequance[symbol]++;
                }
            }
            break;
        }

        case ID_MENU_FILEOPEN: {
            OPENFILENAME ofn;
            ZeroMemory(&ofn, sizeof(ofn));
            TCHAR file_name[300] = { '\0' };
            ofn.lStructSize = sizeof(ofn);
            ofn.hwndOwner = NULL;
            ofn.lpstrFile = file_name;
            ofn.nMaxFile = sizeof(file_name);
            ofn.lpstrFilter = L"All Files\0*.*\0\0";
            ofn.nFilterIndex = 1;
            ofn.lpstrFileTitle = NULL;
            ofn.nMaxFileTitle = 0;
            ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;

            if (GetOpenFileName(&ofn)) {
                std::ifstream in(file_name);
                std::string str;
                 while (!in.eof()) {
                    getline(in, str);
                    std::wstring temp = std::wstring(str.begin(), str.end());
                    SendMessage(hListBox, LB_ADDSTRING, NULL, (LPARAM)(temp.c_str()));
                        strings.push_back(str);
                    }
                }
                InvalidateRect(hwnd, 0, 1);
                break;
            }
        default:
            break;
        }
    }

    case WM_PAINT:{
        hdc = BeginPaint(hwnd, &ps);
        GetClientRect(hwnd, &rect);
        SelectObject(hdc, brush);
        FillRect(hdc, &rect, brush);
        MoveToEx(hdc, 0, 0, 0);
        SetMapMode(hdc, MM_ANISOTROPIC);

        //words_frequance
        SetWindowExtEx(hdc, 3, words_frequance.size(), NULL);
        SetViewportExtEx(hdc, rect.right / 3, rect.bottom, NULL);
        SetViewportOrgEx(hdc, rect.right / 3, 0, NULL);
        pen = CreatePen(PS_SOLID, 0, RGB(255, 0, 0));
        pen_old = (HPEN)SelectObject(hdc, pen);
        MoveToEx(hdc, 0, 0, 0);

        int v[5]; 
        int i = 0;
        for (auto& item : words_frequance) {
            v[i] = item.second;
            i++;
        }
       
        for (size_t i = 0; i < words_frequance.size(); i++)
        {
            Rectangle(hdc, 0, i, v[i], i + 1);
        }

        //symbols_frequance 
        //std::map<char,int>::iterator it=(std::max_element(symbols_frequance.begin(), symbols_frequance.end(),
        //    [](const std::pair<char, int>& p1, const std::pair<char, int>& p2) {
        //        return p1.second < p2.second; }));
        //int max_value = it->second;
       
        SetWindowExtEx(hdc, 10, symbols_frequance.size(), NULL);
        SetViewportExtEx(hdc, 2*rect.right/3 , rect.bottom, NULL);
        SetViewportOrgEx(hdc, 2*rect.right/3, 0, NULL);
        i = 0;
        for (auto& item : symbols_frequance) {
            v[i] = item.second;
            i++;
        }
        for (size_t i = 0; i < symbols_frequance.size(); i++)
        {

            Rectangle(hdc, 0, i, v[i], i + 1);
        }

        SelectObject(hdc, pen_old);
        DeleteObject(pen);
        EndPaint(hwnd, &ps);
        break;
        }
    case WM_SIZE:
        
        InvalidateRect(hwnd, NULL, TRUE);
        break;

        UpdateWindow(hwnd);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}