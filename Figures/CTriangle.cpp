#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawTri(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}

CFigure* CTriangle::Move(Point P) {
	Point Corner202, Corner203;
	if ((Corner1.y<=Corner2.y)&&(Corner1.y<=Corner3.y))
	{
		Corner202.x = P.x - (Corner1.x - Corner2.x);
		Corner202.y = P.y - (Corner1.y - Corner2.y);

		Corner203.x = P.x - (Corner1.x - Corner3.x);
		Corner203.y = P.y - (Corner1.y - Corner3.y);
	}
	else if ((Corner2.y<=Corner1.y)&&(Corner2.y<=Corner3.y))
	{
		Corner202.x = P.x - (Corner2.x - Corner1.x);
		Corner202.y = P.y - (Corner2.y - Corner1.y);

		Corner203.x = P.x - (Corner2.x - Corner3.x);
		Corner203.y = P.y - (Corner2.y - Corner3.y);
	}
	else if ((Corner3.y<=Corner1.y)&&(Corner3.y<=Corner2.y))
	{
		Corner202.x = P.x - (Corner3.x - Corner1.x);
		Corner202.y = P.y - (Corner3.y - Corner1.y);

		Corner203.x = P.x - (Corner3.x - Corner2.x);
		Corner203.y = P.y - (Corner3.y - Corner2.y);
	}

	return new CTriangle(P, Corner202, Corner203, FigGfxInfo);
}