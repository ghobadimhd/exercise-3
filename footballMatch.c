/*
footballMatch	2014-12-24 19:12
Program name : Football Match
Author : Mohammad Ghobadi
Email : ghobadi.mhd@outlook.com
describtion : This is program for predict possblity of a wininig football match .
*/
#include <stdio.h>
#include <math.h>
int main(int argc, const char *argv[])
{
	int games , neededScore , win , equal , lose ;
	double chance=0 ;
	printf("> ");// next games info : number of games and needed Score 
	scanf("%d%d",&games,&neededScore);
		while (games != 0 && neededScore != 0 ) 
		{
			chance = 0;
			printf("> ");// last games info 
			scanf(" %d%d%d",&win,&equal,&lose);
			int sum =win + equal + lose ;
			double  winChance = (double)win  / sum ,equalChance = (double)equal / sum , loseChance =(double) lose / sum ;
			for (int winOrEqual = 1; winOrEqual <=games; winOrEqual++) 
			{
				for (int equals = 0; equals <=winOrEqual; equals++) 
				{
					// Equal games have 1 score that mach with number of gamase 
					int winScore = (winOrEqual -equals )	* 3 , thisGameScore = winScore + equals;
					if(neededScore <= thisGameScore )
					{
						// calculatin this game possibility 
						double thisGamePossibility = pow(winChance,(double) winOrEqual - equal) * pow(equalChance,(double)equal) * pow(loseChance , (double)games - winOrEqual);
						// add to total chance of get needed score (this or other game happened)
						chance += thisGamePossibility ;


					}

				}
			}


			printf("%4.1f\n",chance);
			// get next games info : number of games and needed Score 
			printf("> ");
			scanf(" %d%d",&games,&neededScore);
		}
	return 0;
}
/*
this is function calcutatin power of number  .
*/
double  pow(double number ,double toPower)		
{
	double power =1 ;
	for (int i = 1; i <=toPower; i++) 
	{
		power *= number ;
	}
	return power;
}
