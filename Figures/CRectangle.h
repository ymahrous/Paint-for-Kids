#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	GfxInfo RectGfxInfo;

public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	CRectangle::CRectangle();
	virtual void Draw(Output* pOut) const;
	virtual CFigure* Move(Point P);

	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);

	virtual bool InFig(int, int);   //
	//virtual void SetID(int i);  //
	virtual void PrintInfo(Output* pOut);
};

#endif