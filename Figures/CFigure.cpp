#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

CFigure::CFigure(){}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

color CFigure::GetColorSting(string s) {  //
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

string CFigure::GetColor(color c) {  //
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

void CFigure::SetStored() {  //
	sFill = FigGfxInfo.FillClr;
	sDraw = FigGfxInfo.DrawClr;
	IsFilled = FigGfxInfo.isFilled;
}
void CFigure::SetGfxInfo(GfxInfo& PickGfxInfo) {  //
	PickGfxInfo.DrawClr = sDraw;
	PickGfxInfo.FillClr = sFill;
	PickGfxInfo.isFilled = IsFilled;
}
void CFigure::assignStored() {  //
	FigGfxInfo.isFilled = IsFilled;
	FigGfxInfo.DrawClr = sDraw;
	FigGfxInfo.FillClr = sFill;
}


void  CFigure::SetID(int id) {
	ID = id;
}

int CFigure::getID() const {
	return ID;
 }


