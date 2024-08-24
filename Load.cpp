#include "Load.h"
#include "Figures\CRectangle.h"
#include "CTriangle.h"
#include "CSquare.h"
#include "CHexagon.h"
#include "CCircle.h"

Load::Load(ApplicationManager* pApp) :Action(pApp) {}

//Reads  parameters
void Load::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please enter name of file that you want to load");
	sfname = pIn->GetSrting(pOut);
	sfname = sfname + ".txt";
}


void Load::Execute() {
    string drwclr, fillclr;
    int counter;
    Output* pOut = pManager->GetOutput();

    ReadActionParameters();
    ifstream LoadFile(sfname);
    if (!LoadFile.is_open()) {
        pOut->PrintMessage("Error: Can't open file!");
        return;
    }
    else {
        pOut->ClearDrawArea();
    }

    // Read UI colors and counter
    LoadFile >> drwclr >> fillclr >> counter;
    UI.DrawColor = pManager->GetColorSting(drwclr);
    UI.FillColor = pManager->GetColorSting(fillclr);
    CFigure* newFigure;

    while (counter > 0) {
        string figureType;
        LoadFile >> figureType; // Read figure type from file

       

        //// Create an instance of the appropriate figure subclass based on the figure type
        //if (figureType == "Rectangle") {
        //    newFigure = new CRectangle;
        //}
        //else if (figureType == "Circle") {
        //    newFigure = new CCircle;
        //}
        //else if (figureType == "Triangle") {
        //    newFigure = new CTriangle;
        //}
        //else if (figureType == "Square") {
        //    newFigure = new CSquare;
        //}
        //else if (figureType == "Hexagon") {
        //    newFigure = new CHexagon;
        //}
        //else {
        //    // Handle error: Unknown figure type
        //    pOut->PrintMessage("Error: Unknown figure type in file!");
        //    return;
        //}

        // Load data for the figure from the file
        newFigure->Load(LoadFile);

        // Add the created figure object to the application manager
        pManager->AddFigure(newFigure);

        counter--;
    }

    pManager->UpdateInterface();
    pOut->ClearStatusBar();
    pOut->CreateStatusBar();
}