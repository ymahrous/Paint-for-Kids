#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = UI.width / DRAW_ITM_COUNT;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;
	UI.MenuItemWidth = UI.width / DRAW_ITM_COUNT;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list
	MenuItemImages[ITM_SQU] = "images\\MenuItems\\Menu_Square.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\Menu_Triangle.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\Menu_Circle.jpg";
	MenuItemImages[ITM_HEX] = "images\\MenuItems\\Menu_Hexagon.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_Slct.jpg";
	MenuItemImages[ITM_CHANGEBCOLOR] = "images\\MenuItems\\Menu_Brdr.jpg";
	MenuItemImages[ITM_CHANGEFCOLOR] = "images\\MenuItems\\Menu_Fill.jpg";
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\BLACK.jpg";
	MenuItemImages[ITM_YELLOW] = "images\\MenuItems\\YELLOW.jpg";
	MenuItemImages[ITM_ORANGE] = "images\\MenuItems\\ORANGE.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\RED.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\GREEN.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\BLUE.jpg";
	MenuItemImages[ITM_DELETEFIG] = "images\\MenuItems\\Menu_Delete.jpg";
	MenuItemImages[ITM_CLRALL] = "images\\MenuItems\\Menu_Clear.jpg";
	MenuItemImages[ITM_COPYFIG] = "images\\MenuItems\\Menu_Copy.jpg";
	MenuItemImages[ITM_PASTEFIG] = "images\\MenuItems\\Menu_Paste.jpg";
	MenuItemImages[ITM_SENDBACK] = "images\\MenuItems\\bringtofront.jpg";
	MenuItemImages[ITM_BRINGFRONT] = "images\\MenuItems\\sendback.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Menu_Insert.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Menu_Save.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, UI.LineUnderTBWidth);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	UI.MenuItemWidth = UI.width / PLAY_ITM_COUNT;

	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_PICK] = "images\\MenuItems\\Menu_Pick.jpg";
	MenuItemImages[ITM_TYPE] = "images\\MenuItems\\Menu_BT.jpg";
	MenuItemImages[ITM_COLOR] = "images\\MenuItems\\Menu_BC.jpg";
	MenuItemImages[ITM_BOTH] = "images\\MenuItems\\Menu_both.jpg";
	MenuItemImages[ITM_DRAW] = "images\\MenuItems\\Menu_Play.jpg";


	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, UI.LineUnderTBWidth);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}

// Square
void Output::DrawSqu(Point P, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	int X[4];
	int Y[4];
	// half length of square
	int l = 100;

	X[0] = P.x - l; Y[0] = P.y - l;
	X[1] = P.x - l; Y[1] = P.y + l;
	X[2] = P.x + l; Y[2] = P.y + l;
	X[3] = P.x + l; Y[3] = P.y - l;

	pWind->DrawPolygon(X, Y, 4, style);

}

// Triangle
void Output::DrawTri(Point P1, Point P2, Point P3, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}
// Hexagon
void Output::DrawHex(Point P, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else {
		style = FRAME;
	}


	int X[6];
	int Y[6];
	// half length of square
	int l = 100;


	X[0] = P.x - l;		Y[0] = P.y;
	X[1] = P.x - l / 2; Y[1] = P.y - l / 2;
	X[2] = P.x + l / 2; Y[2] = P.y - l / 2;
	X[3] = P.x + l;		Y[3] = P.y;
	X[4] = P.x + l / 2; Y[4] = P.y + l / 2;
	X[5] = P.x - l / 2; Y[5] = P.y + l / 2;


	pWind->DrawPolygon(X, Y, 6, style);
}

// Circle
void Output::DrawCirc(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	int r = sqrt(pow(P2.x - P1.x, 2) + pow(P2.y - P1.y, 2)) / 2;
	int x = (P1.x + P2.x) / 2;
	int y = (P1.y + P2.y) / 2;

	pWind->DrawCircle(x, y, r, style);

}


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}
