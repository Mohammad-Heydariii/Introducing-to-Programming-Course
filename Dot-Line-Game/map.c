
#include"map.h"
#include <stdio.h>
#include"graphics.h"
#include<stdlib.h>



void clear(int x[6][6], int y[6][6], int z[5][5])  /*tavabe marbote be bakhsh map bazi*/
{
	int k,j;
	for(k=0;k<6;k++)
	{
		for(j=0;j<6;j++)         /* tabe khaly kardan arraye ha*/
		{
			x[k][j]=0;
		}
	}

	for(k=0;k<6;k++)
	{                               /* tabe khaly kardan arraye ha*/
		for(j=0;j<6;j++)
		{
			y[k][j]=0;
		}
	}

	for(k=0;k<5;k++)
	{
		for(j=0;j<5;j++)
		{
			z[k][j]=0;
		}
	}
}

void map1(void){






	setfillstyle(SOLID_FILL, GREEN);                  /* tabe rasme map bazi*/
	floodfill(100, 100, GREEN);

	for (int i = 1; i < 7; i++){
		for (int j = 1; j < 7; j++){
			setcolor(BLACK);                
			circle(i * 60, j * 60,4);
			setfillstyle(SOLID_FILL, BLACK);           /* tabe rasme map bazi*/
			floodfill(i * 60, j * 60, BLACK);

		}
	}




	setcolor(COLOR(255,128,64));
	outtextxy(450,200,"enter 0 0 1 to restart the game");    /* menu henghame bazi*/
	outtextxy(450,220,"enter 0 0 2 to return the main menu");
	outtextxy(450,240,"enter 0 0 3 to exit the game");








}

void printMap(int map[6][6], int soton[6][6], int m[5][5], int e, int x, int y, int turn)
{
	int a, b;                                      /* tabe rasme khotote ofooghy va amoody va rasme circle ha*/
	for (a = 0; a < 5; a++){
		for (b = 0; b <5; b++){                      
			if (map[a][b] == 1 && e == 0){

				if (turn % 2 == 0){
					setcolor(BLUE);
				}
				if (turn % 2 == 1){
					setcolor(RED);                   /* tabe rasme khotote ofooghy va amoody va rasme circle ha*/
				}

				line(60 * (y+1), 60 * (x+1), 60 * (y + 2), 60 * (x+1));
				line(60 * (y+1), 60 * (x+1)+1, 60 * (y + 2), 60 * (x+1)+1);
				line(60 * (y+1), 60 * (x+1)-1, 60 * (y + 2), 60 * (x+1)-1);
				line(60 * (y+1), 60 * (x+1)-2, 60 * (y + 2), 60 * (x+1)-2);
			}



			if (soton[a][b] == 1 && e == 1){


				if (turn % 2 == 0){
					setcolor(BLUE);                           /* tabe rasme khotote ofooghy va amoody va rasme circle ha*/
				}
				if (turn % 2 == 1){
					setcolor(RED);
				}


				             /* tabe rasme khotote ofooghy va amoody va rasme circle ha*/

				line(60 * (y+1), 60 *( x+1), 60 *( y+1), 60 * (x + 2));
				line(60 * (y+1)+1, 60 *( x+1), 60 *( y+1)+1, 60 * (x + 2));
				line(60 * (y+1)-1, 60 *( x+1), 60 *( y+1)-1, 60 * (x + 2));
				line(60 * (y+1)-2, 60 *( x+1), 60 *( y+1)-2, 60 * (x + 2));



			}
			                   

			if(m[a][b]==3)                  /*sharte ejade moraba va rasme gheraficy circle ha*/
			{
				setcolor(RED);
				circle(90+60*b,60*(a+1) + 30,20);
				setfillstyle(SOLID_FILL,RED);
				floodfill(90+60*b,60*(a+1) + 30,RED);
			}


			if(m[a][b]==2)                  /*sharte ejade moraba va rasme gheraficy circle ha*/
			{
				setcolor(BLUE);
				circle(90+60*b,60*(a+1) + 30,20);
				setfillstyle(SOLID_FILL,BLUE);
				floodfill(90+60*b,60*(a+1) + 30,BLUE);
			}
		}

	}
}

bool checkBounded(int e, int x, int y, int map[6][6], int soton[6][6])
{

	if(e==0 && y>=5){
		printf("out of renge\n");      /* ckeck mahdoode */
		return true; // error
	}


	if(x<=-2 || y<=-1 || e>1 || e<0){
		printf("undefined\n");      /* ckeck mahdoode */
		return true; // error
	}

	if(x==-1 && y>=0){
		printf("undefined\n");      /* ckeck mahdoode */
		return true; // error
	}


	if(e==1 && y>=6){                       
		  
		printf("out of renge\n");       /* ckeck mahdoode */
		return true; // error
	}

	if(e==1 && x>=5){
		printf("out of renge\n");   /* ckeck mahdoode */
		return true; // error
	}
	if(e==0 && x>=6){

		printf("out of renge\n");        /* ckeck mahdoode */
		return true; // error
	}


	if( (e==0 && map[x][y]==1) || (e==1 && soton[x][y]==1) )
	{                                                                      /*tabe baresy estefade shide haye khotot*/
		printf("estefadeh shiode ast\n");
		return true; // error
	}

	return false;

}

void restart(int map[6][6], int soton[6][6], int m[5][5])
{                  
	int i,j;                                             /*   tebe restart */
	cleardevice();
	clear(map, soton, m);



	map1();
}

void winner(int emtiazA, int emtiazB)
{
	char pointA[45];                                            /* tabe taeen barande */
	char pointB[45];

	setcolor(COLOR(0,128,192));             
	outtextxy(100,500,"enter 'r' to restart the game");                     /* menu akhare bazi*/
	outtextxy(100,520,"enter 'q' to return the main menu");
	outtextxy(100,540,"enter 'e' to exit the game");

	setcolor(RED);
	circle(200,100,50);
	setfillstyle(SOLID_FILL,RED);
	floodfill(200,100,RED);                                 /*kar haye gherafics*/
	setcolor(BLUE);
	circle(550,100,50);
	setfillstyle(SOLID_FILL,BLUE);
	floodfill(550,100,BLUE);
	sprintf(pointA,"player A=%d",emtiazA);                    /* tabe sprintf baraye rasme emtiaz ha */
	sprintf(pointB,"player b=%d",emtiazB);
	setcolor(RED);
	outtextxy(260,100,pointA);
	setcolor(BLUE);
	outtextxy(610,100,pointB);
	if(emtiazA > emtiazB){                              /* sharte barande shoodan A */
		setcolor(RED);
		circle(400,400,50);
		setfillstyle(SOLID_FILL,RED);
		floodfill(400,400,RED);
		outtextxy(450,400,"player A is winner");        
	}


	else
	{
		setcolor(BLUE);                                             /* sharte barande shoodan B */
		circle(400,400,50);
		setfillstyle(SOLID_FILL,BLUE);
		floodfill(400,400,BLUE);
		outtextxy(450,400,"player B is winner");
	}
}

void circlecolor(int i)
{
	if(i%2==1){

			setcolor(RED);
			circle( 500,500, 50);
			setfillstyle(SOLID_FILL, RED);                      /* taeene range circle haye rasm shode */
			floodfill(500, 500, RED);

			setcolor(COLOR(0,128,192));
			outtextxy(560, 500, "playerA");

		}

		if(i%2==0)
		{
			setcolor(BLUE);                                    /* taeene range circle haye rasm shode */
			circle(500, 500, 50);
			setfillstyle(SOLID_FILL, BLUE);
			floodfill(500, 500, BLUE);

			setcolor(COLOR(0,128,192));
			outtextxy(560, 500, "playerB");
		}
}