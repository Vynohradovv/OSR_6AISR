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

#include <stdio.h>

extern unsigned long *ekran; /* 240 x 128 */
extern unsigned short int* textEkran;
extern int Tim;                // Licznik uzytkownika

//static char PiParamKp [] 	= "Kp =      "	;
//static char PiParamKi [] 	= "Ki =      "	;
//static char PiParamTi [] 	= "Ti =      "	;
//
//static char ObjParamKp [] 	= "Kp =      "	;
//static char ObjParamT [] 	= "T  =      "	;
//
//static char DisParamZ [] 	= "Z =       "	;


R_P_KEYBOARD_TMSLAB WorldKey;

void LCDDrawing::PrinfLCD(char *buff, const int &value)
{
	sprintf(buff + 5,"%d",value);
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

	this->MoveSquare(5, 0);
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

	this->MoveSquare(-5, 0);
}

LCDDrawing::LCDDrawing(void)
{
    arrow_size = 15;
    gPosX = 115;
    gPosY = 50;


//    PrinfLCD(PiParamKp, usKP = 0);
//    PrinfLCD(PiParamKi, usKI = 0);
//    PrinfLCD(PiParamTi, usTI = 0);
//
//    PrinfLCD(ObjParamKp, regKP = 0);
//    PrinfLCD(ObjParamT, regT = 0);
//    PrinfLCD(DisParamZ, regZ = 0);


}

int LCDDrawing::GetSquarePosition(void)
{
	return gPosX;
}

void LCDDrawing::ProcessDrawing(unsigned char &Key)
{
	 this->ClearScreen();

	 switch(Key % 10)
	 {
	 case 7:
		 this->DrawArrowRight();
//		 this->PIDParamitersValue(Key);
		 break;

	 case 9:
		 this->DrawArrowLeft();
//		 this->PIDParamitersValue(Key);
		 break;

	 default:

//		 this->PIDParamitersValue(Key);

		 break;
	 }


	 this->Square(10,30);
	 this->RoadMove();
	 this->PrintMenu();

}

void LCDDrawing::PrintMenu(void)
{

	PrintText(textEkran,"PI PARAM", 8, 0, 0);

//	PrintText(textEkran, PiParamKp, 9, 0, 1);
//	PrintText(textEkran, PiParamKi, 9, 0, 2);
//	PrintText(textEkran, PiParamTi, 9, 0, 3);

	// Wy�wietlanie paramter�w obiektu regulacji
	PrintText(textEkran, "OBJ PARAM", 9, 30, 0);
//	PrintText(textEkran, ObjParamKp, 9, 30, 1);
//	PrintText(textEkran, ObjParamT, 9, 30, 2);

	// Wy�wietlanie warto�ci zak��cenia
	PrintText(textEkran, "DISRUPTION", 10, 30, 5);
//	PrintText(textEkran, DisParamZ, 8, 30, 6);

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

//void LCD::PIDParamitersValue(int CodeKay)
//{
//	switch(CodeKay)
//	{
//	case 1:				/* KP */
//		usKP += stepReg;
//	    PrinfLCD(PiParamKp, usKP);
//		break;
//
//	case 4:
//		usKP -= stepReg;
//	    PrinfLCD(PiParamKp, usKP);
//		break;
//
//	case 2: 			/* KI */
//		usKI += stepReg;
//	    PrinfLCD(PiParamKi, usKI);
//		break;
//
//	case 5:
//		usKI -= stepReg;
//	    PrinfLCD(PiParamKi, usKI);
//		break;
//
//	case 3: 			/* TI */
//		usTI += stepReg;
//	    PrinfLCD(PiParamTi, usTI);
//		break;
//
//	case 6:
//		usTI -= stepReg;
//		PrinfLCD(PiParamTi, usTI);
//		break;
//
//	case 7:				/* Z */
//		regZ += stepReg;
//		PrinfLCD(DisParamZ, regZ);
//		break;
//
//	case 9:
//		regZ -= stepReg;
//		PrinfLCD(DisParamZ, regZ);
//		break;
//
//	default:
//		break;
//	}
//}

void LCDDrawing::Square(int size_x, int size_y)
{
    for (int b=(0+gPosY); b<(size_y+gPosY); b++)
      for (int a=(0+gPosX); a<(size_x+gPosX); a++)
          SetPixel(ekran,a,b);
}

void LCDDrawing::Square(int size_x, int size_y, int pos_x, int pos_y)
{
    for (int b=(0+pos_y); b<(size_y+pos_y); b++)
      for (int a=(0+pos_x); a<(size_x+pos_x); a++)
          SetPixel(ekran,a,b);
}

void LCDDrawing::MoveSquare(int dx, int dy)
{
    if(gPosY < (LCD_H - 30))
    {
        gPosY += dy;
    }

    if(gPosX <= (LCD_W - 30))
    {
        gPosX += dx;
    }

}

void LCDDrawing::ClearScreen(void)
{
	 for (int a = 0; a < (128 * 8); a++)
		 ekran[a] = 0;
}


