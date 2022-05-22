/*
 * world.cpp
 *
 *  Created on: May 3, 2022
 *      Author: Anton
 */
#include <LCDDrawing.h>
#include "setup.h"
#include "R_P_KEYBOARD_TMSLAB.h"

#include "square.h"

#ifdef TMSLAB_WIN
  #include "stdio.h"
#endif

extern unsigned long *ekran; /* 240 x 128 */
extern unsigned short int* textEkran;
extern int Tim;                // Licznik uzytkownika

static char PiParamKp [10] 	= "Kp: ";
static char PiParamTi [10] 	= "Ti: ";
static char PiParamTd [10] 	= "Td: ";

static char ObjParamKp[10]  = "Kp: ";
static char ObjParamT [10] 	= " T: ";

static char DisParamZ [10] 	= "Z: ";


R_P_KEYBOARD_TMSLAB WorldKey;

void LCDDrawing::PrinfLCD(char *buff, const float &value)
{
	sprintf(buff + 3,"%2.2f",value);
}

void LCDDrawing::DrawArrowRight(void)
{
	int i = 0;
	for (int y = 53; y < 63; y++)
	{
		for (int x = 0; x <= arrow_size; x++)
		{
			SetPixel(ekran, (x + i), y);
		}
		i++;
	}

	for (int y = 63; y < 74; y++)
	{
		for (int x = arrow_size; x >= 0; x--)
		{
			SetPixel(ekran, (x + i), y);
		}
		i--;
	}

	*regZ = (Tim % 10);
	this->MoveSquare(*regZ, (-Tim % 3));
}


void LCDDrawing::DrawArrowLeft(void)
{

	int i = 0;

	for (int y = 53; y < 63; y++)
	{
		for (int x = 239; x >= 239 - arrow_size; x--)
		{
			SetPixel(ekran, (x - i), y);
		}
		i++;
	}

	for (int y = 63; y < 74; y++)
	{
		for (int x = 239 - arrow_size; x <= 239; x++)
		{
			SetPixel(ekran, (x - i), y);
		}
		i--;
	}

	*regZ = (-Tim % 10);
	this->MoveSquare(*regZ, (Tim % 3));
}

LCDDrawing::LCDDrawing(void)
{
    arrow_size = 15;
    gPosX = 115;
    gPosY = 50;
    gAngleZ = 0;

    stepReg = 0.5;
}

int LCDDrawing::GetSquarePosition(void)
{
	return gPosX;
}

void LCDDrawing::ProcessDrawing(unsigned char &Key)
{
	static unsigned char LastKey = 0;

	 this->ClearScreen();

	 if(LastKey != Key)
	 {
		 this->PIDParamitersValue(Key % 10);
		 LastKey = Key;

	 }

	 switch(Key % 10)
	 {
	 case 7:
		 this->DrawArrowRight();
		 break;

	 case 9:
		 this->DrawArrowLeft();
		 break;

	 default:

		 break;
	 }



	 this->Square(10,30);
	 this->RoadMove();
	 this->PrintMenu();


}

void LCDDrawing::SetMenuParamiters(float *kp, float *td, float *ti)
{
	usKP = kp;
	usTD = td;
	usTI = ti;

	PrinfLCD(PiParamKp, *usKP);
	PrinfLCD(PiParamTd, *usTD);
	PrinfLCD(PiParamTi, *usTI);
}

void LCDDrawing::SetObjectParamiters(float objKP, float objT, float *objZ)
{
	regZ = objZ;

	PrinfLCD(ObjParamKp, objKP);
	PrinfLCD(ObjParamT,  objT );
	PrinfLCD(DisParamZ,  *regZ);
}

void LCDDrawing::PrintMenu(void)
{

	PrintText(textEkran,"PI PARAM", 8, 0, 0);
	PrintText(textEkran, PiParamKp, 7, 0, 1);
	PrintText(textEkran, PiParamTd, 7, 0, 2);
	PrintText(textEkran, PiParamTi, 7, 0, 3);

	// Wy�wietlanie paramter�w obiektu regulacji
	PrintText(textEkran, "OBJ PARAM", 9, 30, 0);
	PrintText(textEkran, ObjParamKp,  7, 30, 1);
	PrintText(textEkran, ObjParamT,   7, 30, 2);

	// Wy�wietlanie warto�ci zak��cenia
	PrintText(textEkran, "DISRUPTION", 10, 30, 5);
	PrintText(textEkran, DisParamZ, 7, 30, 6);

}

void LCDDrawing::RoadMove(void)
{
    for(int i=0; i< LCD_H; i++)
    {
        if(!(i%5))
        {
            SetPixel(ekran,(LCD_W/2),(i + (Tim % 2)));
        }

    }
}

void LCDDrawing::PIDParamitersValue(int CodeKay)
{
	switch(CodeKay)
	{
	case 1:				/* KP */
		*usKP += stepReg;

		break;

	case 4:
		*usKP -= stepReg;

		break;

	case 2: 			/* TD */
		*usTD += stepReg;

		break;

	case 5:
		*usTD -= stepReg;

		break;

	case 3: 			/* TI */
		*usTI += stepReg;

		break;

	case 6:
		*usTI -= stepReg;

		break;

	case 7:				/* Z */
		break;

	case 9:
		break;

	default:
		break;
	}
}

void LCDDrawing::Square(int size_x, int size_y)
{
	int angleX = 0;

	for (int b = gPosY; b<(size_y + gPosY); b++)
	{
		if(gAngleZ > angleX)
		{
			SetPixel(ekran,(gPosX + angleX),b);
			angleX ++;

		}else{

			SetPixel(ekran,gPosX,b);
			angleX = 0;
		}

	}

	for (int b = gPosY; b<(size_y + gPosY); b++)
	{
		if(gAngleZ > angleX)
		{
			SetPixel(ekran,(size_x + gPosX + angleX),b);
			angleX++;
		}else{

			SetPixel(ekran,(size_x + gPosX),b);
			angleX = 0;
		}

	}

	for (int a=(0+gPosX); a<(size_x+gPosX); a++)
	{
		if(gAngleZ > angleX)
		{
			SetPixel(ekran,a,gPosY);
			angleX++;

		} else {

			SetPixel(ekran,a,gPosY);
			angleX = 0;
		}
	}

	for (int a = gPosX; a < (size_x+gPosX); a++)
	{
		if(gAngleZ > angleX)
		{
			SetPixel(ekran,a,(size_y+gPosY));
			angleX++;

		} else {

			SetPixel(ekran,a,(size_y+gPosY));
			angleX = 0;
		}
	}
}

void LCDDrawing::Square(int size_x, int size_y, int pos_x, int pos_y)
{
    for (int b=(0+pos_y); b<(size_y+pos_y); b++)
      for (int a=(0+pos_x); a<(size_x+pos_x); a++)
          SetPixel(ekran,a,b);
}

void LCDDrawing::MoveSquare(int dx, int dy)
{
	gPosY += dy;

	if(gPosY >= (LCD_H - 40)) gPosY = (LCD_H - 40); else if(gPosY < 10 ) gPosY = 10;

	gPosX += dx;

	if(gPosX >= (LCD_W - 40)) gPosX = (LCD_W - 40); else if (gPosX < 40) gPosX = 40;
}

void LCDDrawing::MoveSquare(int dx, int dy, int angle)
{
	this->Square(dx, dy);

	gAngleZ = angle;
}

void LCDDrawing::ClearScreen(void)
{
	 for (int a = 0; a < (128 * 8); a++)
		 ekran[a] = 0;
}


