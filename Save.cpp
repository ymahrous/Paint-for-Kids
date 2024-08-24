#include "Save.h"


Save::Save(ApplicationManager* pApp) :Action(pApp) {}

//Reads  parameters
void Save::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please enter file name");
	sfname = pIn->GetSrting(pOut);
	sfname = sfname + ".txt";
}

//Saves file
void Save::Execute() {
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	
	ofstream Savedfile;
	Savedfile.open(sfname, ios::out);
	if (!Savedfile.is_open())
		pOut->PrintMessage("Error, couldn't open file");
	else {
		Savedfile << pManager->getCrntDraw(pOut->getCrntDrawColor())<<"\t" << pManager->getCrntDraw(pOut->getCrntFillColor()) << endl << pManager->getCount()<<endl;
	    pManager->SaveAll(Savedfile);
	}
	pOut->ClearStatusBar();
	Savedfile.close();

 }