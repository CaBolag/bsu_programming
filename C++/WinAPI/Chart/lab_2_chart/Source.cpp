//#ifndef UNICODE
//#define UNICODE
//#endif
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<cmath>
#include <windows.h>
#include "resource.h"
#include<string>
#include<iostream>
#include<vector>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void SelectColor(HWND hwndDlg, COLORREF& color);
BOOL CALLBACK Add(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
static HINSTANCE hInst;

struct Student {
    std::string surname;
    int mark;
    COLORREF color;
};

 static std::vector<Student> students;
 int students_number=3;
static int full_mark=10;

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
    static HBRUSH brush;
    static COLORREF color;
    static int size_x, size_y, x, y;
    int x1, y1, x2, y2; // Координаты «долек пирога»
    static short xw, yw, r; // Координаты и радиус диаграммы
    // Радиус диаграммы зависит от размеров клиентской области
    r = yw < xw ? yw / 2 : xw / 2;
    Student student;
    student.surname = "dfdf";
    student.mark = 2;
    color = RGB(128, 0, 0);
    student.color = color;
    students.push_back(student);
    student.surname = "dfdf";
    student.mark = 3;
    color = RGB(0, 128, 0);
    student.color = color;
    students.push_back(student);
    student.surname = "scsxs";
    student.mark = 5;
    color = RGB(0, 0, 128);
    student.color = color;
    students.push_back(student);
    
    switch (uMsg)
    {

    case WM_COMMAND: {
        HMENU hMenu = GetMenu(hwnd);
        switch (LOWORD(wParam)) {
        case ID_MENU_ADD:

            if (DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hwnd, Add)) {
                InvalidateRect(hwnd, 0, 1);
            }

            break;
        default:
            break;
        }
    }

    case WM_SIZE:
        size_x = LOWORD(lParam);
        size_y = HIWORD(lParam);
            xw = LOWORD(lParam) / 2;
 
            yw = HIWORD(lParam) / 2;

        break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        HPEN pen = CreatePen(PS_DASH, 3, RGB(0, 0, 0));
        SelectObject(hdc, pen);
        MoveToEx(hdc, 20, size_y / 2, NULL);
        LineTo(hdc, size_x / 3, size_y / 2);
        MoveToEx(hdc, 20, 20, NULL);
        LineTo(hdc, 20, size_y / 2);

        int h = 20;
        char text[10];
        int radix = 10;
        for (int i = 0; i < students_number; i++) {
            int y = students[i].mark;
            brush = CreateSolidBrush(students[i].color);
            SelectObject(hdc, brush);
            Rectangle(hdc, 20 + h, (size_y / 2) - 20 * y, 40 + h, size_y / 2);
            TextOut(hdc, 20 + h, (size_y / 2) - 23 * y, (students[i].surname).c_str(),
                (students[i].surname).length());

            TextOut(hdc, 10 + h, (size_y / 2) - 23 * y, _itoa(y, text, radix),
                strlen(_itoa(y, text, radix)));
            h += 30;
        }

        // Круговая диаграмма
        double step2 = 2*M_PI / full_mark;
        step2 = round(step2 * 10000000) / 10000000;
        double first_angle = 0.0, second_angle = 0.0;
        double x1, x2, y1, y2;
        for (int i = 0; i < students.size(); i++) {
            static double xw = size_x * 0.75, yw = size_y * 0.5, r;
            r = min(size_x / 2.2, size_y / 2.2);

            first_angle = second_angle;
            second_angle = students[i].mark * step2 + first_angle;

            x1 = (xw + r * cos(first_angle));
            y1 = (yw - r * sin(first_angle));
            x2 = (xw + r * cos(second_angle));
            y2 = (yw - r * sin(second_angle));

            brush = CreateSolidBrush(students[i].color);
            SelectObject(hdc, brush);
            Pie(hdc, xw - r, yw - r, xw + r, yw + r, x1, y1, x2, y2);
        }

        //Student student = students[i];
        //int r = 100;
        //double p2 = 2 * M_PI;
        //HBRUSH hNew = CreateSolidBrush(student.color);
        //SelectObject(hdc, hNew);
        //// Вычисляем координаты «дольки»
        //x1 = (int)(xw + r * cos(p2 * student.mark / full_mark));
        //y1 = (int)(yw - r * sin(p2 * student.mark / full_mark));
        //x2 = (int)(xw + r * cos(p2 * students[i+1].mark / full_mark));
        //y2 = (int)(yw - r * sin(p2 * students[i+1].mark / full_mark));
        //// Изображаем «пирог»
        //Pie(hdc, xw - r, yw - r, xw + r, yw + r, x1, y1, x2, y2);
        
        UpdateWindow(hwnd);
        DeleteObject(brush);
        DeleteObject(pen);
        EndPaint(hwnd, &ps);
    }
    break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}




    void SelectColor(HWND hwndDlg, COLORREF & color) {
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


    BOOL CALLBACK Add(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) {
        COLORREF color=RGB(256,0,0);
        Student student;
        switch (uMsg) {
        case WM_INITDIALOG:
         
            SetDlgItemText(hwndDlg, IDC_EDITSURNAME, "Enter a surname");
            SetDlgItemText(hwndDlg, IDC_EDITMARK, "Enter a number");

            break;
        case WM_COMMAND: {
            
            switch (LOWORD(wParam)) {
            case IDC_BUTTONCHANECOLOR:
                students_number++;
                SelectColor(hwndDlg, color);
                students[students_number - 1].color=color;
                
                break;

            case IDC_BUTTONADD:
            {

                CHAR surname[20];
                GetDlgItemText(hwndDlg, IDC_EDITSURNAME, surname, sizeof(surname));
                SetDlgItemText(hwndDlg, IDC_EDITSURNAME, "Enter a surname");
              

                CHAR text[10];
                GetDlgItemText(hwndDlg, IDC_EDITMARK, text, sizeof(text));
                SetDlgItemText(hwndDlg, IDC_EDITMARK, "Enter a number");

                students[students_number - 1].surname = (std::string)surname;
                students[students_number - 1].mark= atoi(text);
                
                students.push_back(student);
                full_mark+= atoi(text);
               
                break;

            }

            case IDC_BUTTONFINISH:
                EndDialog(hwndDlg, 0);
                break;

            case WM_CLOSE:
                EndDialog(hwndDlg, 0);
                break;
            default:
                break;
            }
        }

        default:
            return false;
        }
    }
        