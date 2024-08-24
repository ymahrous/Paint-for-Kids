#include "Actions/Action.h"
#include "Figures/CFigure.h"

class PasteAction :public Action {
private:
	Point P;
	CFigure* Fig;
public:
	PasteAction(ApplicationManager* pApp, CFigure* Cb);

	//Reads square parameters
	virtual void ReadActionParameters();

	//Add square to the ApplicationManager
	virtual void Execute();
};