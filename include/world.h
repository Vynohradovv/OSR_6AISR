/*
 * world.h
 *
 *  Created on: May 3, 2022
 *      Author: Anton
 */

#ifndef INCLUDE_WORLD_H_
#define INCLUDE_WORLD_H_

#define LCD_H 	(128)
#define LCD_W	(240)

class OSM_World
{
private:
	int arrow_size;
	int gPosX, gPosY;
	int usKP, usKI, usTI;
	int regKP, regT, regZ;

	void DrawArrowRight(void);
	void DrawArrowLeft(void);
	void Square(int size_x, int size_y);
	void Square(int size_x, int size_y, int pos_x, int pos_y);
	void MoveSquare(int dx, int dy);
	void RoadMove(void);
	void PrintMenu(void);
	void PIDParamitersValue(int CodeKay);
	void CalculatePID(void);
	void ClearScreen(void);

	void PrinfLCD(char *buff, const int &value);

public:
	OSM_World(void);
	void DrawWay(unsigned char &Key);

};


#endif /* INCLUDE_WORLD_H_ */
