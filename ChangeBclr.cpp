#include "ChangeBclr.h"
ChangeBclr::ChangeBclr(ApplicationManager* pApp, CFigure* Selected) :Action(pApp), Fig(Selected) {}

void ChangeBclr::ReadActionParameters() {
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Please a select a color!");
	ActionType test;
	test = pIn->GetUserAction();
	switch (test) {
	case C_BLACK:
		c = BLACK;
		break;
	case C_YELLOW:
		c = YELLOW;
		break;
	case C_ORANGE:
		c = ORANGE;
		break;
	case C_RED:
		c = RED;
		break;
	case C_GREEN:
		c = GREEN;
		break;
	case C_BLUE:
		c = BLUE;
		break;
	}

}
void ChangeBclr::Execute() {
	ReadActionParameters();
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	if (pManager->SelFigCount() == 1) { //selected figure count =1
		Fig->ChngDrawClr(c);
		pOut->PrintMessage("Change color changed!");
	}
	else if (pManager->SelFigCount() == 0) {  //selected figure count =0
		pOut->PrintMessage("A figure must be selected first");
		//pManager->Set_LMessage("A figure must be selected first");
	}
	else {
		pOut->PrintMessage("Only one figure must be selected");
		//pManager->Set_LMessage("Only one figure must be selected");
	}
}
