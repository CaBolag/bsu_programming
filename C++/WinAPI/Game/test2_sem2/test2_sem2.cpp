// test2_sem2.cpp : Определяет точку входа для приложения.
//

#include<vector>
#include"Spot.h"
#include"stdlib.h"
#include "framework.h"
#include "test2_sem2.h"
#include "commdlg.h"
#include<string>
#include<fstream>

#define MYKEY WM_USER+1
#define MYKEY1 WM_USER+1
#define MAX_LOADSTRING 100

BOOL CALLBACK ChangeSize(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
void SelectColor(HWND hwndDlg, COLORREF& color);
void InitCentres(std::vector<std::pair<int, int>>& centres, int M, int N);
void InitCenterNumberSpot(int x, int y, int& center_number_x, int& center_number_y, int& center_number);
void SendData(CHAR FileName[300], std::vector<Spot> spots);
void UploadData(CHAR FileName[300], std::vector<Spot>& spots);
void DrawSpots(HDC hdc, std::vector<Spot> spots);



// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);



HBRUSH brush;
HPEN pen1;
LOGBRUSH LogBrush;
static RECT rect;
static int M = 5, N = 5, step, count,x,y, center_number_cursor;
int center_number_x;
int center_number_y;
int center_number;
static double size_x, size_y;
bool timer=0;
std::vector<std::pair<int, int>> centres;
static std::vector<Spot> previous_spots;
static std::vector<Spot> spots;
COLORREF color_water= RGB(30, 144, 255);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_TEST2SEM2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TEST2SEM2));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TEST2SEM2));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDR_MENU1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
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

    static HPEN pen;

    switch (message)
    {
    case WM_KEYDOWN: {
        switch (wParam) {
        case VK_SPACE: {
            if (timer = 1) {
                timer = 0;
                KillTimer(hWnd, 1);
            }
            else {
                timer = 1;
                SetTimer(hWnd, 1, 10000, NULL);
            }
            InvalidateRect(hWnd, NULL, TRUE);
        } break;
        }
    }break;

    case WM_CREATE: {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                Spot spot(j, i);
                spots.push_back(spot);
            }
        }
        RegisterHotKey(hWnd, MYKEY, MOD_CONTROL, VK_F2);
        RegisterHotKey(hWnd, MYKEY1, VK_LBUTTON, VK_SHIFT);
        SetTimer(hWnd, 1, 10000, NULL);
        break;
    }
    case WM_MOUSEMOVE: {
        int x1 = (size_x - M * step) / 2;
        int y1 = (size_y - N * step) / 2;
        x = LOWORD(lParam);
        y = HIWORD(lParam);
        if (x<size_x-x1 && y<size_y-y1 && x>x1 &&y>y1) {
            InitCenterNumberSpot(x, y, center_number_x, center_number_y, center_number_cursor);
        }
        else {
            center_number_cursor = 0;
        }
        InvalidateRect(hWnd, 0, 1);

        break;
    }
    case WM_HOTKEY:
        if (MYKEY == (int)wParam) {
            DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, ChangeSize);
            InvalidateRect(hWnd, 0, 1);
            UnregisterHotKey(hWnd, MYKEY);

        }
        if (MYKEY1 == (int)wParam) {
            x = LOWORD(lParam);
            y = HIWORD(lParam);
            InitCenterNumberSpot(x, y, center_number_x, center_number_y, center_number);
            spots[center_number].figure = "source";
            InvalidateRect(hWnd, NULL, TRUE);
        }
        break;

    case WM_TIMER: {
        bool equal = false;
        for (int i = 0; i < previous_spots.size(); i++) {
            if (previous_spots[i].figure == spots[i].figure) {
                equal = true;
            };
        }
        if (equal) {
            return  MessageBox(NULL, (LPCSTR)"Nothing has changed!",(LPCSTR)"Status", MB_OK);
            break;
        }
        else {
            count++;
            previous_spots = spots;
        }
        InvalidateRect(hWnd, NULL, TRUE);
        break; 
    }

    case WM_SIZE: {
        size_x = LOWORD(lParam);
        size_y = HIWORD(lParam);
        if (M > N) {
            step = min(size_x, size_y) / max(M, N);
        }
        else {
            step = min(size_x, size_y) / min(M, N);
        }
        InitCentres(centres, M, N);
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    }

    case WM_LBUTTONUP:{
        x = LOWORD(lParam);
        y = HIWORD(lParam);
        InitCenterNumberSpot(x, y, center_number_x, center_number_y, center_number);
        spots[center_number].figure = "mountain";
        InvalidateRect(hWnd, NULL, TRUE);

    } break;
    case WM_RBUTTONUP: {
        x = LOWORD(lParam);
        y = HIWORD(lParam);
        InitCenterNumberSpot(x, y, center_number_x, center_number_y, center_number);
        spots[center_number].figure = "lowland";
        InvalidateRect(hWnd, NULL, TRUE);
    } break;
    case WM_COMMAND:
        {
        HMENU hMenu = GetMenu(hWnd);
        switch (LOWORD(wParam))
        {
        case ID_MENU_CHANGECOLOR:
            EnableMenuItem(hMenu, ID_MENU_CHANGECOLOR, MF_ENABLED);
            SelectColor(hWnd, color_water);
            InvalidateRect(hWnd, 0, 1);
            break;
        case ID_MENU_CHANGESIZE:
        {
            DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, ChangeSize);
                InvalidateRect(hWnd, 0, 1);
            break;
        }
       
        case ID_MENU_UPLOADSTATE:{
            OPENFILENAME ofn;
            ZeroMemory(&ofn, sizeof(ofn));
            CHAR FileName[300] = { '\0' };
            ofn.lStructSize = sizeof(ofn);
            ofn.hwndOwner = NULL;
            ofn.lpstrFile = FileName;
            ofn.nMaxFile = sizeof(FileName);
            ofn.lpstrFilter = "All Files\0*.*\0\0";
            ofn.nFilterIndex = 1;
            ofn.lpstrFileTitle = NULL;
            ofn.nMaxFileTitle = 0;
            ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
            if (GetOpenFileName(&ofn))
                UploadData(FileName, spots);
            InvalidateRect(hWnd, 0, 1);

            break;
        }

        case ID_MENU_SEND: {
            OPENFILENAME ofn;
            ZeroMemory(&ofn, sizeof(ofn));
            CHAR FileName[300] = { '\0' };
            ofn.lStructSize = sizeof(ofn);
            ofn.hwndOwner = NULL;
            ofn.lpstrFile = FileName;
            ofn.nMaxFile = sizeof(FileName);
            ofn.lpstrFilter = "All Files\0*.*\0\0";
            ofn.nFilterIndex = 1;
            ofn.lpstrFileTitle = NULL;
            ofn.nMaxFileTitle = 0;
            ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
            if (GetOpenFileName(&ofn))
            SendData(FileName, spots);
            break;
        }
        break;
        default:
            break;
        }
    }
        break;
    
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            GetClientRect(hWnd, &rect);
            LogBrush.lbColor = RGB(34, 139, 34);
            LogBrush.lbStyle = BS_SOLID;
            pen = ExtCreatePen(PS_GEOMETRIC | PS_DASHDOT, 3, &LogBrush, 0, NULL);
            
            SelectObject(hdc, pen);
            
            int x0 = (size_x - N * step) / 2;
            int y0 = (size_y - M * step) / 2;
            for (int i = 0; i <= M * step; i += step) {
                MoveToEx(hdc, 0 + x0, i + y0, NULL);
                LineTo(hdc, N * step + x0, i + y0);
            }
            for (int i = 0; i <= N * step; i += step) {
                MoveToEx(hdc, i + x0, 0 + y0, NULL);
                LineTo(hdc, i + x0, M * step + y0);
            }
            InitCentres(centres, M, N);
            DrawSpots(hdc, spots);
            
            std::string text = std::to_string(count);
            LPCSTR sw = text.c_str();
            TextOut(hdc, rect.right - 15, 5, sw, 2);
            

            //рамка вокург клетки
            pen1 = CreatePen(PS_SOLID, 2, RGB(255, 215, 0));
            SelectObject(hdc, pen1);
            MoveToEx(hdc, centres[center_number_cursor].first - step / 2, centres[center_number_cursor].second + step / 2, NULL);
            LineTo(hdc, centres[center_number_cursor].first + step / 2, centres[center_number_cursor].second + step / 2);
            LineTo(hdc, centres[center_number_cursor].first + step / 2, centres[center_number_cursor].second - step / 2);
            LineTo(hdc, centres[center_number_cursor].first - step / 2, centres[center_number_cursor].second - step / 2);
            LineTo(hdc, centres[center_number_cursor].first - step / 2, centres[center_number_cursor].second + step / 2);
            EndPaint(hWnd, &ps);

        }
        break;
    case WM_DESTROY:
        KillTimer(hWnd, 1);
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}




void InitCentres(std::vector<std::pair<int, int>>& centres, int M, int N) {
    if (!centres.empty()) {
        centres.clear();
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int x0 = (size_x - M * step) / 2;
            int y0 = (size_y - N * step) / 2;
            
            centres.push_back(std::make_pair(x0+j * step + step / 2,y0+ i * step + step / 2));
        }
    }
}


void SelectColor(HWND hwndDlg, COLORREF& color)
{
    static CHOOSECOLOR ccs;
    static COLORREF acrCustClr[16];
    ccs.lStructSize = sizeof(CHOOSECOLOR);
    ccs.hwndOwner = hwndDlg;
    ccs.rgbResult = color;
    ccs.Flags = CC_RGBINIT | CC_FULLOPEN;
    ccs.lpCustColors = (LPDWORD)acrCustClr;
    if (ChooseColor(&ccs) == TRUE)
        color = ccs.rgbResult;
}

BOOL CALLBACK ChangeSize(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_INITDIALOG: {
       
        CHAR text[20];
        CHAR text1[20];
        int radix = 10;
        /*SetDlgItemText(hwndDlg, IDC_EDIT1, _itoa(M, text, radix));
        SetDlgItemText(hwndDlg, IDC_EDIT2, _itoa(N, text1, radix));*/
    }
        break;
    case WM_COMMAND:
    {
        switch (LOWORD(wParam))
        {
        case IDOK: {
            static CHAR text1[100]{ 0 };
            static CHAR text2[100]{ 0 };
            GetDlgItemText(hwndDlg, IDC_EDIT1, text1, sizeof(text1));
            GetDlgItemText(hwndDlg, IDC_EDIT2, text2, sizeof(text1));

            int m = atoi(text1);
            int n = atoi(text2);
            if (m > 3 && m < 20 && n > 3 && n < 20) {
                M = m;
                N = n;
                return TRUE;
            }
            else {
                return  MessageBox(NULL, (LPCSTR)"Invalid value", (LPCSTR)"Error", MB_OK);
            }
           
            EndDialog(hwndDlg, 0);
            break;
        }
        
        default:
            break;
        }
        return TRUE;
    }
    case WM_CLOSE:
        EndDialog(hwndDlg, 0);
        break;
    default:
       
        return FALSE;
    }
    return TRUE;
}

void InitCenterNumberSpot(int x,int y,int& center_number_x, int& center_number_y, int& center_number) {
    center_number_x = (x - (size_x - M * step) / 2) / step;//номер ячейки - 1, по которой нажали, по x
    center_number_y = (y - (size_y - N * step) / 2) / step;
    center_number = (center_number_y)*M + center_number_x;
};


void SendData(CHAR FileName[300], std::vector<Spot> spots)
{
    std::ofstream out(FileName);
    out << M << " " << N << "\n";
    for (int i = 0; i < spots.size(); i++) {
        std::string figure = spots[i].figure;
        if (figure == "nothing") {
            out << 0;
        }
        else if (figure == "lowland") {
            out << 1;
        }
        else if (figure == "mountain") {
            out << 2;
        }
        else if (figure == "source") {
            out << 3;
        }
        else {
            out << 4;
        }
    }
}

void UploadData(CHAR FileName[300], std::vector<Spot>& spots) {
    std::ifstream in(FileName);
    in >> M;
    in >> N;
    int number;
    for (int i = 0; i < M*N; i++) {
        std::string figure = spots[i].figure;
        in >> number;
        if (number == 0) {
           
            spots[i].figure = "nothing";
        }
        else if (number == 1) {

            spots[i].figure = "lowland";
        }
        else if (number == 2) {

            spots[i].figure = "mountain";
        }
        if (number == 3) {

            spots[i].figure = "source";
        }
        else {
            spots[i].figure = "flooded";
        }
    }

}


void DrawSpots(HDC hdc, std::vector<Spot> spots) {
    for (int i = 0; i < spots.size(); i++) {
        if (spots[i].figure == "mountain") {
            brush = CreateSolidBrush(RGB(192, 192, 192));
            SelectObject(hdc, brush);

            POINT points[3];
            points[0].x = centres[i].first - step / 2;
            points[0].y = centres[i].second + step / 2;
            points[1].x = centres[i].first + step / 2;
            points[1].y = centres[i].second + step / 2;
            points[2].x = centres[i].first + step / 4;
            points[2].y = centres[i].second - step / 2;
            Polygon(hdc, points, 3);
        }
        if (spots[i].figure == "lowland") {
            brush = CreateSolidBrush(RGB(34, 139, 34));
            SelectObject(hdc, brush);

            Rectangle(hdc, centres[i].first - step / 2, centres[i].second + step / 2, centres[i].first + step / 2, centres[i].second - step / 2);

        }
        if (spots[i].figure == "source") {
            brush = CreateSolidBrush(color_water);
            SelectObject(hdc, brush);

            Ellipse(hdc, centres[i].first - step / 2, centres[i].second - step / 2, centres[i].first + step / 2, centres[i].second + step / 2);
            if (spots[i - 1].figure == "lowland") {
                spots[i - 1].figure = "flooded";
            }
            if (spots[i + 1].figure == "lowland") {
                spots[i + 1].figure = "flooded";
            }
            if (i + M <= M * N) {
                if (spots[i + M].figure == "lowland") {
                    spots[i + M].figure = "flooded";
                }
            }
            if (i - M >= 0) {
                if (spots[i - M].figure == "lowland") {
                    spots[i - M].figure = "flooded";
                }
            }
        }
        if (spots[i].figure == "flooded") {
            brush = CreateSolidBrush(color_water);
            SelectObject(hdc, brush);
            int temp = spots[i].x_ * M + spots[i].y_;
            Rectangle(hdc, centres[i].first - step / 2, centres[i].second + step / 2, centres[i].first + step / 2, centres[i].second - step / 2);
            if (spots[i - 1].figure == "lowland") {
                spots[i - 1].figure = "flooded";
            }
            if (spots[i + 1].figure == "lowland") {
                spots[i + 1].figure = "flooded";
            }
            if (i + M <= M * N) {
                if (spots[i + M].figure == "lowland") {
                    spots[i + M].figure = "flooded";
                }
            }
            if (i - M >= 0) {
                if (spots[i - M].figure == "lowland") {
                    spots[i - M].figure = "flooded";
                }
            }
        }
    }
}