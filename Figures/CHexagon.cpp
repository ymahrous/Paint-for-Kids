#include "CHexagon.h"

CHexagon::CHexagon(Point P, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo) {
	Center = P;
}


void CHexagon::Draw(Output* pOut) const {
	//Call Output::DrawRect to draw a hexagon on the screen	
	pOut->DrawHex(Center, FigGfxInfo, Selected);
}

CFigure* CHexagon::Move(Point P) {
	return new CHexagon(P, FigGfxInfo);
}