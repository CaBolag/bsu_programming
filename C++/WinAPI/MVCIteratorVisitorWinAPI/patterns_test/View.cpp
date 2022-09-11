#include "View.h"

View::View(Model& model, HWND& h_wnd, UINT edit_id) :model_(model), h_wnd_(h_wnd), edit_id_(edit_id) {
	model_.Attach(this);
}
void View::Update() {
	std::string data_string=model_.GetStringOfData();
	std::string elements_string = model_.GetStringOfElements();
	SetDlgItemText(h_wnd_, IDC_EDIT_OUTPUT_DATA, data_string.c_str());
	SetDlgItemText(h_wnd_, IDC_EDIT_OUTPUT_ELEMENTS, elements_string.c_str());

}