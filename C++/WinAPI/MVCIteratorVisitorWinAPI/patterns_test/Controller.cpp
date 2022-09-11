
#include"resource.h"
#include "Model.h"
#include "Controller.h"


void Controller::ProcessInput(HWND& h_wnd, const WPARAM& w_param) {
	switch (LOWORD(w_param))
	{
	case IDOK:
	case IDCANCEL:
		EndDialog(h_wnd, LOWORD(w_param));
		break;
	case IDC_BUTTON_ADD: {
		size_t element;
		element = GetDlgItemInt(h_wnd, IDC_EDIT_INPUT, NULL, true);
		/*TCHAR text[256];
		GetDlgItemText(h_wnd, IDC_EDIT_INPUT, text, 256);
		std::string text_str = text;
		std::stringstream string_stream(text_str);
		std::vector<int> elements;
		int element;
		while (string_stream >> element) {
			elements.push_back(element);
		}
		Set new_set(elements);*/

		model_.Add(element);
		SetDlgItemText(h_wnd, IDC_EDIT_INPUT, "");
		break;
	}
	
	case IDC_BUTTON_CARDINALITY:
	{
		CardinalityVisitor cardinality_visitor;
		model_.Cardinality(cardinality_visitor);
		size_t cardinality = cardinality_visitor.GetTotal();
		std::string card_str = std::to_string(cardinality);
		/*size_t size = model_.Size();
		std::string size_ = std::to_string(size);*/
		MessageBox(NULL, card_str.c_str(), "Cardinality", MB_OK);
	}

	case IDC_BUTTON_SAVE: {
		SaveVisitor visitor;
		std::string filename= "Output.txt";
		model_.Save(visitor, filename);
	}
	break;
	default:
		break;
	}
}