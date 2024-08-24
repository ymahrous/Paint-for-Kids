#include "ClearAllAction.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

ClearAllAction::ClearAllAction(ApplicationManager* pApp) :Action(pApp) {}

void ClearAllAction::ReadActionParameters() {
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();

	pOut->ClearDrawArea();
}

//Execute the action
void ClearAllAction::Execute() {
	//This action needs to read some parameters first
	ReadActionParameters();

	Output* pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
	pManager->DeleteAll();
}