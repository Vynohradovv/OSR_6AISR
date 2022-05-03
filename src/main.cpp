////////////////////////////////////////////////////////
///////      Podstawowa konfiguracja
////////////////////////////////////////////////////////

#define BUFFERSYNC

////////////////////////////////////////////////////////


#include "main.h"

#ifdef TMSLAB_WIN
  #include "stdio.h"
#endif

unsigned long *ekran; // Adres obszaru graficznego LCD [8*128*2]


#ifdef TMSLAB_WIN

	unsigned short int *textEkran; // Adres obszaru tekstowego [40*16/2]
	extern int (*PartialRefresh)();
	char credits[43]="-               DEMO DISC                -";  // Tekst wyswietlany w naglowku symulatora
	long Timer2IsrPeriod=1; // okres pracy symulowanego licznika Timer2 podany w przybli�eniu w ms

#endif

int Tim = 0;                // Licznik uzytkownika
unsigned int preScale = 0;  // Preskaler licznika uzytkownika
volatile char EnableRefresh = 0;    //Zezwolenie na odswiezenie zawartosci pamieci graficznej

R_P_LCD_TMSLAB LCD;             // Obiekt obslugujacy LCD


int main()

{
        LCD.LCD_Init(&ekran,&textEkran);

       	OSM_World myWorld;

        while (1)
        {
            EnableRefresh = 1;
            LCD.Synchronize();
            EnableRefresh = 0;


            myWorld.DrawWay();


			#ifdef TMSLAB_WIN
            if(PartialRefresh()) return 0;
			#endif

        }
}

#ifdef TMSLAB_WIN
    void Timer2Isr()
    {
        if(++preScale==500)
        {   preScale=0;Tim++;}
    }
#endif
