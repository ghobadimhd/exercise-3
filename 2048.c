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
		//move(direction);
		//merge(direction);
		//move(direction);
		//newTile();
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
