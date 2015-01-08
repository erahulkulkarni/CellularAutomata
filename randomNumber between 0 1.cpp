#include <random>
#include <iostream>

#include<time.h>
#include<stdlib.h>

using namespace std;
 
int main()
{
	srand (time(NULL));
	int a;	
	int b;
	double c;
/*
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(1, 2);
    for (int n = 0; n < 10; ++n) {
        std::cout << dis(gen) << ' ';
    }
    std::cout << '\n';
    
*/
	for (int n = 0; n < 10; ++n) 
	{
		a = rand();
		//b = RAND_MAX;
		cout<<"\n a = "<<a<<"\t b = "<<b;
		
		//a = ( 1.0 * rand() / (RAND_MAX) ) ;        
    }
	 
}
