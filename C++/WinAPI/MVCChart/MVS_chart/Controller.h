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

#include"Model.h"
#include"View.h"



class Controller {

public:
    Controller() = default;
    ~Controller() = default;
    static void InitDialog(HINSTANCE, int);
    static WPARAM Start();
    static INT_PTR CALLBACK InputMessage(HWND, UINT, WPARAM, LPARAM, Model);

private:
    //int number_;
    static HWND hListBox;
  
    //model.UploadData()
    //View view;
    //view.
    //int 

};





void Controller::InitDialog(HINSTANCE hInstance, int nCmdShow) {
        // Register the window class.
       const wchar_t CLASS_NAME[] = L"Sample Window Class";
       WNDCLASS wc = {};
       //wc.lpfnWndProc = InputMessage;
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
      /*  if (hwnd == NULL)
        {
         return 0;
        }*/
        ShowWindow(hwnd, nCmdShow);
        UpdateWindow(hwnd);
}


WPARAM Controller::Start() {
    // Run the message loop.
        MSG msg = {};
        while (GetMessage(&msg, NULL, 0, 0)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    return msg.wParam;
}



INT_PTR CALLBACK Controller::InputMessage(
    HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam,Model model) {
    switch (message) {
    case WM_COMMAND: {

        HMENU hMenu = GetMenu(hwnd);
        switch (LOWORD(wParam)) {
        case IDC_BUTTON_CHOOSE: {
            static TCHAR str_number[2]
            GetDlgItemText(hwnd, IDC_EDIT_NUMBER, str_number, sizeof(str_number));
            int number = std::stoi(str_number);
            model.UpdateSymbolsWordsFrequance(number);
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
                std::vector<std::string> strings;
                while (!in.eof()) {
                    getline(in, str);
                    std::wstring temp = std::wstring(str.begin(), str.end());
                    SendMessage(hListBox, LB_ADDSTRING, NULL, (LPARAM)(temp.c_str()));
                   strings.push_back(str);
                }
                model.SetStrings(strings);
            }
            InvalidateRect(hwnd, 0, 1);
            break;
        }
        default:
            break;
        }
    }

    case WM_PAINT: {
        View::Paint(hwnd,model);
        break;
    }
    }

    return (INT_PTR)FALSE;
}





int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
    Controller::InitDialog(hInstance, nCmdShow);
    return Controller::Start();
}

