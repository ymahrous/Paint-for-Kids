#pragma once
#include "Figures/CFigure.h"

class CHexagon : public CFigure {
private:
	Point Center;
public:
	CHexagon(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual CFigure* Move(Point P);
};