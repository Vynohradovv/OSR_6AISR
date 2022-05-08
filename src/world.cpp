/*
 * world.cpp
 *
 *  Created on: May 3, 2022
 *      Author: Anton
 */
#include "setup.h"
#include "world.h"
#include "R_P_KEYBOARD_TMSLAB.h"

#include "square.h"

#include <stdio.h>

extern unsigned long *ekran; /* 240 x 128 */
extern unsigned short int* textEkran;
extern int Tim;                // Licznik uzytkownika

R_P_KEYBOARD_TMSLAB WorldKey;

void OSM_World::DrawArrowRight(void)
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


void OSM_World::DrawArrowLeft(void)
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


OSM_World::OSM_World(void)
{
    arrow_size = 15;
    gPosX = 115;
    gPosY = 50;
}

void OSM_World::DrawWay(unsigned char &Key)
{

	 switch(Key % 10)
	 {
	 case 1:
		 break;
	 case 3:
		 break;
#ifdef TMSLAB_C2000
	 case 8:
#else
	 case 4:
#endif
		 this->DrawArrowRight();
		 break;
	 case 6:
		 this->DrawArrowLeft();
		 break;
	 case 7:
		 break;
	 case 9:
		 break;

	 default:

		 this->ClearScreen();
		 this->Square(10,30);
		 this->RoadMove();
		 this->PrintMenu();
		 break;
	 }

}

void OSM_World::PrintMenu(void)
{
	char PiParam [] 	= "PI PARAM";
	char PiParamKp [] 	= "Kp =     ";
	char PiParamKi [] 	= "Ki =     ";
	char PiParamTi [] 	= "Ti =     ";

	char ObjParam [] 	= "OBJ PARAM";
	char ObjParamKp [] 	= "Kp =     ";
	char ObjParamT [] 	= "T  =     ";

	char DisParam [] 	= "DISRUPTION";
	char DisParamZ [] 	= "Z =     ";

	disp_val = Tim;
	printf("my class time %i \n",Tim);

	PrintText(textEkran,PiParam, 8, 0, 0);

	sprintf(PiParamKp + 5,"%d.%02u", (int) disp_val, (int) ((disp_val - (int) disp_val ) * 100) );
	sprintf(PiParamKi + 5,"%d.%02u", (int) disp_val, (int) ((disp_val - (int) disp_val ) * 100) );
	sprintf(PiParamTi + 5,"%d.%02u", (int) disp_val, (int) ((disp_val - (int) disp_val ) * 100) );


	PrintText(textEkran,PiParamKp, 9, 0, 1);
	PrintText(textEkran, PiParamKi, 9, 0, 2);

	PrintText(textEkran, PiParamTi, 9, 0, 3);


	// Wy�wietlanie paramter�w obiektu regulacji
	sprintf(ObjParamKp + 5,"%d.%02u", (int) disp_val, (int) ((disp_val - (int) disp_val ) * 100) );
	sprintf(ObjParamT + 5,"%d.%02u", (int) disp_val, (int) ((disp_val - (int) disp_val ) * 100) );
	sprintf(DisParamZ + 4,"%d.%02u", (int) disp_val, (int) ((disp_val - (int) disp_val ) * 100) );

	PrintText(textEkran, ObjParam, 9, 30, 0);
	PrintText(textEkran, ObjParamKp, 9, 30, 1);
	PrintText(textEkran, ObjParamT, 9, 30, 2);

	// Wy�wietlanie warto�ci zak��cenia
	PrintText(textEkran, DisParam, 10, 15, 0);
	PrintText(textEkran, DisParamZ, 8, 16, 1);

}

void OSM_World::RoadMove(void)
{
    for(int i=0; i< LCD_H; i++)
    {
        if(!(i%5))
        {
            SetPixel(ekran,(LCD_W/2),i);
        }

        SetPixel(ekran,(LCD_W/2 - 10),i);
        SetPixel(ekran,(LCD_W/2 + 10),i);
    }

  //  this->Square(10, 5, 50, 50);
}

void OSM_World::Square(int size_x, int size_y, int pos_x, int pos_y)
{
    for (int b=(0+pos_y); b<(size_y+pos_y); b++)
      for (int a=(0+pos_x); a<(size_x+pos_x); a++)
          SetPixel(ekran,a,b);
}

void OSM_World::MoveSquare(int dx, int dy)
{
    if(gPosY < (LCD_H - 30))
    {
        gPosY += dy;
    }

    if(gPosX < (LCD_W - 30))
    {
        gPosX += dx;
    }

}

void OSM_World::Square(int size_x, int size_y)
{
    for (int b=(0+gPosY); b<(size_y+gPosY); b++)
      for (int a=(0+gPosX); a<(size_x+gPosX); a++)
          SetPixel(ekran,a,b);
}

void OSM_World::ClearScreen(void)
{
	 for (int a = 0; a < (128 * 8); a++)
		 ekran[a] = 0;
}


