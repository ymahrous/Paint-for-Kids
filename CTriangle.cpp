#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}
CTriangle::CTriangle(){}

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a triangle on the screen	
	pOut->DrawTri(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}

CFigure* CTriangle::Move(Point P) {
	Point Corner202, Corner203;
	if ((Corner1.y <= Corner2.y) && (Corner1.y <= Corner3.y))
	{
		Corner202.x = P.x - (Corner1.x - Corner2.x);
		Corner202.y = P.y - (Corner1.y - Corner2.y);

		Corner203.x = P.x - (Corner1.x - Corner3.x);
		Corner203.y = P.y - (Corner1.y - Corner3.y);
	}
	else if ((Corner2.y <= Corner1.y) && (Corner2.y <= Corner3.y))
	{
		Corner202.x = P.x - (Corner2.x - Corner1.x);
		Corner202.y = P.y - (Corner2.y - Corner1.y);

		Corner203.x = P.x - (Corner2.x - Corner3.x);
		Corner203.y = P.y - (Corner2.y - Corner3.y);
	}
	else if ((Corner3.y <= Corner1.y) && (Corner3.y <= Corner2.y))
	{
		Corner202.x = P.x - (Corner3.x - Corner1.x);
		Corner202.y = P.y - (Corner3.y - Corner1.y);

		Corner203.x = P.x - (Corner3.x - Corner2.x);
		Corner203.y = P.y - (Corner3.y - Corner2.y);
	}

	return new CTriangle(P, Corner202, Corner203, FigGfxInfo);
}

void CTriangle::Save(ofstream& OutFile) {
	OutFile << "Triangle" << "\t" << getID() << "\t" << Corner1.x << "\t" << Corner1.y << Corner2.x << "\t" << Corner2.y << "\t"<<Corner3.x<< "\t" <<Corner3.y<< "\t" << GetColor(FigGfxInfo.DrawClr) << "\t";
	if (FigGfxInfo.isFilled)
		OutFile << GetColor(FigGfxInfo.FillClr) << endl;
	else
		OutFile << "NO_FILL" << endl;
 }

 void CTriangle::Load(ifstream& Infile) {
	 Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y;
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


bool CTriangle::InFig(int x, int y) {  //

	double BC1 = sqrt((x - Corner1.x) ^ 2 + (y - Corner1.y) ^ 2);
	double BC2 = sqrt((x - Corner2.x) ^ 2 + (y - Corner2.y) ^ 2);
	double BC3 = sqrt((x - Corner3.x) ^ 2 + (y - Corner3.y) ^ 2);
	double C1C2 = sqrt((Corner1.x - Corner2.x) ^ 2 + (Corner1.y - Corner2.y) ^ 2);
	double C2C3 = sqrt((Corner2.x - Corner3.x) ^ 2 + (Corner2.y - Corner3.y) ^ 2);
	double C1C3 = sqrt((Corner1.x - Corner3.x) ^ 2 + (Corner1.y - Corner3.y) ^ 2);
	double p1 = (0.5) * (BC2 + BC3 + C2C3);
	double p2 = (0.5) * (BC1 + BC2 + C1C2);
	double p3 = (0.5) * (BC1 + BC3 + C1C3);
	double p = (0.5) * (C1C2 + C1C3 + C2C3);
	double A1 = sqrt(p1 * (p1 - BC2) * (p1 - BC3) * (p1 - C2C3));
	double A2 = sqrt(p2 * (p2 - BC1) * (p2 - BC2) * (p2 - C1C2));
	double A3 = sqrt(p3 * (p3 - BC1) * (p3 - BC3) * (p3 - C1C3));
	double A = sqrt(p * (p - C1C2) * (p - C1C3) * (p - C2C3));
	if (abs(A - (A1 + A2 + A3) < 5)) {
		return true;
	}
	else {
		return false;
	}
	
}


void CTriangle::PrintInfo(Output* pOut) {  //
	string id = to_string(getID());
	string clr = GetColor(FigGfxInfo.DrawClr);
	int s1 = sqrt((Corner1.x - Corner2.x) ^ 2 + (Corner1.y - Corner2.y) ^ 2);
	string S1 = to_string(s1);
	int s2 = sqrt((Corner2.x - Corner3.x) ^ 2 + (Corner3.y - Corner2.y) ^ 2);
	string S2 = to_string(s2);
	int s3 = sqrt((Corner1.x - Corner3.x) ^ 2 + (Corner1.y - Corner3.y) ^ 2);
	string S3 = to_string(s3);
	if (FigGfxInfo.isFilled) {
		string Fclr = GetColor(FigGfxInfo.FillClr);
		pOut->PrintMessage("Triangle - Id: " + id + " Side 1: " + S1 + " Side 2: " + S2 + " Side 3: " + S3 + " Draw Color: " + clr + " Fill Color: " + Fclr);
	}
	else
		pOut->PrintMessage("Triangle - Id: " + id + " Side 1: " + S1 + " Side 2: " + S2 + " Side 3: " + S3 + " Draw Color:�" + clr);
}


//string CTriangle::PrintInfo(Output* pOut) {  //
//	string id = to_string(ID);
//	string clr = GetColor(this->FigGfxInfo.DrawClr);
//	int s1 = sqrt((Corner1.x - Corner2.x) ^ 2 + (Corner1.y - Corner2.y) ^ 2);
//	string S1 = to_string(s1);
//	int s2 = sqrt((Corner2.x - Corner3.x) ^ 2 + (Corner3.y - Corner2.y) ^ 2);
//	string S2 = to_string(s2);
//	int s3 = sqrt((Corner1.x - Corner3.x) ^ 2 + (Corner1.y - Corner3.y) ^ 2);
//	string S3 = to_string(s3);
//	if (FigGfxInfo.isFilled) {
//		string Fclr = GetColor(this->FigGfxInfo.FillClr);
//		return ("Triangle - Id: ", id, " Side 1: ", S1, " Side 2: ", S2, " Side 3: ", S3, " Draw Color: ", clr, " Fill Color: ", Fclr);
//	}
//	else
//		return ("Triangle - Id: ", id, " Side 1: ", S1, " Side 2: ", S2, " Side 3: ", S3, " Draw Color:�", clr);
//}