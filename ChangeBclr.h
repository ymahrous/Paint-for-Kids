#pragma once
#include"Actions/Action.h"
#include"ApplicationManager.h"
class ChangeBclr : public Action
{
	CFigure* Fig;
	Point P1;
	color c;
public:
	ChangeBclr(ApplicationManager* pApp, CFigure* Selected);
	void ReadActionParameters();
	void Execute();
};

