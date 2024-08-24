#include "SendtoBack.h"


SendtoBack::SendtoBack(ApplicationManager* pApp, CFigure* selected) :Action(pApp), Fig(selected) {}

//Reads  parameters
void SendtoBack::ReadActionParameters() {
	SF = pManager->FigIndex();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("brought to front!");
}


//Saves file
void SendtoBack::Execute() {
	Output* pOut = pManager->GetOutput();

	if (Fig!=NULL) {
		ReadActionParameters();
		pManager->sendback(Fig);
	}
	else {
		pOut->PrintMessage("Please select a figure first");
	}

}