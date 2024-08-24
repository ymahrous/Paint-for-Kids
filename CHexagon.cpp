#include "CHexagon.h"

CHexagon::CHexagon(Point P, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo) {
	Center = P;
}

CHexagon::CHexagon(){}

void CHexagon::Draw(Output* pOut) const {
	//Call Output::DrawRect to draw a hexagon on the screen	
	pOut->DrawHex(Center, FigGfxInfo, Selected);
}

CFigure* CHexagon::Move(Point P) {
	return new CHexagon(P, FigGfxInfo);
}

void CHexagon::Save(ofstream& OutFile) {
	OutFile << "Hexagon" << "\t" << getID() << "\t" << Center.x << "\t" << Center.y <<  "\t" << GetColor(FigGfxInfo.DrawClr) << "\t";
	if (FigGfxInfo.isFilled)
		OutFile << GetColor(FigGfxInfo.FillClr) << endl;
	else
		OutFile << "NO_FILL" << endl;
}

void CHexagon::Load(ifstream& Infile) {
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

bool CHexagon::InFig(int x, int y) {  //
	int l = 100;
	if (x >= (Center.x - l) && x <= (Center.x + l) && y >= (Center.y - l) && y <= (Center.y + l)) {
		return true;
	}
	else {
		return false;
	}
}

void CHexagon::PrintInfo(Output* pOut) {  //
	int l = 100;
	string id = to_string(ID);
	string clr = GetColor(FigGfxInfo.DrawClr);
	string m = to_string(l);
	if (FigGfxInfo.isFilled) {
		string Fclr = GetColor(FigGfxInfo.FillClr);
		pOut->PrintMessage("Hexagon - Id: " + id + " Side length: " + m + " Draw Color: " + clr + " Fill Color: " + Fclr);
	}
	else
		pOut->PrintMessage("Hexagon - Id: " + id + " Side length: " + m + " Draw Color:�" + clr);
}