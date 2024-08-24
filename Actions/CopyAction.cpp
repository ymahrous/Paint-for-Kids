#include "CopyAction.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

CopyAction::CopyAction(ApplicationManager* pApp, CFigure* Selected) :Action(pApp), Fig(Selected) {}

void CopyAction::ReadActionParameters() {
	//Get a Pointer to the Output Interfaces
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Copied Successfully");
	pOut->ClearStatusBar();
}

//Execute the action
void CopyAction::Execute() {
	Output* pOut = pManager->GetOutput();

	if (Fig != NULL) {
		//This action needs to read some parameters first
		ReadActionParameters();
		pManager->SetClipboard(Fig);
		pOut->PrintMessage("Copied Successfully");
	} else {
		pOut->PrintMessage("Please select a figure first");
	}
}