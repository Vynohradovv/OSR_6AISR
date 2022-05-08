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

extern unsigned long *ekran; /* 240 x 128 */
extern unsigned short int* textEkran;

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
		 break;
	 }

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


