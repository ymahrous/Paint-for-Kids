#include "Actions/Action.h"
#include "Figures/CFigure.h"

class CopyAction :public Action {
private:
	CFigure* Fig;
public:
	CopyAction(ApplicationManager* pApp, CFigure* Selected);

	//Reads square parameters
	virtual void ReadActionParameters();

	//Add square to the ApplicationManager
	virtual void Execute();
};