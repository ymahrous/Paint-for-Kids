#include "Actions/Action.h"

class ClearAllAction :public Action {
public:
	ClearAllAction(ApplicationManager* pApp);

	void ReadActionParameters();

	//Execute the action
	void Execute();
};