#include<iostream>
#include <fstream>

using namespace std;

int main()
 {
 	int i;
 	
	ofstream divisionRateFileStream;	
	ofstream stiffnessFileStream;
	
	divisionRateFileStream.open ("DivisionRate.txt");
	stiffnessFileStream.open ("Stiffness.txt");
	
	for( i=0; i<10; i++ )
	 {
	 	divisionRateFileStream << stiffnessFileStream << i <<" ";
	 }
	
	divisionRateFileStream.close();		
	stiffnessFileStream.close();		
	
 	return 0;
 }
