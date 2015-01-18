/*
2048	2015-01-18 08:01
Program name : 2048
Author : Mohammad Ghobadi
Email : ghobadi.mhd@outlook.com
describtion : This is cool game  .
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define up 'A'
#define down 'B'
#define right 'C'
#define left 'D'
void move(char);// it's move tiles to a specifice side 
void merge(char);// it's merge (sum value of ) adjust tile's by getting side (or last move) 
void newTile();// it create a tile in random location with random value 
void show();// it print down tile in stdout in good format 
int isLose();// it check that if user lose 
int screen[4][4]= {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};// this our tile's screen  
// it's first make two new tile then get a direction and move the tile's 
// after merging tile it move them again and make new tile 
// if user can't move tile in any direction game is over 
int main(int argc, const char *argv[])
{
	int gameNotOver=1; // game not over yet 
	char direction;
	newTile();
	newTile();
	//show();
	while (gameNotOver) 
	{
		scanf(" %c%c%c",&direction,&direction,&direction);// it get three char esc(27), [ , and arrow char . we need last one 
		move(direction);
		//merge(direction);
		move(direction);
		newTile();
		//show() ;
		//gameNotOver = isLose() ;
	}
	
	return 0;
}
/*
this is function creating new tile  .
*/
void newTile()
{
	int isFull=1 ,  i , j // i and j are used for index's 
			, *tiles = screen ; // tiles get us access to screen in linear way 
	
	// it's look for one free tile to prove that screen is not full 
	// it saw array as One-dimensional for decreasing loops 
	for (i = 0; i < 16; i++) 
		if (tiles[i]==0 )
		{
			isFull=0;
			break ; 
		}

	if ( !isFull )
	{
		// looking for a random free tile for new Tile 
		do 
		{
			i=rand() % 4;
			j=rand() % 4;
		} while (screen[i][j]!= 0);
	int randomPower = rand() % 2  + 1 
		, newTileValue = pow(2,randomPower);// tile value should be power of 2 , and almost 2 and 4 

	// random tile appeared on screen 
	screen[i][j]=newTileValue ; 
	}
	
}
/*
this is function for moving tile in specifice direction .
*/
void move(char direction)
{
	int i , j // i and j used for index's of screen array
		,*lineIndexChanger // it's used to change i or j value dynamicly , so we can choose one of them as index of line
		,*tileIndexChanger // it's used to change i or j value dynamicly , so we can choose one of them as index of tile in line
		,tileToStart , tileToEnd // this variable indicate that we start from which side of line
		,stepDirection ;// it indicate direction of moving in line and work with tileToStart and tileToEnd , the value is 1 or -1
	
	if ( direction == up || direction == down  )
	{
		// if move direction was a vertical arrow , we should move through screen column and move tile in vertical lines 
		// so lineIndexChanger point to i and tileIndexChanger j
		lineIndexChanger = &j ;
		tileIndexChanger = &i ;
		if(direction == up)
		{
			tileToStart=0;
			tileToEnd=3 ;
			stepDirection = 1 ;
		}
		else 
		{
			tileToStart = 3 ;
			tileToEnd = 0 ;
			stepDirection = -1 ;
		}
		
	}
	 if ( direction == left || direction == right  )
         {
		// if move direction was a horizontal arrow , we should move through screen rows and move tile in horizontal lines 
		// so lineIndexChanger point to j and tileIndexChanger point to i
                 lineIndexChanger = &i ;
                 tileIndexChanger = &j ;
                 if(direction == left)
                 {
                         tileToStart=0;
                         tileToEnd=3 ; 
                         stepDirection = 1 ;
                }
                 else
                 {
                         tileToStart = 3 ;
                         tileToEnd = 0 ; 
                         stepDirection = -1 ;
                 }
          
         }
	
	// it try to move tile in lines of screen depend on what lineIndexChanger point on :  i or j
	// it move tile in screen column or screen  rows 
	for (*lineIndexChanger = 0; *lineIndexChanger <4; (*lineIndexChanger)++) 
	{
		for (*tileIndexChanger = tileToStart;  *tileIndexChanger != tileToEnd; *tileIndexChanger += stepDirection) 
		{
			// it search for first empty tile in line with given direction 
			// and change the value of empty tile  with value of first non-empty tile after it  
			if ( screen[i][j] == 0 )
			{
				// saving tileIndexChanger in temp help us continue current loop after next loop done 
				// zeroTile help us to change the values of the tiles in next loop
				int *zeroTile = &screen[i][j] , temp=*tileIndexChanger ;
				// it search for first non-empty tile after zeroTile and change it with zeroTile 
				for (*tileIndexChanger += stepDirection ;*tileIndexChanger != tileToEnd + stepDirection; *tileIndexChanger += stepDirection) 
					if ( screen[i][j] != 0 )
					{
						*zeroTile=screen[i][j];
						screen[i][j]=0 ;
						break ;
					}
				// fix tileToChange value , so previose loop work currectly 
				*tileIndexChanger=temp ;
			}
		}
	}

}
