#include "Figures/CFigure.h"
#include "Actions/Action.h"

class DeleteAction:public Action {
	private:
		CFigure* Fig;

	public:
		DeleteAction(ApplicationManager* pApp, CFigure* selected);

		void ReadActionParameters();

		//Execute the action
		void Execute();
};