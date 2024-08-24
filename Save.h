#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include <fstream>
#include "Figures\CFigure.h"

class Save: public Action
{
private:
	string sfname="name";

public:
	Save(ApplicationManager* pApp) ;

	//Reads  parameters
	virtual void ReadActionParameters();


	//Saves file
	virtual void Execute();

};

