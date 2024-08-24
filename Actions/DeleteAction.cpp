#include "DeleteAction.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

DeleteAction::DeleteAction(ApplicationManager* pApp, CFigure* selected):Action(pApp), Fig(selected) {}

void DeleteAction::ReadActionParameters() {
	//Get a Pointer to the Output Interface
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Deleted Successfully");
	pOut->ClearDrawArea();
}

//Execute the action
void DeleteAction::Execute() {
	Output* pOut = pManager->GetOutput();

	if (Fig != NULL) {
		//This action needs to read some parameters first
		ReadActionParameters();
		pManager->Delete(Fig);
	}
	else {
		pOut->PrintMessage("Please select a figure first");
	}
}