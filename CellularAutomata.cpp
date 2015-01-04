#include<iostream>
#include "CellularAutomata.h"
#include<windows.h>

// Debug
// test getters
// test setters

// Pass by reference

// how to access adjacent objects in object arrays , how about function call

// improve performance with use of iterators

// if array of objects how to call function
//                     how to access data members of objects of same class

// Pass by reference

int main()
 {
 	int i;
 	int j;
 	
 	// number of time the simulations has to be run
 	int itr = 5;
 	
 	int rows = 10;
 	int columns = 10;
 	
 	int type = 0;
	float stiffness = 0.5;
	float divisionRate = 0.5;
	int size = 1;
	float contractility = 0.5;
	float invasiveness = 0.5;
	float degradationPotential = 0.5;
	float sensingRadius = 1;
	int fiberDensity = 5;
	float crossLinking = 0.5;
 	
 	// set the rows and columns in Cellular Automata
 	// Bhai! Static member ko set aur update kaise kare , member function , static member function
 	// variable ko public kare - that over looks why OOPS was used
 	
 	// automate better with run time allocation using new array of pointers to single rows with required columns;
 	CellularAutomata CA[12][12];
 	// Default constructor called on creation of two dimension array of computation cell
 	// Default set to ECM Sites type
 	
 	// row and columns considered as 10 * 10 , with padding row and columns on both sides
 	// The padding bounds the cell structure, also had default values, but are not considered for updating
 	
 	int initialState[12][12] = {0};
 	int currentState[12][12] = {0};
 	//int color[12][12] = {7};
 	float divRate[12][12] = {0.0};
 	
 	// considering the center cell as Biological cell 	
 	initialState[6][6] = 1;
 	
 	
 	// set the rows and columns in Cellular Automata
 	// use the layout to initialise user/pre defined ualues of Biological Cell and ECM Site
 	for( i=0; i<rows /* row -1 if padding*/ ; i++ )
 	 {
 	 	for ( j=0; j<columns /* columns -1  if padding considered */; j++ )
 	 	 {
 	 	 	// user / pre  defined values , and parameter list
 	 	 	
 	 	 	if( initialState[i][j] == 1 )
 	 	 	 {
 	 	 	 	// parameter list
 	 	 	 	// type, stiffness, divisionRate, size,	contractility, invasiveness, degradationPotential, sensingRadius
 	 	 	 	
 	 	 	 	CA[i][j].setBiologicalCellProperties(type, stiffness, divisionRate, size,	contractility, invasiveness, degradationPotential, sensingRadius); 	 	 	 	          	 	 	 			 
 	 	 	 	currentState[i][j] = 1;
 	 	 	 	//color[i][j] = 7;
 	 	 	 }
 	 	 	else
 	 	 	 {
 	 	 	 	// parameter list
 	 	 	 	// type, fiberDensity, crossLinking
 	 	 	 	CA[i][j].setECMSiteProperties(type, fiberDensity, crossLinking);
 	 	 	 	currentState[i][j] = 0;
 	 	 	 	//color[i][j] = 2;
 	 	 	 }
 	 	 }
 	 }
 	
 	
 	while( itr != 0 )
 	 {
 	 	// paralled computing
 		// omp opm .h macro par par for

		for( i=1; i<=rows; i++ )
	 	 {
	 	 	for ( j=1; j<=columns; j++ )
	 	 	 {
	 	 	 	CA[i][j].update(i,j,currentState);
	 	 	 	
	 	 	 	if( CA[i][j].isBiologicalCell() )
	 	 	 	 {
	 	 	 	 	//color[i][j] = int ( color[i][j] * CA[i][j].getDivisionRate() );
	 	 	 	 	divRate[i][j] = CA[i][j].getDivisionRate();
	 	 	 	 }	 	 	 	
	 	 	 }
	 	 } 		
 	 	
 	 	CA[0][0].printCellularAutomata(rows, columns, currentState , divRate);
 	 	 	 	
 	 	cout<<endl<<endl;
 	 	
 	 	itr--;
 	 }
 	
 	
 	
 	return(0);
 }
