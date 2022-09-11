
#include <windows.h>
#include"resource.h"
#include<fstream>
#include<string>
#include<sstream>

INT_PTR CALLBACK DlgMain(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
		ShowWindow(GetDlgItem(hwnd, IDC_BUTTON2), SW_HIDE);
		ShowWindow(GetDlgItem(hwnd, IDC_EDIT1), SW_HIDE);
		break;
	case WM_CLOSE:
		EndDialog(hwnd, 0);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON1:
		{
			OPENFILENAME ofn;
			ZeroMemory(&ofn, sizeof(ofn));
			TCHAR FileName[300] = { '\0' };
			ofn.lStructSize = sizeof(ofn);
			ofn.hwndOwner = NULL;
			ofn.lpstrFile = FileName;
			ofn.nMaxFile = sizeof(FileName);
			ofn.lpstrFilter = "All Files\0*.*\0\0";
			ofn.nFilterIndex = 1;
			ofn.lpstrFileTitle = NULL;
			ofn.nMaxFileTitle = 0;
			ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;

			if (GetOpenFileName(&ofn)) {
				std::ifstream in(FileName);
				int count = 0, sizeline = 0;
				
				CHAR str[300];
				//std::wstring s;
				std::string temp;
				while (!in.eof()) {
					
					getline(in, temp);
					//std::stringstream ss(s);
					//std::wstring temp((wchar_t*)s.c_str());
					//std::wstring temp(s.begin(), s.end());
					count++;
					if (sizeline < temp.size()) {
						sizeline = temp.size();
						SendDlgItemMessage(hwnd, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)temp.c_str());
					}

				}
				sprintf_s(str,"Number of lines:%d\nMax line length%d\n file name%s",count,sizeline,FileName);
				SetDlgItemText(hwnd, IDC_STATIC1, str);
			}
		}

		default:
			break;
		}
		return TRUE;
	default:
		return FALSE;
		break;
	}
	return TRUE;

}
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgMain);
	return 0;
}