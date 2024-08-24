#include "PasteAction.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

PasteAction::PasteAction(ApplicationManager* pApp, CFigure* Cb) :Action(pApp), Fig(Cb) {}

void PasteAction::ReadActionParameters() {
	//Get a Pointer to the Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Click at a new point");

	//Read and store in point P
	pIn->GetPointClicked(P.x, P.y);
	pOut->ClearStatusBar();
}

//Execute the action
void PasteAction::Execute() {
	Output* pOut = pManager->GetOutput();

	if (Fig != NULL) {
		//This action needs to read some parameters first
		ReadActionParameters();
		pManager->SetClipboard(NULL);
		CFigure* NewFig = Fig->Move(P);
		pManager->AddFigure(NewFig);
		pOut->PrintMessage("Pasted Successfully");
	}
	else {
		pOut->PrintMessage("Please select a figure first");
	}
}