#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;

 int main()
  {
  	int x;
  	int y;
  	int itr = 20; 	 	
  	
	srand (time(NULL));
	  
	while( itr != 0 )
 	 {
 	 		x = rand() % 10 + 1;
			y = rand() % 10 + 1;
			
			cout<<"\n ( "<<x<<" , "<<y<<" )";
			
			itr--;
 	 }
  	
  	return(0);
  }	 	 	
			
