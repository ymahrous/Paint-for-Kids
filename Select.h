#pragma once
#include"Actions/Action.h"
#include"ApplicationManager.h"
class Select : public Action
{

private:
	Point P1;
	GfxInfo* SelectGfxInfo;
public:
	Select(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
};

