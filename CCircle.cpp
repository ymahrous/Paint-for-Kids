#include "CCircle.h"

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo) {
	Corner1 = P1;
	Corner2 = P2;
}

CCircle::CCircle(){}

void CCircle::Draw(Output* pOut) const {
	//Call Output::DrawCirc to draw a circle on the screen	
	pOut->DrawCirc(Corner1, Corner2, FigGfxInfo, Selected);
}

CFigure* CCircle::Move(Point P) {
	Point Corner202;
	Corner202.x = P.x + abs(Corner1.x - Corner2.x);
	Corner202.y = P.y + abs(Corner1.y - Corner2.y);

	return new CCircle(P, Corner202, FigGfxInfo);
}

void CCircle::Save(ofstream& OutFile) {

OutFile << "Circle" << "\t" << getID() << "\t" << Corner1.x << "\t" << Corner1.y << Corner2.x << "\t" << Corner2.y << "\t" << GetColor(FigGfxInfo.DrawClr) << "\t";
if (FigGfxInfo.isFilled)
OutFile << GetColor(FigGfxInfo.FillClr) << endl;
else
OutFile << "NO_FILL"<<endl;
	
}

void CCircle::Load(ifstream& Infile) {
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;
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


bool CCircle::InFig(int x, int y) {  //
	int d = sqrt((x - Corner1.x) ^ 2 + (y - Corner1.y) ^ 2);
	int r = sqrt((Corner2.x - Corner1.x) ^ 2 + (Corner2.y - Corner1.y) ^ 2);
	if (d <= r)
		return true;
	else
		return false;
}

void CCircle::PrintInfo(Output* pOut) {  //
	int r = sqrt((Corner2.x - Corner1.x) ^ 2 + (Corner2.y - Corner1.y) ^ 2);
	string Rad = to_string(r);
	string id = to_string(getID());
	string clr = GetColor(FigGfxInfo.DrawClr);
	if (FigGfxInfo.isFilled) {
		string Fclr = GetColor(FigGfxInfo.FillClr);
		pOut->PrintMessage("Circle - Id: " + id + " Radius: " + Rad + " Draw Color : " + clr + " Fill Color : " + Fclr);
	}
	else
		pOut->PrintMessage("Circle - Id: " + id + " Radius: " + Rad + " Draw Color�:�" + clr);
}

//void CCircle::SetID(int i) {  //
//	ID = i;
//}

//string CCircle::PrintInfo(Output* pOut) {  //
//	int r = sqrt((Corner2.x - Corner1.x) ^ 2 + (Corner2.y - Corner1.y) ^ 2);
//	string Rad = to_string(r);
//	string id = to_string(ID);
//	string clr = GetColor(this->FigGfxInfo.DrawClr);
//	if (FigGfxInfo.isFilled) {
//		string Fclr = GetColor(this->FigGfxInfo.FillClr);
//		return ("Circle - Id: ", id, " Center: (", Corner1.x, ",", Corner1.y, ") Radius: ", Rad, " Draw Color : ", clr, " Fill Color : ", Fclr);
//	}
//	else
//		return ("Circle - Id: ", id, " Center: (", Corner1.x, ",", Corner1.y, ") Radius: ", Rad, " Draw Color�:�", clr);
//}