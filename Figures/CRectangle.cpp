#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	
CRectangle::CRectangle() {}

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}



CFigure* CRectangle::Move(Point P) {
	Point Corner202;
	Corner202.x = P.x + abs(Corner1.x - Corner2.x);
	Corner202.y = P.y + abs(Corner1.y - Corner2.y);
	return new CRectangle(P, Corner202, FigGfxInfo);
}

void CRectangle::Save(ofstream& OutFile) {
	OutFile << "Rectangle" << "\t" << getID() << "\t" << Corner1.x << "\t" << Corner1.y << Corner2.x << "\t" << Corner2.y << "\t" << GetColor(FigGfxInfo.DrawClr) << "\t";
	if (FigGfxInfo.isFilled)
		OutFile << GetColor(FigGfxInfo.FillClr) << endl;
	else
		OutFile << "NO_FILL" << endl;
}

void CRectangle::Load(ifstream& Infile) {
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;
	string color;
	Infile >> color;
	FigGfxInfo.DrawClr=GetColorSting(color);
	string check;
	Infile >> check;
	if (check != "NO_FILL") {
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr= GetColorSting(check);
	}	
	else {
		FigGfxInfo.isFilled = false;
	}
	
}

bool CRectangle::InFig(int x, int y) {      //
	if (x >= Corner1.x && x <= Corner2.x && y >= Corner1.y && y <= Corner2.y) {
		return true;
	}
	else {
		return false;
	}
}



void CRectangle::PrintInfo(Output* pOut) {  //
	string id = to_string(getID());
	string clr = GetColor(FigGfxInfo.DrawClr);
	if (FigGfxInfo.isFilled) {
		string Fcolor = GetColor(FigGfxInfo.FillClr);
		pOut->PrintMessage("Rectangle - Id: " + id + " Draw Color: " + clr + "Fill Color: " + Fcolor);
	}
	else
		pOut->PrintMessage("Rectangle - Id: " + id + " Draw Color:�" + clr);
}

//string CRectangle::PrintInfo(Output* pOut) {  //
//	string id = to_string(ID);
//	string clr = GetColor(this->FigGfxInfo.DrawClr);
//	if (FigGfxInfo.isFilled) {
//		string Fcolor = GetColor(this->FigGfxInfo.FillClr);
//		return ("Rectangle - Id: ", id, "Corner 1: (", Corner1.x, ",", Corner1.y, ") Corner 2: (", Corner2.x, ",", Corner2.y, ") Draw Color: ", clr, "Fill Color: ", Fcolor);
//	}
//	else
//		return ("Rectangle - Id: ", id, "Corner 1: (", Corner1.x, ",", Corner1.y, ") Corner 2: (", Corner2.x, ",", Corner2.y, ") Draw Color:�", clr);
//}