#include<windows.h>
#include"resource.h"
#include "Model.h"
#include "Controller.h"
#include "View.h"

HINSTANCE hInst;

INT_PTR CALLBACK WndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{

    DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, WndProc);
    return 0;
}


INT_PTR CALLBACK WndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    static Model model;
    static Controller controller(model);
    static View DataView(model, hDlg, IDC_EDIT_OUTPUT_DATA);
    static View ElementsView(model, hDlg, IDC_EDIT_OUTPUT_ELEMENTS);




    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:

        return (INT_PTR)TRUE;

    case WM_COMMAND:
        controller.ProcessInput(hDlg, wParam);
        return (INT_PTR)TRUE;
        break;
    }
    return (INT_PTR)FALSE;

    return 0;
}
