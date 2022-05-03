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
	void DrawArrow1(void);
	void DrawArrow4(void);
	void DrawArrow6(void);
	void DrawArrow3(void);
	void DrawArrow7(void);
	void DrawArrow9(void);
public:
	OSM_World(void);
	void DrawWay(void);
	void ClearScreen(void);
};


#endif /* INCLUDE_WORLD_H_ */
