
// main driving program

#include<iostream>
#include "CellularAutomata.h"
#include<time.h>
#include<stdlib.h>
#include <fstream>


// Dimensions of cellular automata
#define ROWS 10
#define COLUMNS 10

// Check efficient random number generation - integers and (0,1)

// order of execution of updates to cells

// Free Space in Neighbourhood - check for ECM sites in Neighbourhood

// Improvements

// pointer to function for similar structure functions that only vary in function call in core of loops
// like print automata state in division rate, fiber density, degradation potential . . 
// writing results into file

// automate better with run time allocation using new array of pointers to single rows with required columns;

// improve performance with use of iterators

// paralled computing
// omp opm .h macro par par for parallel computing


// Check linking options in Dev C++ 
// In function definition - undefined reference to static variable , linker error -o

// Check Divide by zero problem , no exception thrown

// Try graph , form file with same parameters

int main()
 {
 	int i;
 	int j;
 	int k;
 	int simulation = 0;		//Counts from 0 to number of iterations
 	
 	// number of time the simulations has to be run
 	int itr = 2; 	 	
 	
 	// Default values of properties of Biological cell and ECM Site
 	
 	int identity = 0;
 	
 	int type = 0;
 	
 	int age = 0;
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
 	// Biological cells centered in the 10*10 Cellular Automata , of dimensions 3 * 3
 	
 	for ( i=4; i<=6; i++ )
 	 {
 	 	for( j=4; j<=6; j++ )
 	 	 {
 	 	 	initialState[i][j] = 1;
 	 	 }
 	 } 	
 	
 	cout<<"\nDefault Values set - \n";
 	
 	k=1;
 	for( i=1; i<= CA[0][0].getRows(); i++ )
	 	 {
	 	 	for ( j=1; j<= CA[0][0].getColumns(); j++ )
	 	 	 {	 	 	 	
	 	 	 	CA[i][j].setIdentity(k++);
	 	 	 }
	 	 } 			 	
 	
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
	
 	// Initialise random number generator
	srand (time(NULL));
 		
	CA[0][0].writeConstantsIdentityAndIterationsIntoFile(CA,itr);
 	
	while( simulation != itr )
 	 {
 	 	cout <<"\n Simulation - "<<++simulation;
 	 	
		CA[0][0].update(CA);		
		
		// now call write into file , instead of only once after iterations
		// open file in apend mode  	 			
		
		// CA[0][0].writeResultsToFile(CA,itr);
 	 } 	
 	
 	return(0);
 }
