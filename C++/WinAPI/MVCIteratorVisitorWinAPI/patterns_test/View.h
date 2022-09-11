#pragma once
#include<windows.h>


#include "Observer.h"
#include "Model.h"
#include "Controller.h"
#include "resource.h"
class View :
    public Observer
{
public:
	View(Model& model, HWND& h_wnd, UINT edit_id);
	void Update() override;
private:
	Model& model_;
	HWND h_wnd_;
	UINT edit_id_;

};

