#pragma once
#include"Actions/Action.h"
#include"ApplicationManager.h"
class ChangeFclr : public Action
{
	CFigure* Fig;
	Point P1;
	color c;
public:
	ChangeFclr(ApplicationManager* pApp, CFigure* Selected);
	void ReadActionParameters();
	void Execute();
};

