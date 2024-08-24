#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"

class BringtoFront : public Action
{
private:
	int SF;
	CFigure* Fig;

public:

	BringtoFront(ApplicationManager* pApp, CFigure* selected);

	//Reads  parameters
	virtual void ReadActionParameters();


	//Saves file
	virtual void Execute();
};

