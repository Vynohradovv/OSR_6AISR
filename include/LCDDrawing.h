/*
 * world.h
 *
 *  Created on: May 3, 2022
 *      Author: Anton
 */

#ifndef INCLUDE_LCDDRAWING_H_
#define INCLUDE_LCDDRAWING_H_

class LCDDrawing
{
private:
	int arrow_size;
	int gPosX, gPosY;

	void RoadMove(void);
	void ClearScreen(void);
	void DrawArrowLeft(void);
	void DrawArrowRight(void);
	void Square(int size_x, int size_y);
	void PrinfLCD(char *buff, const int &value);
	void Square(int size_x, int size_y, int pos_x, int pos_y);

public:

	#define LCD_H 	(128)
	#define LCD_W	(240)

	LCDDrawing(void);
	void PrintMenu(void);
	void MoveSquare(int dx, int dy);
	void ProcessDrawing(unsigned char &Key);
	int GetSquarePosition(void);
};


#endif /* INCLUDE_LCDDRAWING_H_ */
