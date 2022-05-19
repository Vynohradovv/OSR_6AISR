/*
 * Ship.h
 *
 *  Created on: May 16, 2022
 *      Author: Anton
 */

#ifndef INCLUDE_SHIP_H_
#define INCLUDE_SHIP_H_

#include "LCDDrawing.h"
#include "PID.h"

#ifdef TMSLAB_WIN
  #include "stdio.h"
#endif

extern int Tim;                // Licznik uzytkownika

class Ship:public LCDDrawing, public PID
{

private:

	int LastTime;

public:

	Ship(float Kp, float Ki, float Kd)
	:PID(Kp, Ki, Kd,2,-127,127){ };

	void ProcessingShip(unsigned char &Key)
	{
		ProcessDrawing(Key);

		setInput((float)GetSquarePosition(),(float)115);

		Calculate();

		float outPID = getOutput();

			if(outPID > 0.0)
			{
				MoveSquare( 1 , 0 );

			} else if(outPID < 0.0) {

				MoveSquare( -1 , 0 );
			}
	}
};




#endif /* INCLUDE_SHIP_H_ */
