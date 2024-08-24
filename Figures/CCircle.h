#include "Figures/CFigure.h"

class CCircle:public CFigure {
	private:
		Point Corner1;
		Point Corner2;
	public:
		CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo);
		virtual void Draw(Output* pOut) const;
		virtual CFigure* Move(Point P);
};