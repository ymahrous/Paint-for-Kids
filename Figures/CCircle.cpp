#include "CCircle.h"
CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo) {
	Corner1 = P1;
	Corner2 = P2;
}


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