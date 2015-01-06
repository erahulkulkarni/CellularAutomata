// main driving program

#include<iostream>
#include "CellularAutomata.h"

// Dimensions of cellular automata
#define ROWS 10
#define COLUMNS 10

// Improvements

// automate better with run time allocation using new array of pointers to single rows with required columns;

// To print in color include windows .h #include<windows.h>

// improve performance with use of iterators

// paralled computing
// omp opm .h macro par par for parallel computing


// Check linking options in Dev C++ 
// In function definition - undefined reference to static variable , linker error -o

// Pass by reference

// if array of objects how to call function
//                     how to access data members of objects of same class

// Pass by reference

int main()
 {
 	int i;
 	int j;
 	int simulation = 0;
 	
 	// number of time the simulations has to be run
 	int itr = 5; 	 	
 	
 	// Default values of properties of Biological cell and ECM Site
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
 	 	 	 	 	 		
	//Setting dimensions with padding 
 	CellularAutomata CA[12][12];
 	// Default constructor called on creation of two dimension array of computation cell
 	// Default set to ECM Sites type
 	
	// set the rows and columns in Cellular Automata
 	CA[0][0].setRows(ROWS);
 	CA[0][0].setColumns(COLUMNS); 	  	 	 	 	
 	
 	// row and columns considered as 10 * 10 , with padding row and columns on both sides
 	// The padding bounds the cell structure, also had default properties values, but are not considered for updating
 	
//you already have these values , why create once again
	
	//We can use an array for initail state of types of cells in Cellular Automata
 	
	int initialState[12][12] = {0};
 	int currentState[12][12] = {0}; 	
 	
 	
 	// considering the center cell as Biological cell 	
 	initialState[3][3] = 1;
 	initialState[5][5] = 1;
	initialState[5][6] = 1;
	initialState[6][6] = 1;
	initialState[5][6] = 1;
	initialState[8][8] = 1;
	initialState[8][9] = 1;
	
	initialState[7][2] = 1;
	initialState[7][3] = 1;
	initialState[8][2] = 1;
	initialState[8][3] = 1;
 	
 	
 	cout<<"\nDefault Values set - \n";
 	
 	CA[0][0].printCellularAutomata(CA); 	 	 	
 	
	// For User defined cell grid of cell types , set property values
		
 	// use the layout to initialise user/pre defined ualues of Biological Cell and ECM Site
 	 	
 	for( i=1; i<= CA[0][0].getRows(); i++ )
	 	 {
	 	 	for ( j=1; j<= CA[0][0].getColumns(); j++ )
	 	 	 {
	 	 	 	CA[i][j].setType(initialState[i][j]);
	 	 	 }
	 	 }
	
	cout<<"\nUser defined Biological Cell , ES Set - \n";
	
	CA[0][0].printCellularAutomata(CA);	 	
	
 	
 	while( itr != 0 )
 	 {
 	 	cout <<"\n Simulation - "<<++simulation;
		CA[0][0].update(CA);
 	 	
 	 	CA[0][0].printCellularAutomata(CA);
 	 	 	 	
 	 	cout<<endl<<endl;
 	 	
 	 	itr--;
 	 }
 	
 	
 	
 	return(0);
 }
