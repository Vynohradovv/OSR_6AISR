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
	float inKp, inTi, inTd;
	float inObjKp, inObjT, inObjZ;


public:

	Ship(float Kp, float Ti, float Td)
	:PID(Kp, Ti, Td,2,-127,127)
	{
		inKp = Kp;
		inTi = Ti;
		inTd = Td;

		inObjKp = 1;
		inObjT = 2;
		inObjZ = 0;

		SetMenuParamiters(&inKp,&inTi,&inTd);
		SetObjectParamiters(inObjKp,inObjT,&inObjZ);
	};

	void ProcessingShip(unsigned char &Key)
	{
		ProcessDrawing(Key);
		SetMenuParamiters(&inKp,&inTi,&inTd);
		SetObjectParamiters(inObjKp,inObjT,&inObjZ);

		setInput((float)GetSquarePosition(),(float)115);

		Calculate();

		float outPID = getOutput();
		if(outPID > 0.0)
		{
			MoveSquare( 1 , 0 );

		} else if(outPID < 0.0) {

			MoveSquare( -1 , 0 );

		}else{

			inObjZ = 0;
		}

	}
};




#endif /* INCLUDE_SHIP_H_ */
