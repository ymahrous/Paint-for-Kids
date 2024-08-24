#pragma once
#include "Figures/CFigure.h"

class CHexagon : public CFigure {
private:
	Point Center;
	GfxInfo RectGfxInfo;

public:
	CHexagon(Point, GfxInfo FigureGfxInfo);
	CHexagon();
	virtual void Draw(Output* pOut) const;
	virtual CFigure* Move(Point P);

	virtual void Save(ofstream& OutFile);
	virtual bool InFig(int, int);  //
	virtual void PrintInfo(Output* pOut);
	virtual void Load(ifstream& Infile);

};