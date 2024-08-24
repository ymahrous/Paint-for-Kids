#include "Figures/CFigure.h"

class CTriangle:public CFigure {
	private:
		Point Corner1;
		Point Corner2;
		Point Corner3;
		GfxInfo RectGfxInfo;

	public:
		CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo);
		CTriangle();
		virtual void Draw(Output* pOut) const;
		virtual CFigure* Move(Point P);

		virtual void Save(ofstream& OutFile);
		virtual bool InFig(int, int);  //
		virtual void PrintInfo(Output* pOut);
		virtual void Load(ifstream& Infile);

};