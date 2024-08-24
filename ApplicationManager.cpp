#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "AddSquAction.h"
#include "AddHexAction.h"
#include "AddTriAction.h"
#include "AddCircAction.h"
#include "ClearAllAction.h"
#include "Save.h"
#include "Load.h"
#include "BringtoFront.h"
#include "SendtoBack.h"
#include "Select.h"
#include "CopyAction.h"
#include "PasteAction.h"
#include "DeleteAction.h"
#include "ChangeBclr.h"
#include "ChangeFclr.h"


//Constructor
ApplicationManager::ApplicationManager() {
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;
}



//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		break;

	case DRAW_SQU:
		pAct = new AddSquAction(this);
		break;

	case DRAW_TRI:
		pAct = new AddTriAction(this);
		break;

	case DRAW_CIRC:
		pAct = new AddCircAction(this);
		break;

	case DRAW_HEX:
		pAct = new AddHexAction(this);
		break;

	case CHANGE_BORDER_COLOR:
		pAct = new ChangeBclr(this, SelectedFig);
		break;

	case CHANGE_FILLING_COLOR:
		pAct = new ChangeFclr(this, SelectedFig);
		break;

	case DELETE_FIGURE:
		pAct = new DeleteAction(this, SelectedFig);
		break;

	case CLEAR_ALL:
		pAct = new ClearAllAction(this);
		break;

	case BRING_TOFRONT:
		pAct = new BringtoFront(this, SelectedFig);
		break;

	case SEND_TOBACK:
		pAct = new SendtoBack(this, SelectedFig);
		break;

	case COPY:
		pAct = new CopyAction(this, SelectedFig);
		break;

	case PASTE:
		pAct = new PasteAction(this, Clipboard);
		break;

	case SAVE:
		pAct = new Save(this);
		break;

	case LOAD_FILE:
		pAct = new Load(this);
		break;
	case SELECT:
		pAct = new Select(this);
		break;


	case EXIT:
		break;

	case STATUS:	//a click on the status bar ==> no action
		return;
	}
	//Execute the created action

	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}


	void ApplicationManager::SetClipboard(CFigure * Figu) {
		Clipboard = Figu;
		SelectedFig = NULL;
	}

	void ApplicationManager::Delete(CFigure * df) {
		for (int i = 0; i < FigCount; i++) {
			if (df == FigList[i]) {
				delete FigList[i];
				FigList[i] = NULL;
				FigCount--;
				for (int j = i; j < FigCount; j++) {
					FigList[j] = FigList[i + 1];
				}
			}
		}
		SelectedFig = NULL;
	}

	void ApplicationManager::DeleteAll() {
		for (int i = 0; i < FigCount; i++) {
			delete FigList[i];
			FigList[i] = NULL;
		}
		FigCount = 0;
	}

	



//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount) {
		FigList[FigCount] = pFig;
		FigList[FigCount]->SetID(FigCount + 1);
		FigCount++;
	}
	//pOut->CreateDrawToolBar();
}
////////////////////////////////////////////////////////////////////////////////////

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }


CFigure* ApplicationManager::GetFigure(int x, int y) const  // 
{
	for (int i = 0; i < (FigCount); i++) {
		if (FigList[i]->InFig(x, y)) {
			FigList[i]->PrintInfo(pOut);
			return FigList[i];
		}
	}
	return NULL;
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.
}


void ApplicationManager::Set_Selected(CFigure* fig) {  //
	SelectedFig = fig;
}
int ApplicationManager::SelFigCount() {  //
	int c = 0;
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->IsSelected()) {
			c = c + 1;
		}
	}
	return c;
}
void ApplicationManager::Set_LMessage(string s) {  //
	LMessage = s;
}
void ApplicationManager::Unselect(CFigure* fig) {  //
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i] != fig) {
			FigList[i]->SetSelected(false);
		}
	}
}

int ApplicationManager::FigIndex() {
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->IsSelected()) {
			return i;
		}
		
	}
}


//calls save
void ApplicationManager::SaveAll(ofstream& OutFile)
{
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Save(OutFile); 
}

//get count
int ApplicationManager::getCount() {
	return FigCount;
}

//get Current Draw color as string
string ApplicationManager::getCrntDraw(color c) {
	if (c == BLACK)
		return "Black";
	else if (c == YELLOW)
		return "Yellow";
	else if (c == RED)
		return "Red";
	else if (c == ORANGE)
		return "Orange";
	else if (c == GREEN)
		return "Green";
	else if (c == BLUE)
		return "Blue";
	else if (c == MAGENTA)
		return "Magenta";
	else
		return "Color";
}

color ApplicationManager::GetColorSting(string s) {  //
	if (s == "Black")
		return BLACK;
	else if (s == "Yellow")
		return YELLOW;
	else if (s == "Red")
		return RED;
	else if (s == "Orange")
		return ORANGE;
	else if (s == "Green")
		return GREEN;
	else if (s == "Blue")
		return BLUE;
	else if (s == "Magenta")
		return MAGENTA;
	else
		return BLACK;  //default color
}

//bring to front
void ApplicationManager::bringfront(CFigure* bf) {
	int itmsent_index = -1; 
	for (int i = 0; i < FigCount; i++) {
		if (bf == FigList[i]) {
			itmsent_index = i;
			break;
		}
	}
	if (itmsent_index != -1) {
		for (int i = itmsent_index; i > 0; i--) {
			FigList[i] = FigList[i - 1];
		}
		FigList[0] = bf;
	}
	
}

void ApplicationManager::sendback(CFigure* sb) {
	int itmsent_index = -1;
	for (int i = 0; i < FigCount; i++) {
		if (sb == FigList[i]) {
			itmsent_index = i;
			break;
		}
	}
	if (itmsent_index != -1) {
		for (int i = itmsent_index; i < FigCount - 1; i++) {
			FigList[i] = FigList[i + 1];
		}
		FigList[FigCount - 1] = sb;
	}
}

////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
}

