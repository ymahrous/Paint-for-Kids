#include "Actions/Action.h"

class AddHexAction :public Action {
private:
	Point P; //Square Center
	GfxInfo RectGfxInfo;
public:
	AddHexAction(ApplicationManager* pApp);

	//Reads square parameters
	virtual void ReadActionParameters();

	//Add square to the ApplicationManager
	virtual void Execute();
};