#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure
	CFigure* ID;
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	CFigure* sb;
	CFigure* bf;
	CFigure* Clipboard;  //Pointer to copied/cut figure
	string LMessage;
public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
		
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	void DeleteAll();
	void Delete(CFigure* df);
	void SetClipboard(CFigure* Figu);

	void SaveAll(ofstream& OutFile);
	int getCount();
	string getCrntDraw(color c);
	color GetColorSting(string s);
	void bringfront(CFigure* bf);
	void sendback(CFigure* sb);


	void Set_Selected(CFigure* fig);  //
	void Set_LMessage(string s);  //
	void Unselect(CFigure* fig);  //
	int SelFigCount(); 
	int FigIndex();


};

#endif