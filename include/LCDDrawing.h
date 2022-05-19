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

	float *usKP,*usTD,*usTI;
	float regKP,regT,*regZ;
	float stepReg;

	void RoadMove(void);
	void PrintMenu(void);
	void ClearScreen(void);
	void DrawArrowLeft(void);
	void DrawArrowRight(void);
	void Square(int size_x, int size_y);
	void PIDParamitersValue(int CodeKay);
	void PrinfLCD(char *buff, const float &value);
	void Square(int size_x, int size_y, int pos_x, int pos_y);

public:

	#define LCD_H 	(128)
	#define LCD_W	(240)

	LCDDrawing(void);

	void SetMenuParamiters(float *kp, float *td, float *ti);
	void SetObjectParamiters(float objKP, float objT, float *objZ);

	void MoveSquare(int dx, int dy);
	void ProcessDrawing(unsigned char &Key);
	int GetSquarePosition(void);
};


#endif /* INCLUDE_LCDDRAWING_H_ */
