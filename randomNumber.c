/* rand example: guess the number */
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

int main ()
{
  int iSecret, iGuess;
  int times = 10;
  
  srand (time(NULL));
  
  while(times !=0 )
   {   	   	
	  /* initialize random seed: */
	  
	
	  /* generate secret number between 1 and 10: */
	  iSecret = rand() % 10 + 1;
	  
	  printf("\n%d",iSecret);
   	
   	times--;
   }

  return 0;
}
