
#include "resource.h"
#include "Model.h"
#include "Controller.h"

void Controller::ProcessInput(HWND& h_wnd, const WPARAM& w_param) {
	switch (LOWORD(w_param))
	{
	case IDOK:
	case IDCANCEL:
		EndDialog(h_wnd, LOWORD(w_param));
		break;
	case IDC_BUTTON_SET: {
		TCHAR text[256];
		GetDlgItemText(h_wnd, IDC_EDIT_INPUT, text, 256);
		std::string text_str = text;
		std::stringstream string_stream(text_str);
		std::vector<int> elements;
		int element;
		while (string_stream >> element) {
			elements.push_back(element);
		}
		Set new_set(elements);

		model_.UpdateSet(new_set);
		SetDlgItemText(h_wnd, IDC_EDIT_INPUT, "");
		break;
	}

	case IDC_BUTTON_CLEAR:
		model_.Clear();
	case IDC_BUTTON_SIZE:
	{
		size_t size = model_.Size();
		std::string size_ = std::to_string(size);
		MessageBox(NULL, size_.c_str(), "Size", MB_OK);
	}
	break;
	default:
		break;
	}
}