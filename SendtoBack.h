#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"

class SendtoBack : public Action
{
private:
	CFigure* Fig;

	int SF;

public:

	SendtoBack(ApplicationManager* pApp, CFigure* selected);

	//Reads  parameters
	virtual void ReadActionParameters();


	//Saves file
	virtual void Execute();
};

