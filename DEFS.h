#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,		//Draw Rectangle
	DRAW_SQU,
	DRAW_TRI,
	DRAW_CIRC,
	DRAW_HEX,

	SELECT,

	CHANGE_BORDER_COLOR,
	CHANGE_FILLING_COLOR,
	C_BLACK,
	C_YELLOW,
	C_ORANGE,
	C_RED,
	C_GREEN,
	C_BLUE,
	DELETE_FIGURE,
	CLEAR_ALL,

	COPY,
	PASTE,

	SEND_TOBACK,

	BRING_TOFRONT,

	LOAD_FILE,
	SAVE,
	EXIT,			//Exit
			//Switch interface to Play mode
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS			//A click on the status bar
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif