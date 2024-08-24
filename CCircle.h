#include "Figures/CFigure.h"

class CCircle:public CFigure {
	private:
		Point Corner1;
		Point Corner2;
		GfxInfo RectGfxInfo;
	public:
		CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo);
		CCircle();
		virtual void Draw(Output* pOut) const;
		virtual CFigure* Move(Point P);

		virtual void Save(ofstream& OutFile);
		virtual bool InFig(int, int);  //
		virtual void PrintInfo(Output* pOut);
		virtual void Load(ifstream& Infile);

};