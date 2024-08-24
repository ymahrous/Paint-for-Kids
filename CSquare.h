#include "Figures/CFigure.h"

class CSquare: public CFigure {
	private:
		Point Center;
		GfxInfo RectGfxInfo;

	public:
		CSquare(Point, GfxInfo FigureGfxInfo);
		CSquare();
		virtual void Draw(Output* pOut) const;
		virtual CFigure* Move(Point P);

		virtual void Save(ofstream& OutFile);
		virtual bool InFig(int, int);  //
		virtual void PrintInfo(Output* pOut);
		virtual void Load(ifstream& Infile);

};

