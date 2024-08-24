#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include <fstream>
#include "Figures\CFigure.h"
class Load: public Action 
{
private:
	string sfname = "name";

public:
	Load(ApplicationManager* pApp);

	//Reads  parameters
	virtual void ReadActionParameters();


	//Saves file
	virtual void Execute();
};

