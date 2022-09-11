#include <windows.h>
#include"Model.h"
#include<map>
class View {
    static void Paint(HWND hwnd,Model model) {
        hdc = BeginPaint(hwnd, &ps);
        GetClientRect(hwnd, &rect);
        SelectObject(hdc, brush);
        FillRect(hdc, &rect, brush);
        MoveToEx(hdc, 0, 0, 0);
        SetMapMode(hdc, MM_ANISOTROPIC);

        //words_frequance
        static std::map<std::string, int> words_frequance= model.GetWordsFrequance();
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

        static std::map<std::string, int> symbols_frequance=model.GetWordsFrequance();
        //std::map<char,int>::iterator it=(std::max_element(symbols_frequance.begin(), symbols_frequance.end(),
        //    [](const std::pair<char, int>& p1, const std::pair<char, int>& p2) {
        //        return p1.second < p2.second; }));
        //int max_value = it->second;

        SetWindowExtEx(hdc, 10, symbols_frequance.size(), NULL);
        SetViewportExtEx(hdc, 2 * rect.right / 3, rect.bottom, NULL);
        SetViewportOrgEx(hdc, 2 * rect.right / 3, 0, NULL);
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
    }
    static void Size(HWND hwnd) {
        InvalidateRect(hwnd, NULL, TRUE);
    }


private:
    static HDC hdc;
    static RECT rect;
    static HBRUSH brush;
    static HPEN pen, pen_old;
    static PAINTSTRUCT ps;
};


