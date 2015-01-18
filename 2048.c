/*
2048	2015-01-18 08:01
Program name : 2048
Author : Mohammad Ghobadi
Email : ghobadi.mhd@outlook.com
describtion : This is cool game  .
*/
#include <stdio.h>
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
	show();
	while (gameNotOver) 
	{
		scanf(" %c%c%c",&move,&move,&move);// it get three char esc(27), [ , and arrow char . we need last one 
		move(direction);
		merge(direction);
		move(direction);
		newTile();
		show() ;
		gameNotOver = isLose() ;
	}
	
	return 0;
}
