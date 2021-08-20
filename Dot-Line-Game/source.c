#include <stdio.h>
#include"graphics.h"
#include<stdlib.h>
#include "menu.h"
#include "map.h"


int main()
{
	int i,p,j,e,a,b,x,y;
	char c;
	int emtiazA;                                        /* tarife motaghayer ha va araye ha dar barname */
	int emtiazB;
	int istherewinner=0;
	int map[6][6] = { 0 };
	int soton[6][6] = { 0 };
	int m[5][5]={0};

	initwindow(800, 600, "bgi");
	                                                                      /* ejade page aslye bazi */
	i = sMenu();
	clear(map, soton, m);
	map1();
	emtiazA=0;
	emtiazB=0;

	while (1){                                                           /* while koly benahayate barname */
		circlecolor(i);
		
		if (i % 2 == 0 )
		{
			printf("playerB:\n");                              /* zooj namayande nobat B va fard namayande A */
		}

		if (i % 2 == 1 )
		{
			printf("playerA:\n");
		}
		
		scanf("%d", &e);
		scanf("%d", &x);                           
		scanf("%d", &y);                                          /* gereftn moteghayer ha az voorody */
		x--;
		y--;                                                                

		if(e==0 && x==-1 && y==0)           
		{	
			cleardevice();                              /* farayande restart va astefade az tabe clear baraye khaly kardane araye */
			clear(map, soton, m);

			map1();
			emtiazA=0;
			emtiazB=0;
			continue;
		}		

		if(e==0 && x==-1 && y==2)                             
		{
			                                                         /* farayande exit */
			exit(1);
		}

		if(e==0 && x==-1 && y==1)
		{
			i = sMenu();
			clear(map, soton, m);                                  /* farayande bazghasht be menu */
			map1();
			emtiazA=0;
			emtiazB=0;
			continue;
		}

		if(checkBounded(e, x, y, map, soton))                     /* astefade az tabe check mahdoode */
			continue;

		if (e == 0)
		{
			map[x][y] = 1;                                    /* alghoritm por kardan araye soton ha va satr ha */
		}

		else if (e == 1)
		{
			soton[x][y] = 1;
		}

		if(e==0)
		{
			if(map[x][y]==1 && map[x+1][y]==1 && soton[x][y]==1 && soton[x][y+1]==1)
			{
				if(i%2==0)
				{                                                     /* shart moraba boodan baray azlae ofoghy va nahve elame reward*/
					m[x][y]=2;
					emtiazB++;
					istherewinner=1;
				}
				if(i%2==1)
				{
					m[x][y]=3;
					emtiazA++;
					istherewinner=1;
				}
			}

			if(map[x][y]==1 && map[x-1][y]==1 && soton[x-1][y]==1 && soton[x-1][y+1]==1)
			{
				if(i%2==0)
				{
					m[x-1][y]=2;             /* shart moraba boodan baray azlae ofoghy va nahve elame reward*/
					emtiazB++;
					istherewinner=1;
				}

				if(i%2==1)
				{
					m[x-1][y]=3;
					emtiazA++;
					istherewinner=1;
				}
			}
		}

		if(e==1)
		{
			if(map[x][y]==1 && map[x+1][y]==1 && soton[x][y]==1 && soton[x][y+1]==1)
			{
				if(i%2==0)
				{
					m[x][y]=2;         /* shart moraba boodan baray azlae amoody va nahve elame reward*/
					emtiazB++;
					istherewinner=1;
				}

				if(i%2==1)
				{
					m[x][y]=3;
					emtiazA++;
					istherewinner=1;
				}
			}

			if(map[x][y-1]==1 && map[x+1][y-1]==1 && soton[x][y]==1 && soton[x][y-1]==1)
			{
				if(i%2==0)
				{
					m[x][y-1]=2;
					emtiazB++;
					istherewinner=1;                  /* shart moraba boodan baray azlae amoody va nahve elame reward*/
				}

				if(i%2==1)
				{
					m[x][y-1]=3;
					emtiazA++;
					istherewinner=1;
				}
			}
		}

		printMap(map, soton, m, e, x, y, i);             /* estefade az tabe tarif shode rasm khotot gheraficy ofooghy va amoody*/

		if(istherewinner)
		{
			i++;
			istherewinner=0;                         /* baresy voogode moraba baraye reward dadn*/
		}

		i++;                     /* turn nobat*/

		if(emtiazA + emtiazB==25)                  /* shart taeen barande*/
		{
			
			printf("emtiaz A: %d \n emtiaz B: %d \n",emtiazA,emtiazB);        /* chap emtiazat*/
			cleardevice();

			winner(emtiazA, emtiazB);           /* tabe taeen barande*/

			scanf(" %c",&c);
			if(c=='e')
			{                           
				exit(0);
			}
			                           
			if(c=='q')
			{
				i = sMenu();
				clear(map, soton, m);
				map1();                            /* farayand gereftn char baraye restart & menu & exit */
				emtiazA=0;
				emtiazB=0;
				continue;
			}
			if(c=='r')
			{
				restart(map, soton, m);
				emtiazA=0;
				emtiazB=0;
				continue;
			}
		}
	}  /* while koly barname */
}