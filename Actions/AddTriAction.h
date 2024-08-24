#pragma once
#include "Actions/Action.h"

class AddTriAction:public Action {
private:
	Point P1;
	Point P2;
	Point P3;
	GfxInfo RectGfxInfo;
public:
	AddTriAction(ApplicationManager* pApp);

	//Reads triangle parameters
	virtual void ReadActionParameters();

	//Add triangle to the ApplicationManager
	virtual void Execute();
};



