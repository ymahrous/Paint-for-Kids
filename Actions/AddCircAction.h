#include "Actions/Action.h"

class AddCircAction:public Action {
	private:
		Point P1, P2;
		GfxInfo RectGfxInfo;
	public:
		AddCircAction(ApplicationManager * pApp);

		//Reads rectangle parameters
		virtual void ReadActionParameters();

		//Add rectangle to the ApplicationManager
		virtual void Execute();

};