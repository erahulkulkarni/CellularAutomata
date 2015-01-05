#include<iostream>

//pass array

using namespace std;

class A
 {
 	private:
	 int n;
 	
 	public:
 	 int getA()	
 	  {
 	  	return n;
 	  }
 	 
	 void setA( int value)  
	  {
	  	n = value;
	  }
 	
 	 void print(A arr[][])
 	  {
 	  	int i;
 	  	
 	  	cout<<endl;
 	  	
 	  	for( i=0; i<10; i++ )
 	  	 { 	  	 	
			cout<<" "<<arr[i][0].getA();
			arr[i][0].setA(arr[i][0].getA()*10);
 	  	 }
 	  }
 };
 
 int main()
  {
  	A arr[10][10];
  	
  	for( int i=10; i>0; i-- )
  	 {
  	 	arr[10-i][0].setA(i);
  	 }
  	 
  	arr[0][0].print(arr);
/*  	
  	for( int i=0; i<10; i++ )
  	 {
  	 	arr[i].setA(i);
  	 }
*/  	 
  	arr[0].print(arr);
  	
  	arr[0].print(arr);
  	
  	return(0);
  }
