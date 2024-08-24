#include "BringtoFront.h"


BringtoFront::BringtoFront(ApplicationManager* pApp, CFigure* selected) :Action(pApp), Fig(selected) {}

//Reads  parameters
void BringtoFront::ReadActionParameters() {
	SF = pManager->FigIndex();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Sent back!");
 }


//Saves file
void BringtoFront::Execute() {
	Output* pOut = pManager->GetOutput();

	if (Fig!=NULL) {
		ReadActionParameters();
		pManager->bringfront(Fig);
	}
	else {
		pOut->PrintMessage("Please select a figure first");
	}

 }