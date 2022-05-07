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

void OSM_World::DrawArrow4(void)
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
}


void OSM_World::DrawArrow6(void)
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
		 break;
	 case 3:
		 break;
	 case 4:
		 this->DrawArrow4();
		 break;
	 case 6:
		 this->DrawArrow6();
		 break;
	 case 7:
		 break;
	 case 9:
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


