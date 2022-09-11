#include "View.h"
View::View(Model& model, HWND& h_wnd,UINT edit_id) :model_(model), h_wnd_(h_wnd),edit_id_(edit_id) {
	model_.Attach(this);
}
void View::Update() {
	ToStringVisitor to_string_visitor;
	model_.Accept(to_string_visitor);
	std::string result = to_string_visitor.GetString();
	SetDlgItemText(h_wnd_, IDC_EDIT_OUTPUT, result.c_str());
}