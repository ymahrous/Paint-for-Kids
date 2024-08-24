#include "CSquare.h"

CSquare::CSquare(Point P, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo) {
	Center = P;
}
CSquare::CSquare(){}

void CSquare::Draw(Output* pOut) const {
	//Call Output::DrawRect to draw a square on the screen	
	pOut->DrawSqu(Center, FigGfxInfo, Selected);
}

CFigure* CSquare::Move(Point P) {
	return new CSquare(P, FigGfxInfo);
}

void CSquare::Save(ofstream& OutFile) {
	OutFile << "Square" << "\t" << getID() << "\t" << Center.x << "\t" << Center.y << "\t" << GetColor(FigGfxInfo.DrawClr) << "\t";
	if (FigGfxInfo.isFilled)
		OutFile << GetColor(FigGfxInfo.FillClr) << endl;
	else
		OutFile << "NO_FILL" << endl;
 }


void CSquare::Load(ifstream& Infile) {
	Infile >> ID >> Center.x >> Center.y;
	string color;
	Infile >> color;
	FigGfxInfo.DrawClr = GetColorSting(color);
	string check;
	Infile >> check;
	if (check != "NO_FILL") {
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = GetColorSting(check);
	}
	else {
		FigGfxInfo.isFilled = false;
	}


}


bool CSquare::InFig(int x, int y) {  //
	int l = 100;
	if (x >= (Center.x - l) && x <= (Center.x + l) && y >= (Center.y - l) && y <= (Center.y + l)) {
		return true;
	}
	else {
		return false;
	}
}

void CSquare::PrintInfo(Output* pOut) {
	int l = 100;
	string id = to_string(ID);
	string clr = GetColor(FigGfxInfo.DrawClr);
	string x = to_string((Center.x - l));
	string y = to_string((Center.y - l));
	string n = to_string((Center.x + l));
	string m = to_string((Center.y + l));
	string o = to_string((2 * l));
	if (FigGfxInfo.isFilled) {
		string Fclr = GetColor(FigGfxInfo.FillClr);

		pOut->PrintMessage("Square - Id: " + id + " Side length : " + o + " Draw Color : " + clr + " Fill Color : " + Fclr);
	}
	else {

		pOut->PrintMessage("Square - Id: " + id + " Side length: " + o + " Draw Color:�" + clr);
	}
}

//string CSquare::PrintInfo(Output* pOut) {
//	int l = 100;
//	string id = to_string(ID);
//	string clr = GetColor(this->FigGfxInfo.DrawClr);
//	if (FigGfxInfo.isFilled) {
//		string Fclr = GetColor(this->FigGfxInfo.FillClr);
//		return ("Square - Id: ", id, " Corner 1: (", Center.x - l, ",", Center.y - l, ") Corner 2: (", Center.x + l, ",", Center.y + l, ") Side length: ", 2 * l, " Draw Color: ", clr, " Fill Color: ", Fclr);
//	}
//	else
//		return ("Square - Id: ", id, " Corner 1: (", Center.x - l, ",", Center.y - l, ") Corner 2: (", Center.x + l, ",", Center.y + l, ") Side length: ", 2 * l, " Draw Color:�", clr);
//}


