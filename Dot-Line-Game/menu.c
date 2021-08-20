#include"menu.h"
#include<stdio.h>
#include"graphics.h"
#include<stdlib.h>

void menu(void)
{

	cleardevice();


	setcolor(BLUE);
	outtextxy(300, 20, "Dots and Boxes!");
	setcolor(GREEN);
	outtextxy(100, 100, "please choose one of the flowing option:");   /* tabe ghrafics menu baraye shoroe bazi*/
	setcolor(RED);
	outtextxy(100, 150, "1)Start game");
	setcolor(BROWN);
	outtextxy(100, 200, "2)select the turn");
	setcolor(RED);
	outtextxy(100, 250, "3)exit");                          /* chap text ha ghrafics ebtedaye bazi */
}

int sMenu()
{

	int i = 1,
		p,d;                      
	menu();
	printf("please inter 2 to chooae the turn and after enter 1 to start\n");
	printf("or enter 1 to start with default player\n");
	while(1)
	{
		scanf("%d", &p);

		if (p == 3)                         /*menu henghame bazi baraye exit & restart & main menu*/
		{
			exit(0);
		}

		if (p == 1)
		{
			cleardevice();
			break;
		}

		if (p == 2){
			printf("enter 1 to turn A\t");
			printf("enter 2 to turn B\n");
			scanf("%d",&d);
			                                    /* taeen turn bazi ba gherftn moteghayer d*/
			if (d == 2)
			{
				i = 0;
			}

			if (d == 1)
			{
				i = 1;
			}

		}

	}
	return i;
}