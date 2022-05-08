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
	int disp_val;

	void DrawArrowRight(void);
	void DrawArrowLeft(void);
	void Square(int size_x, int size_y);
	void Square(int size_x, int size_y, int pos_x, int pos_y);
	void MoveSquare(int dx, int dy);
	void RoadMove(void);
	void PrintMenu(void);
public:
	OSM_World(void);
	void DrawWay(unsigned char &Key);
	void ClearScreen(void);
};


#endif /* INCLUDE_WORLD_H_ */
