/*
 * world.cpp
 *
 *  Created on: May 3, 2022
 *      Author: Anton
 */
#include "setup.h"
#include "world.h"
#include "R_P_KEYBOARD_TMSLAB.h"

extern unsigned long *ekran; /* 240 x 128 */
extern unsigned short int* textEkran;

R_P_KEYBOARD_TMSLAB WorldKey;

void OSM_World::DrawArrow1(void)
{
	for(int i=0; i< LCD_H/2; i++)
	{
		if(!(i%5))
		{
			SetPixel(ekran,i, (i - 10));
		}
	}
}

void OSM_World::DrawArrow9(void)
{
	for(int i = LCD_H; i > LCD_H/2; i--)
	{
		if(!(i%5))
		{
			SetPixel(ekran,(i+(LCD_W/2)), i);
		}
	}
}

void OSM_World::DrawArrow3(void)
{
	/* Do zrobienia*/
}

void OSM_World::DrawArrow4(void)
{
	for(int i=30; i< 100; i++)
	{
		if(!(i%5))
		{
			SetPixel(ekran,i, LCD_H/2);
		}
	}
}

void OSM_World::DrawArrow7(void)
{
	/* Do zrobienia*/
}

void OSM_World::DrawArrow6(void)
{
	for(int i=210; i > 140; i--)
	{
		if(!(i%5))
		{
			SetPixel(ekran,i, LCD_H/2);
		}
	}
}


OSM_World::OSM_World(void)
{
	WorldKey.InitKB(100);
}

void OSM_World::DrawWay(void)
{

	 unsigned char Key = WorldKey.GetKey();

	 switch(Key)
	 {
	 case 1:
		 this->DrawArrow1();
		 break;
	 case 3:
		 this->DrawArrow3();
		 break;
	 case 4:
		 this->DrawArrow4();
		 break;
	 case 6:
		 this->DrawArrow6();
		 break;
	 case 7:
		 this->DrawArrow7();
		 break;
	 case 9:
		 this->DrawArrow9();
		 break;

	 default:

		 this->ClearScreen();

		 for(int i=0; i< LCD_H; i++)
		 {
			 if(!(i%20))
			 {
				 SetPixel(ekran,(LCD_W/2),i);
			 }
		 }
		 break;
	 }
}

void OSM_World::ClearScreen(void)
{
	 for (int a = 0; a < (128 * 8); a++)
		 ekran[a] = 0;
}


