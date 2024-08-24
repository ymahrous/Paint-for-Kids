#include "Figures/CFigure.h"

class CTriangle:public CFigure {
	private:
		Point Corner1;
		Point Corner2;
		Point Corner3;
	public:
		CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo);
		virtual void Draw(Output* pOut) const;
		virtual CFigure* Move(Point P);
};