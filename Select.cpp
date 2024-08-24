#include "Select.h"
#include"Actions/Action.h"
Select::Select(ApplicationManager* pApp) : Action(pApp) {} //,Select(SF), Paste(PF) ,SelectGfxInfo(SelGfxInfo) {}
void Select::ReadActionParameters() {
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Select figure(s)");
	pIn->GetPointClicked(P1.x, P1.y);
}
void Select::Execute() {
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (P1.y<UI.StatusBarHeight || P1.y>(UI.height - UI.StatusBarHeight)) {
		bool SF = false;
		pOut->PrintMessage("Please select a valid point!");
		while (SF == false) {
			pIn->GetPointClicked(P1.x, P1.y);
			if (P1.y < UI.StatusBarHeight || P1.y < (UI.height - UI.StatusBarHeight)) {
				SF = 1;
			}
		}
	}
	pOut->ClearStatusBar();
	CFigure* fig = pManager->GetFigure(P1.x, P1.y);
	//pManager->SetClipboard(NULL);
	if (fig != NULL) {
		if (fig->IsSelected()) {
			pOut->PrintMessage(fig->PrintInfo(pOut));
			//pManager->Set_LMessage(fig->PrintInfo(pOut));
			fig->SetSelected(true);
			pManager->Set_Selected(fig);
			SelectGfxInfo->isFilled = false;
			SelectGfxInfo->DrawClr = MAGENTA;
			SelectGfxInfo->FillClr = WHEAT;
		}
		else {

			fig->SetSelected(true);
			pManager->Set_Selected(fig);
		}
	}
	else {
		pOut->PrintMessage("No shape available to select");
		pManager->Unselect(fig);
		pManager->Set_Selected(NULL);
	}
}