#include "AddSquAction.h"
#include "CSquare.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

AddSquAction::AddSquAction(ApplicationManager* pApp):Action(pApp) {}

void AddSquAction::ReadActionParameters() {
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at Center of Square");

	//Read 1st corner and store in point P
	pIn->GetPointClicked(P.x, P.y);

	RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

//Execute the action
void AddSquAction::Execute() {
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a square with the parameters read from the user
	CSquare *C = new CSquare(P, RectGfxInfo);

	//Add the square to the list of figures
	pManager->AddFigure(C);
}