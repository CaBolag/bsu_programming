#pragma once
#include<windows.h>

//#include"Model.h"
//#include "resource.h"

class Model;

class Controller
{
public:
	Controller(Model& model) :model_(model) {};
	void ProcessInput(HWND& h_wnd, const WPARAM& w_param);
private:
	Model& model_;
};
