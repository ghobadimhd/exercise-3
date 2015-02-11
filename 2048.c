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
int isFull();// check screen for empty tiles 
// it's first make two new tile then get a direction and move the tile's 
// after merging tile it move them again and make new tile 
// if user can't move tile in any direction game is over 
int main(int argc, const char *argv[])
{
	int gameOver=0; // game not over yet 
	char direction;
	newTile();
	newTile();
	show();
	while (!gameOver) 
	{
		scanf(" %c%c%c",&direction,&direction,&direction);// it get three char esc(27), [ , and arrow char . we need last one 
		move(direction);
		merge(direction);
		move(direction);
		newTile();
		show() ;
		gameOver = isLose() ;
	}
	printf("You Lose !\n");
	return 0;
}
/*
this is function creating new tile  .
*/
void newTile()
{
	int   i , j ; // i and j are used for index's 
	if ( !isFull() )
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
		// so lineIndexChanger point to j and tileIndexChanger i
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
		// so lineIndexChanger point to i and tileIndexChanger point to j
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
/*
this is function for merging tile in specifice direction .
*/
void merge(char direction)
{
	int i , j // i and j used for index's of screen array
		,*lineIndexChanger // it's used to change i or j value dynamicly , so we can choose one of them as index of line
		,*tileIndexChanger // it's used to change i or j value dynamicly , so we can choose one of them as index of tile in line
		,tileToStart , tileToEnd // this variable indicate that we start from which side of line
		,stepDirection ;// it indicate direction of merging in line and work with tileToStart and tileToEnd , the value is 1 or -1
	
	if ( direction == up || direction == down  )
	{
		// if move direction was a vertical arrow , we should move through screen column and merge tile in vertical lines 
		// so lineIndexChanger point to j and tileIndexChanger i
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
		// if move direction was a horizontal arrow , we should move through screen rows and merge tile in horizontal lines 
		// so lineIndexChanger point to i and tileIndexChanger point to j
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
	
	// it try to merge aside tile in lines of screen depend on what lineIndexChanger point on :  i or j
	// it merge aside tile in screen column or screen  rows , if they have same value
	for (*lineIndexChanger = 0 ; *lineIndexChanger <4 ; (*lineIndexChanger)++) 
	{
		for (*tileIndexChanger = tileToStart ;  *tileIndexChanger != tileToEnd ; /* tileIndexChager change in loop body */) 
		{
			// this loop search for first non-empty tile in line with given direction 
			// save it in lastTile , move to next tile and check if two aside tile have equal values merge them 
			if ( screen[i][j] != 0 )
			{
				// merge means that it sum value of two tile and save it in last tile and current tile should be zero 
				int *lastTile = &screen[i][j] ;
				*tileIndexChanger += stepDirection ; // move to next tile 
				if ( screen[i][j] == *lastTile ) // merging aside tile if they have equal values 
				{
					 *lastTile *= 2 ;
					 screen[i][j] = 0 ;
				}
			}
			else 
				*tileIndexChanger += stepDirection ; // move to next tile 
		}
	}
}
/*
this is function for showing screen on stdout .
*/
void show()
{
	printf("%c[2J %c[H",27,27);// clear screen and move cursor to upper left corner 
	for (int i = 0; i <4; i++) 
	{
		for (int j = 0; j <4; j++) 
		{
			if( screen[i][j] == 0 ) 
				printf("|\t");
			else
				printf("|%d\t",screen[i][j]);
			
		}
		printf("\n");
	}
}
/*
this is function for checking that is user losed or not .
*/
int isLose()
{
	if( !isFull() )	
		return 0; // if there is empty tile on screen user has chance to success 
	// checking four middle tile 
	for (int i = 1; i <3; i++) 
	{
		for (int j = 1; j <3; j++) 
		{
			// looking for two tile with same value , if there is user is not losing
			if ( screen[i][j]==screen[i-1][j] || screen[i][j]==screen[i+1][j] 
				|| screen[i][j]==screen[i][j-1] || screen[i][j]==screen[i][j+1] )
			{
				return 0 ;
			}
		}
	}
	// checking corner tiles 
	
	if ( screen[0][0]==screen[0][1] || screen[0][0]==screen[1][0] // left upper 
		|| screen[0][3]==screen[0][2] || screen[0][3]==screen[1][3] // ritgt upper 
	  	|| screen[3][0]==screen[3][1] || screen[3][0]==screen[2][0] // left down 
	  	|| screen[3][3]==screen[3][2] || screen[3][3]==screen[2][3] ) // right upper 
	{
		return 0 ;
	}
	// middle tile of sides 
	if ( screen[0][1]==screen[0][2] // upper side 
		|| screen[3][1]==screen[3][2] //  downer side  
		|| screen[1][0]==screen[2][0] // left side 
		|| screen[1][3]==screen[2][3] ) // right side  
	{
		return 0 ;
	}
	
	return 1 ; // not lose 
}
/*
this is function for checking that is any empty tile on screen .
*/
int isFull()
{
	int *tiles = screen ; // tiles get us access to screen in linear way (one-demential) 
	
	// it's look for one free tile to prove that screen is not full 
	// it saw array as One-dimensional for decreasing loops 
	for (int i = 0; i < 16; i++) 
		if (tiles[i]==0 )
		{
			
			return 0 ; 
		}
}
