#include "Actions/Action.h"

class AddSquAction:public Action {
	private:
		Point P; //Square Center
		GfxInfo RectGfxInfo;
	public:
		AddSquAction(ApplicationManager* pApp);

		//Reads square parameters
		virtual void ReadActionParameters();

		//Add square to the ApplicationManager
		virtual void Execute();
};

