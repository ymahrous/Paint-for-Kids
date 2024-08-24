#include "CSquare.h"

CSquare::CSquare(Point P, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo) {
	Center = P;
}


void CSquare::Draw(Output* pOut) const {
	//Call Output::DrawRect to draw a square on the screen	
	pOut->DrawSqu(Center, FigGfxInfo, Selected);
}

CFigure* CSquare::Move(Point P) {
	return new CSquare(P, FigGfxInfo);
}