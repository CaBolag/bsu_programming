#include <windows.h>

#include <fstream>
#include <sstream>
#include <string>

#include "resource1.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

bool edit = true;



int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PWSTR pCmdLine, int nCmdShow) {
    // Register the window class.
    const char CLASS_NAME[] = "Sample Window Class";
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
            "Learn to Program Windows",  // Window text
            WS_OVERLAPPEDWINDOW,          // Window style
            // Size and position
            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
            NULL,       // Parent window
            NULL,       // Menu
            hInstance,  // Instance handle
            NULL        // Additional application data
        );

  
       

    HWND hWndButton = CreateWindow("button", "Edit", WS_CHILD | WS_VISIBLE, 138, 189, 93, 14, hwnd, (HMENU)1012, hInstance, NULL);
    HWND hWndButton1 = CreateWindow("button", "->", WS_CHILD | WS_VISIBLE, 161, 98, 30, 17, hwnd, (HMENU)1005, hInstance, NULL);
    HWND hWndButton2 = CreateWindow("button", "<-", WS_CHILD | WS_VISIBLE, 157, 117, 43, 17, hwnd, (HMENU)1006, hInstance, NULL);
    HWND hWndButton3 = CreateWindow("button", "Delete", WS_CHILD | WS_VISIBLE, 25, 188, 104, 16, hwnd, (HMENU)1007, hInstance, NULL);

    CreateWindow("Edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER| ES_AUTOHSCROLL, 117, 14, 140, 25, hwnd, (HMENU)1008, NULL, NULL);
    HWND hListBox = CreateWindow("LISTBOX", NULL, LBS_SORT | LBS_NOINTEGRALHEIGHT | WS_VSCROLL | WS_TABSTOP| WS_CHILD | WS_VISIBLE | WS_BORDER, 17, 62, 132, 101, hwnd, (HMENU)1001, hInstance, NULL);
    HWND hListBox1 = CreateWindow("LISTBOX", NULL, LBS_SORT | LBS_NOINTEGRALHEIGHT | WS_VSCROLL | WS_TABSTOP| WS_CHILD | WS_VISIBLE | WS_BORDER, 210, 64, 135, 101, hwnd, (HMENU)1002, hInstance, NULL);


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





LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
  
    static HWND hListBox;
    TCHAR text[256];
    static int index;
  
    switch (uMsg)
    {
    case WM_COMMAND: 
    {
        HMENU hMenu = GetMenu(hwnd);
        switch (LOWORD(wParam)) {
        case ID_FILEOPEN_1: {

            OPENFILENAME ofn;
            ZeroMemory(&ofn, sizeof(ofn));
            TCHAR FileName[300] = { '\0' };
            ofn.lStructSize = sizeof(ofn);
            ofn.hwndOwner = NULL;
            ofn.lpstrFile = FileName;
            ofn.nMaxFile = sizeof(FileName);
            ofn.lpstrFilter = "All Files\0*.*\0.TXT\0";
            ofn.nFilterIndex = 1;
            ofn.lpstrFileTitle = NULL;
            ofn.nMaxFileTitle = NULL;
            ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
            if (GetOpenFileName(&ofn) == TRUE) {
                std::ifstream in(FileName);

                CHAR str[300];
                std::string temp;
                while (!in.eof()) {
                    getline(in, temp);
                    SendDlgItemMessage(hwnd, IDC_LIST1, LB_ADDSTRING, 0,
                        (LPARAM)temp.c_str());
                }
            }
        }
                          break;

        case ID_FILEOPEN_2: {

            OPENFILENAME ofn;
            ZeroMemory(&ofn, sizeof(ofn));
            TCHAR FileName[300] = { '\0' };
            ofn.lStructSize = sizeof(ofn);
            ofn.hwndOwner = NULL;
            ofn.lpstrFile = FileName;
            ofn.nMaxFile = sizeof(FileName);
            ofn.lpstrFilter = "All Files\0*.*\0.TXT\0";
            ofn.nFilterIndex = 1;
            ofn.lpstrFileTitle = NULL;
            ofn.nMaxFileTitle = NULL;
            ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
            if (GetOpenFileName(&ofn) == TRUE) {
                std::ifstream in(FileName);

                CHAR str[300];
                std::string temp;
                while (!in.eof()) {
                    getline(in, temp);
                    SendDlgItemMessage(hwnd, IDC_LIST2, LB_ADDSTRING, 0,
                        (LPARAM)temp.c_str());
                }
            }
        }
                          break;


        default:
            break;
        }

    }
    case IDC_BUTTON_EDIT: {
        if (edit) {
            index = SendMessage(GetDlgItem(hwnd, IDC_LIST1), LB_GETCURSEL, 0, 0);
            SendMessage(GetDlgItem(hwnd, IDC_LIST1), LB_GETTEXT, index,
                (LPARAM)text);
            SetDlgItemText(hwnd, IDC_EDIT1, text);
            edit = false;
        }
        else {
            SendMessage(GetDlgItem(hwnd, IDC_LIST1), LB_DELETESTRING, (WPARAM)index,
                0);
            GetDlgItemText(hwnd, IDC_EDIT1, text, 256);
            SendMessage(GetDlgItem(hwnd, IDC_LIST1), LB_INSERTSTRING, (WPARAM)index,
                (LPARAM)text);
            edit = true;
        }
    } break;


    case IDC_BUTTON_MOVE1: {
        TCHAR text[256];
        DlgDirSelectExA(hwnd, text, 256, IDC_LIST1);
        SendMessage(GetDlgItem(hwnd, IDC_LIST2), LB_ADDSTRING, 0,
            (LPARAM)text);
        SetFocus(GetDlgItem(hwnd, IDC_LIST1));

    } break;


    case IDC_BUTTON_MOVE2: {
        TCHAR text[256];
        DlgDirSelectExA(hwnd, text, 256, IDC_LIST2);
        SendMessage(GetDlgItem(hwnd, IDC_LIST1), LB_ADDSTRING, 0,
            (LPARAM)text);
        SetFocus(GetDlgItem(hwnd, IDC_LIST2));

    } break;


    case IDC_BUTTON_DELETE: {
        int k = SendMessage(GetDlgItem(hwnd, IDC_LIST1), LB_GETCURSEL, 0, 0);
        SendMessage(GetDlgItem(hwnd, IDC_LIST1)
            , LB_DELETESTRING, (WPARAM)k, 0);
        int n = SendMessage(GetDlgItem(hwnd, IDC_LIST2), LB_GETCURSEL, 0, 0);
        SendMessage(GetDlgItem(hwnd, IDC_LIST2), LB_DELETESTRING, (WPARAM)n,
            0);
    } break;

    
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
        }
        return 0;
    }
    