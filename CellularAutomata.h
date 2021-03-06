// Concept of Database - normalize functions
// break it to atomic functions
// Get Properties , Set Properties

// class of Cellular Automata - containing properties of Biological Cell and ECM Sites

// Neighbourhood of a cell as 8 Adjacency

// Check linking options in Dev C++ 
// In function definition - undefined reference to static variable , linker error -o

// generate state function

// Fiber Density Going Negative

// Optimize File Write function


#include<stdlib.h>
#include<time.h>
#include <fstream>

using namespace std;

// Dimensions of cellular automata
#define ROWS 10
#define COLUMNS 10

// number of time the simulations has to be run
#define ITERATIONS 100
	
#define ECMSite 0	// type 0 - ECM site or ES
#define CSC 1		// type 1 - Cancer Stem Cell
#define TAC 2		// type 2 - Transient Amplifying Cells
#define TDC 3		// type 3 - Terminally Differentiated Cell

#define ALPHA 0.5
#define BETA 25
#define GAMMA 50

#define TRIES 8		//Number to tries to find free random cell in neighbourhood


class CellularAutomata
 {
 	//class variables  	 	

 	private:
	//Variables to set dimensions of Cellular Automata
 	// rows for number of rows
 	// columns for number of columns
 	// dimensions - rows * columns number of computational cells
 	// static to create only one copy of varaibles rows and columns
	static int rows;
 	static int columns; 	 	
	
	
	// Each cell is assigned identity
	
	int identity;
	
	// static , integer to generate sequential numbers , may not be useful as we are using boundary cells
	static int id;
	
	//Variable to identify if Computational Cell is a Biological Cell or ECM Site
	 	
 	// type set to 0 - considered as ECM site , not a Biological Cell
 	
 	// Following are Types of Biological Cells
 	// type set to 1 - CSC Cancer Stem Cell
 	// type set to 2 - TAC Transient Amplifying Cells
	// type set to 3 - TDC Terminally Differentiated Cell
	 	
	int type;	//{ 0, 1, 2, 3 }
 	
 	
 	//Properties of Biological Cell
 	
 	// Age of Biological cell
	int age; 	
 	
 	// Stiffness of Biological Cell - (0,1) , how wasy it is to move => remove obstacles
 	float stiffness;
 	
 	// Division Rate also known as Doubling Time of  Biological Cell - (0,1)
 	float divisionRate;
 	
 	// Size of the Biological Cell - starting with assumption size = 1 , one Biological Cell occupies only one Computational Cell
 	int size;
 	
 	// Contractility of the Biological Cell - (0,1) 
 	float contractility;
 	
 	// Invasiveness also known as Migration Potential of the Biological Cell
 	float invasiveness;
 	
 	// Degradation Potential of the Biological Cell or potential capacity to degrade ECM
 	float degradationPotential; 	
 	
 	
 	// Sensing Radius of the Biological Cell - starting with assumption Sensing Radius = 1
 	// Biological Cell is able to sense one neighbour
 	int sensingRadius;
 	
 	
 	
 	//Properties of ECM Site
 	
 	// Fiber Density of ECM Site - (0,10) , number of fiber per cell area
 	int fiberDensity;
 	
 	// Cross Linking of ECM Site - (0,1) , amount of crossing in fibers
 	float crossLinking;
 	
 	public:		
 		
 	// Constructor - assign default values to Biological Cell and ECM Site 	 	
 	CellularAutomata(); 	

 	//int type, int age, float stiffness, float divisionRate, int size, float contractility, float invasiveness, float degradationPotential, float sensingRadius , int fiberDensity, float crossLinking
 	CellularAutomata( int , int, float , float , int , float , float , float , float , int , float );
 	 	
 	// Constructor - assign user defined values to Biological Cell 	
 	//int type, int age, float stiffness, float divisionRate, int size, float contractility, float invasiveness
 	CellularAutomata( int , int, float , float , int , float , float , float , float );
 	
 	// Constructor - assign user defined values to ECM Site
 	// int type, float degradationPotential, float sensingRadius
 	CellularAutomata( int , int , float );
	 	
 	//getters and setters	

	static int getRows();
	   	
	static void setRows(int);

	static int getColumns();
	   	
	static void setColumns(int);

	int getIdentity();
	
	void setIdentity(int );
	 
	int getType();
	
	void setType(int );
	
	// type testers
	
	// returns TRUE if Computational cell is Biological Cell
	// returns FALSE if Computational cell is not Biological Cell
	bool isBiologicalCell();
	 
	// returns TRUE if Computational cell is ECM Site
	// returns FALSE if Computational cell is not ECM Site
 	bool isECMSite();

	// returns TRUE if Computational cell is Cancer Stem Cell
	bool isCancerStemCell();
	 
	// returns TRUE if Computational cell is Transient Amplifying Cell
	bool isTransientAmplifyingCell();

	// returns TRUE if Computational cell is Cancer Stem Cell
	bool isTerminallyDifferentiatedCell();

		
	//getters and setters	
	
	int getAge();
	
	void setAge( int );
	
	float getStiffness();
	
	void setStiffness( float );
	 
	float getDivisionRate( );
	 
	void setDivisionRate( float  );
	
	int getSize();
	
	void setSize( int  );
	
	float getContractility();
	
	void setContractility( float  );
	 
	void setInvasiveness( float  );
	
	float getInvasiveness();
	
	void setDegradationPotential( float );
	
	float getDegradationPotential();
	
	int getSensingRadius();
	 
	void setSensingRadius( int  );
	 
	int getFiberDensity();
	
	void setFiberDensity( int  );
	 
	float getCrossLinking();
	
	void setCrossLinking( float );

	//CellularAutomata CA[][12] , int type, int age, float stiffness, float divisionRate, int size, float contractility, float invasiveness, float degradationPotential, float sensingRadius , int fiberDensity, float crossLinking 
	void setProperties(CellularAutomata[][12], int , int, float , float , int , float , float , float , float, int , float );
	
	// set user defined values to Biological Cell 	
 	
 	//int type, int age, float stiffness, float divisionRate, int size, float contractility, float invasiveness, float degradationPotential, float sensingRadius
 	void setBiologicalCellProperties( int , int, float , float , int , float , float , float , float );
 	
 	// set user user defined values to ECM Site
 	//int type, int fiberDensity, float crossLinking 
 	void setECMSiteProperties( int , int , float );
	
	// Generic function to set properties of Computational Cell	
	void update(CellularAutomata[][12] );		
	
	// function to set properties of Computational Cell	- now as BiologicalCell
	void resetBiologicalCellProperties();
	
	// function to set properties of Computational Cell	- now as ECM Site
	void resetECMSiteProperties();			
	
	// Update Division Rate of Biological Cell at (i,j)th loaction
	// CellularAutomata CA[][12], int i, int j  
	void updateDivisionRate(CellularAutomata[][12],int,int);		
	
	// Update Stiffness of Biological Cell at (i,j)th loaction 
	// CellularAutomata CA[][12], int i, int j  
	void updateStiffness( CellularAutomata[][12], int , int );
	
	// Update Degradation Potential of Biological Cell at (i,j)th loaction
	// CellularAutomata CA[][12], int i, int j  
	void updateDegradationPotential( CellularAutomata[][12], int , int );
	
	// Update Fiber Density of ECM Site at (i,j)th loaction
	// CellularAutomata CA[][12], int i, int j  
	void updateFiberDensity( CellularAutomata[][12], int , int );
	 
	// return sum of number Of ECM Site In Neighbourhood of (i,j) th Cell 
	// CellularAutomata CA[][12], int i, int j 
	int numberOfESInNeighbourhood( CellularAutomata[][12], int , int );
	
	// return sum of number Of Biological Cell In Neighbourhood of (i,j) th Cell
	// CellularAutomata CA[][12], int i, int j
	int numberOfBiologicalCellInNeighbourhood( CellularAutomata[][12], int , int );
	
	// return sum of Cross Linking Of ECM Sites In Neighbourhood of (i,j) th Cell
	// CellularAutomata CA[][12], int i, int j
	float summationOfCrossLinkingInNeighbourhood( CellularAutomata[][12], int , int );
	
	// return sum of Fiber Density Of ECM Sites In Neighbourhood of (i,j) th Cell
	// CellularAutomata CA[][12], int i, int j
	int summationOfFiberDensityOfESInNeighbourhood( CellularAutomata[][12], int , int );
	
	// return sum of Degradation Potential of Biological Cells In Neighbourhood of (i,j) th Cell
	// CellularAutomata CA[][12], int i, int j
	float summationOfDegradationPotentialInNeighbourhood( CellularAutomata[][12], int , int );
	
	// Write identities and Iteration List into separate files for each Property
	// CellularAutomata CA[][12], int itr
	void writeConstantsIdentityAndIterationsIntoFile(CellularAutomata[][12], int);
	
	// write results of Cellular Automata  into files for cell property 
	// CellularAutomata CA[][12], int itr
	void writeResultsToFile(CellularAutomata[][12], int, int, int);	 
	
	// Increment age of All Biological Cells by a unit
	// CellularAutomata CA[][12]
	void incrementAge(CellularAutomata[][12]);
		
	// Update state of Transient Amplifying Cells to Terminally Differentiated Cells, condition to cell age and BETA
	// CellularAutomata CA[][12], int i, int j
	void updateStateOfTransientAmplifyingCell( CellularAutomata[][12], int, int );
	
	// Select in Random one Free cell in Neighbourhood of (i,j)th TAC, and set it to TAC and age to 0
	// CellularAutomata CA[][12], int i, int j
	void selectInRamdomOutOfFreeNeighbourhoodToSetToTAC( CellularAutomata[][12], int, int );
	
	// Update state of Terminally Differentiated Cell to ECM Site, condition to cell age and GAMMA
	void updateStateOfTerminallyDifferentiatedCell( );
	 
	// Update state / Division of Cancer Stem Cell to Transient Amplifying Cell or Cancer Stem Cell
	// condition to ALPHA and availability of free neighbour 
	// CellularAutomata CA[][12], int i, int j
	void updateStateOfCancerStemCell( CellularAutomata[][12], int , int );
	
	//Select in Random one Free cell in Neighbourhood of (i,j)th TAC, and set it to TAC and age to 0
	void selectInRamdomOutOfFreeNeighbourhoodToUpdateToTACOrCSC( CellularAutomata[][12], int , int );
	
 };
 
	// Constructor initialising all values to zero
	CellularAutomata::CellularAutomata()
 	 {
 	 	// identity = id++;
 	 	// why not used - presence of padding of row and column , above , below and left , right respectively
 	 	// Cell starts at index 14 if above initialisation used
		  
		type = ECMSite;
 	 	
 	 	age = 0;
		stiffness = 0.5;
		divisionRate = 0.5;
		size = 1;
		contractility = 0.5;
		invasiveness = 0.5;
		degradationPotential = 0.5;
		
		sensingRadius = 1;
		
		fiberDensity = 5;
		crossLinking = 0.5;
		
/*
		type = ECMSite;
 	 	
 	 	age = 0;
		stiffness = 0;
		divisionRate = 0;
		size = 0;
		contractility = 0;
		invasiveness = 0;
		invasiveness = 0;
		degradationPotential = 0;
		
		sensingRadius = 0;
		
		fiberDensity = 0;
		crossLinking = 0;
*/		
 	 } 
	
	// Parameterised constructor
	// parameters - 
	// type, age, stiffness, divisionRate, size, contractility, invasiveness, degradationPotential, sensingRadius, fiberDensity, crossLinking 
	CellularAutomata::CellularAutomata( int type, int age, float stiffness, float divisionRate, int size, float contractility, float invasiveness, float degradationPotential, float sensingRadius , int fiberDensity, float crossLinking)
 	 { 	 	 	 	
		this->type = type;
 	 	
 	 	this->age = age;
		this->stiffness = stiffness;
		this->divisionRate = divisionRate;
		this->size = size;
		this->contractility = contractility;
		this->invasiveness = invasiveness;
		this->degradationPotential = degradationPotential;
		
		this->sensingRadius = sensingRadius;
				
		this->fiberDensity = fiberDensity;
		this->crossLinking = crossLinking;
 	 }   	 

	// Parameterisied Constructor setting only Biological Cell properties
	// parameters - 
	// type, age, stiffness, divisionRate, size, contractility, invasiveness, degradationPotential, sensingRadius
	CellularAutomata::CellularAutomata( int type, int age, float stiffness, float divisionRate, int size, float contractility, float invasiveness, float degradationPotential, float sensingRadius)
 	 { 	
		this->type = type;
 	 	
 	 	this->age  = age;
		this->stiffness = stiffness;
		this->divisionRate = divisionRate;
		this->size = size;
		this->contractility = contractility;
		this->invasiveness = invasiveness;
		this->degradationPotential = degradationPotential;
		
		this->sensingRadius = sensingRadius; 	 
	 }  
 	
 	// Parameterisied Constructor setting only ECM site properties
 	// parameters - 
	// type, fiberDensity, crossLinking 
	CellularAutomata::CellularAutomata( int type, int fiberDensity, float crossLinking)
 	 {
 	 	
		this->type = type; 	 	
				
		this->fiberDensity = fiberDensity;
		this->crossLinking = crossLinking;
 	 }	  
 
 //Getters and Setters
 
	int CellularAutomata::getRows()
 	 {
	  return rows;
 	 }
	   	
	void CellularAutomata::setRows(int r)
	 {
	 	rows = r;
	 }
	 
	int CellularAutomata::getColumns()
 	 { 	 	
 	 	return columns;
 	 }
	   	
	void CellularAutomata::setColumns(int c)
	 {
	 	columns = c;
	 }	 
	 
	int CellularAutomata::getIdentity() 
	 {
	 	return(identity);
	 }
	
	void CellularAutomata::setIdentity(int i) 
	 {
	 	identity = i;
	 }
	 
	int CellularAutomata::getType() 
	 {
	 	return(type);
	 }
	
	void CellularAutomata::setType(int t) 
	 {
	 	type = t;
	 }
		
	bool CellularAutomata::isBiologicalCell()
	 {
	 	return( getType() == CSC || getType() == TAC || getType() == TDC );
	 }
	 	
 	bool CellularAutomata::isECMSite()
	 {
	 	return( getType() == ECMSite );
	 }

	bool isCancerStemCell()
	 {
	 	return( getType() == CSC );
	 }
	 
	bool isTransientAmplifyingCell()
	 {
	 	return( getType() == TAC );	   
	 }

	bool isTerminallyDifferentiatedCell()
	 {
	 	return( getType() == TDC );	   
	 }

	int CellularAutomata::getAge()
	 {
	 	return(age);
	 }
	
	void CellularAutomata::setAge( int a)
	 {
	 	age = a;
	 }
	
	float CellularAutomata::getStiffness()
	 {
	 	return stiffness;
	 }
	
	void CellularAutomata::setStiffness( float s)
	 {
	 	stiffness = s;
	 }
	 
	float CellularAutomata::getDivisionRate( )
	 {
	 	return divisionRate;
	 }
	 
	void CellularAutomata::setDivisionRate( float d )
	 {
	 	divisionRate = d;
	 }
	
	int CellularAutomata::getSize()
	 {
	 	return size;
	 }
	
	void CellularAutomata::setSize( int s ) 
	 {
	 	size = s;
	 }
	
	float CellularAutomata::getContractility() 
	 {
	 	return contractility;
	 }
	
	void CellularAutomata::setContractility( float c )
	 {
	 	contractility = c;
	 }
	 
	void CellularAutomata::setInvasiveness( float i ) 
	 {
	 	invasiveness = i;	 	
	 }
	
	float CellularAutomata::getInvasiveness() 
	 {
	 	return invasiveness;
	 }
	
	void CellularAutomata::setDegradationPotential( float d)
	 {
	 	degradationPotential = d;
	 }
	
	float CellularAutomata::getDegradationPotential()
	 {
	 	return degradationPotential;
	 }
	 
	int CellularAutomata::getSensingRadius()
	 {
	 	return sensingRadius;
	 }
	 
	void CellularAutomata::setSensingRadius( int s )
	 {
	 	sensingRadius = s;
	 }
	 
	int CellularAutomata::getFiberDensity()
	 {
	 	return fiberDensity;
	 }
	
	void CellularAutomata::setFiberDensity( int f )
	 {
	 	fiberDensity = f;
	 }
	 
	float CellularAutomata::getCrossLinking()
	 {
	 	return crossLinking;
	 }
	
	void CellularAutomata::setCrossLinking( float c )
	 {
	 	crossLinking = c;
	 }

// This is required so the compiler has a place for the static variable
 int CellularAutomata::rows=0;
 int CellularAutomata::columns=0; 
 int CellularAutomata::id=1; 

	void CellularAutomata::update( CellularAutomata CA[][12] )
	 {
	 	int i;
	 	int j;
	 	
	 	int x;
	 	int y;	 
	 		 	
	 	// neighbours straight forward for inner cells than the boundary cell	 	
	 	// for boundary cell - neighbours be toroid using modulus to find neighbours if cell in first row, column or last row, column
	 	
	 	// Assuming the padding case of cellular automata
	 	
	 	// initial check cell m = -1 or -2 . .  depends on sensing radius
	 	// assumption of sensing radius = 1
	 	
	 	//cout<<"\n In Update Function - ";	 		 	
	 	
		//Separate loop for increamenting age
	 	
	 	for( i=1; i<= this -> getRows(); i++ )
	 	 {
	 	 	for ( j=1; j<= this -> getColumns(); j++ )
	 	 	 {
			   if( CA[i][j].isBiologicalCell() )
			    {
			      CA[i][j].incrementAge();
			    }
	 	 	 }
	 	 }

	 	for( i=1; i<= ROWS * COLUMNS ; i++ )
	 	 { 		 	 		 	 	
	 	 	
			x = rand() % 10 + 1;
	 	 	y = rand() % 10 + 1; 	
	 	 	

			if ( CA[x][y].isECMSite() )		// If it is ECM Site
			 {
			   CA[x][y].updateFiberDensity(CA,x,y);
			 }
			else					// then it is Biological Cell
			 {
			   CA[x][y].updateDivisionRate(CA,x,y);
			   CA[x][y].updateStiffness(CA,x,y);
			   CA[x][y].updateDegradationPotential(CA,x,y);
			 }

			
			if ( CA[x][y].isBiologicalCell() )			// If it is a Biological Cell
			 {
			   if ( CA[x][y].isTransientAmplifyingCell() )		// If it is a Transient Amplifying Cell
			    {
				CA[x][y].updateStateOfTransientAmplifyingCell(CA,x,y);			   
			    }
			   else if( CA[x][y].isTerminallyDifferentiatedCell() )	// Else If it is a Terminally Differentiated Cell
			    {
				CA[x][y].updateStateOfTerminallyDifferentiatedCell();
			    }
			   else 						// then it is a Cancer Stem Cell
			    {
				CA[x][y].updateStateOfCancerStemCell(CA,x,y);
			    }
			 }					
			this -> writeResultsToFile(CA,itr, x, y);
	 	 }
	 	
	 }

	//CellularAutomata CA[][12] , int type, int age, float stiffness, float divisionRate, int size, float contractility, float invasiveness, float degradationPotential, float sensingRadius , int fiberDensity, float crossLinking 
	void CellularAutomata::setProperties( CellularAutomata CA[][12] , int type, int age, float stiffness, float divisionRate, int size, float contractility, float invasiveness, float degradationPotential, float sensingRadius , int fiberDensity, float crossLinking )
	 {
	 	int i;
	 	int j;
	 	
	 	for( i=1; i<= ROWS; i++ )
	 	 {
	 	 	for ( j=1; j<= COLUMNS; j++ )
	 	 	 {
	 	 	 	// user / pre  defined values , and parameter list
	 	 	 	
	 	 	 	if( type == ESMSite )
	 	 	 	 {
	 	 	 	 	// parameter list
	 	 	 	 	// type, fiberDensity, crossLinking
	 	 	 	 	CA[i][j].setECMSiteProperties(type, fiberDensity, crossLinking);	 	 	 	 	
	 	 	 	 }
	 	 	 	else	// It is Biological Cell
	 	 	 	 {
	 	 	 	 	// parameter list
	 	 	 	 	// int type, int age, float stiffness, float divisionRate, int size, float contractility, float invasiveness, float degradationPotential, float sensingRadius
	 	 	 	 	CA[i][j].setBiologicalCellProperties(type, age, stiffness, divisionRate, size,	contractility, invasiveness, degradationPotential, sensingRadius);
	 	 	 	 }
	 	 	 }
	 	 }
	 
	 }	 	

 	// int type, int age, float stiffness, float divisionRate, int size, float contractility, float invasiveness, float degradationPotential, float sensingRadius
	void CellularAutomata::setBiologicalCellProperties( int type, int age, float stiffness, float divisionRate, int size, float contractility, float invasiveness, float degradationPotential, float sensingRadius )
 	 {
 	 	this->type = type;
 	 	
 	 	this->age = age;
		this->stiffness = stiffness;
		this->divisionRate = divisionRate;
		this->size = size;
		this->contractility = contractility;
		this->invasiveness = invasiveness;
		this->degradationPotential = degradationPotential;
		
		this->sensingRadius = sensingRadius;
				
 	 }
 	 	
 	// int type, int fiberDensity, float crossLinking 
	void CellularAutomata::setECMSiteProperties( int type, int fiberDensity, float crossLinking )
 	 {
 	 	this->type = type;
 	 					
		this->fiberDensity = fiberDensity;
		this->crossLinking = crossLinking;
 	 }
	
	// set default values to Biological Cell
	void CellularAutomata::resetBiologicalCellProperties()
	 {
	 	type = CSC;
 	 	
 	 	age = 0;
		stiffness = 0;
		divisionRate = 0;
		size = 0;
		contractility = 0;
		invasiveness = 0;
		degradationPotential = 0;
		
		sensingRadius = 0;
		
		// also - reseting all values of ECM Site properties
		fiberDensity = 0;
		crossLinking = 0;
	 }
	
	// set default values to ECM Site
	void CellularAutomata::resetECMSiteProperties()
	 {
	 	type = ECMSite;
 	 			
		fiberDensity = 0;
		crossLinking = 0;
		
		// also - reseting all values of Biological Cell properties
 	 	age = 0;
		stiffness = 0;
		divisionRate = 0;
		size = 0;
		contractility = 0;
		invasiveness = 0;
		degradationPotential = 0;
		
		sensingRadius = 0;

	 }
	 
	// Update Division Rate of Biological Cell at (i,j)th loaction 
	void CellularAutomata::updateDivisionRate( CellularAutomata CA[][12], int i, int j ) 
	 {	 		 	
	 	int totalNumberOfESInNeighbourhood;
	 	
		int m;
	 	int n;
	 	
	 	// Only if its a Biological Cell , update Degradation Potential
	 	if( this->isBiologicalCell() )
 	 	 { 	 	 	
			totalNumberOfESInNeighbourhood = numberOfESInNeighbourhood( CA, i, j);

		 	this->setDivisionRate( (float) tes / ( (float) (totalNumberOfESInNeighbourhood + 1) ) ); 	 	 	
 	 	 }	 	
	 }
	 	
	// Update Stiffness of Biological Cell at (i,j)th loaction 
	void CellularAutomata::updateStiffness( CellularAutomata CA[][12], int i, int j )
	 {
	 	int totalNumberOfESInNeighbourhood;
	 	float sumOfCrossLinking;
	 	float averageCrossLinking;
	 	
		int m;
	 	int n;
	 	
	 	// Only if its a Biological Cell , update Degradation Potential
	 	if( this->isBiologicalCell() )
 	 	 {
 	 	 	
			totalNumberOfESInNeighbourhood = numberOfESInNeighbourhood( CA, i, j);
			
			// test if there are no ES in neighbourhood
			// If none then will the stiffness change or remain same
			
			if( totalNumberOfESInNeighbourhood )
			 {
			 	sumOfCrossLinking = summationOfCrossLinkingInNeighbourhood( CA, i, j );
				averageCrossLinking = sumOfCrossLinking / ( (float) totalNumberOfESInNeighbourhood );				
				
				this->setStiffness( averageCrossLinking );			 	
			 } 	 	 	
 	 	 }	 	
	 }

	// Update Degradation Potential of Biological Cell at (i,j)th loaction
	void CellularAutomata::updateDegradationPotential( CellularAutomata CA[][12], int i, int j )
	 {	 	
	 	float sumOfFiberDensity;
	 	float newDegradationPotential;
	 	
		int m;
	 	int n;
	 	
	 	// Only if its a Biological Cell , update Degradation Potential
	 	if( this->isBiologicalCell() )
 	 	 { 	 	 				
			sumOfFiberDensity = (float) summationOfFiberDensityOfESInNeighbourhood( CA, i, j );
			
			newDegradationPotential = ( (float) sumOfFiberDensity / ( (float) (sumOfFiberDensity + 2)  ) );

		 	this->setDegradationPotential( newDegradationPotential );
 	 	 }
	 }
	 
	// Update Fiber Density of ECM Site at (i,j)th loaction	
	void CellularAutomata::updateFiberDensity( CellularAutomata CA[][12], int i, int j )
	 {
	 	int totalNumberoFBiologicalCellInNeighbourhood;
	 	float sumOfDegradationPotential;
	 	float averageDegradationPotential;
	 	
		int m;
	 	int n;
	 	
	 	if( this->isECMSite() )
 	 	 {
			totalNumberoFBiologicalCellInNeighbourhood = numberOfBiologicalCellInNeighbourhood( CA, i, j);
			
			// Only if total number of Biological cell in Neighbourhood is Not Zero , update Fiber Density of present cell
			if( tbc )
			 {
				sumOfDegradationPotential = summationOfDegradationPotentialInNeighbourhood( CA, i, j );
				
				averageDegradationPotential = sumOfDegradationPotential / totalNumberoFBiologicalCellInNeighbourhood;
				
				// If Fiber Density already zero - we need not calculate new Fiber Density				
		
			 	this->setFiberDensity( this->getFiberDensity() - ( this->getFiberDensity() * averageDegradationPotential ) );			 	
			 }			 	 	 	
 	 	 }	 	
	 }
	
	// return sum of number Of ECM Site In Neighbourhood of (i,j) th Cell 
	int CellularAutomata::numberOfESInNeighbourhood( CellularAutomata CA[][12], int i, int j )
	 {
	 	int totalNumberOfESInNeighbourhood = 0;
	 	int m;
	 	int n;
	 	
	 	// For 8 Adjacent cells
	 	for( m=-1; m<2; m++ ) 
	 	 {
	 	 	for( n=-1; n<2; n++ )
	 	 	 {	
			   	// If its a ECM Site inclrease count
	 	 	 	if( !( m==0 && n==0 ) && CA[i+m][j+n].isECMSite() )
	 	 	 	 {
	 	 	 	 	totalNumberOfESInNeighbourhood ++;
	 	 	 	 }
	 	 	 }
	 	 }

		return totalNumberOfESInNeighbourhood;
	 }					
	
	// return sum of number Of Biological Cell In Neighbourhood of (i,j) th Cell
	int CellularAutomata::numberOfBiologicalCellInNeighbourhood( CellularAutomata CA[][12], int i , int j )
	 {
	 	int totalNumberoFBiologicalCellInNeighbourhood = 0;
	 	int m;
	 	int n;
	 	
	 	// For 8 Adjacent cells
	 	for( m=-1; m<2; m++ ) 
	 	 {
	 	 	for( n=-1; n<2; n++ )
	 	 	 {				 	 	 					 	 	 	
	 	 	 	// If its a Biological Cell Increase the count
				if( !( m==0 && n==0 ) && CA[i+m][j+n].isBiologicalCell() )
	 	 	 	 {
	 	 	 	 	totalNumberoFBiologicalCellInNeighbourhood ++;
	 	 	 	 }
	 	 	 }
	 	 }	 	 	 	 
	 	 
	 	 return totalNumberoFBiologicalCellInNeighbourhood;
	 }

	// return sum of Cross Linking Of ECM Sites In Neighbourhood of (i,j) th Cell
	float CellularAutomata::summationOfCrossLinkingInNeighbourhood( CellularAutomata CA[][12], int i , int j )
	 {
	 	float sumOfCrossLinking = 0;
	 	int m;
	 	int n;
	 	
	 	// For 8 Adjacent cells
	 	for( m=-1; m<2; m++ ) 
	 	 {
	 	 	for( n=-1; n<2; n++ )
	 	 	 {				 	 	 					 	 	 	
	 	 	 	// If its a ECM Site, get cross linking and sum it
				if( !( m==0 && n==0 ) && CA[i+m][j+n].isECMSite() )
	 	 	 	 {
					sumOfCrossLinking = sumOfCrossLinking + CA[i+m][j+n].getCrossLinking();
	 	 	 	 }
	 	 	 }
	 	 }	 	 	 	 
	 	 return sumOfCrossLinking;	 	
	 }
	
	// return sum of Fiber Density Of ECM Sites In Neighbourhood of (i,j) th Cell
	int CellularAutomata::summationOfFiberDensityOfESInNeighbourhood( CellularAutomata CA [][12], int i , int j )
	 {
	 	float sumOfFiberDensityOfES = 0;
	 	int m;
	 	int n;
	 	
	 	// For 8 Adjacent cells
	 	for( m=-1; m<2; m++ ) 
	 	 {
	 	 	for( n=-1; n<2; n++ )
	 	 	 {				 	 	 					 	 	 	
	 	 	 	// If its a ECM Site, get fiber density and sum it
				if( !( m==0 && n==0 ) && CA[i+m][j+n].isECMSite() )
	 	 	 	 {							 	 	 	 	
					sumOfFiberDensityOfES = sumOfFiberDensityOfES + CA[i+m][j+n].getFiberDensity();
	 	 	 	 }
	 	 	 }
	 	 }
	 	 
	 	 return sumOfFiberDensityOfES;
	 }
	
	// return sum of Degradation Potential of Biological Cells In Neighbourhood of (i,j) th Cell
	float CellularAutomata::summationOfDegradationPotentialInNeighbourhood( CellularAutomata CA[][12], int i, int j)
	 {
	 	float sumOfDegradationPotential = 0;
	 	int m;
	 	int n;
	 	
	 	// For 8 Adjacent cells
	 	for( m=-1; m<2; m++ ) 
	 	 {
	 	 	for( n=-1; n<2; n++ )
	 	 	 {	
			   	// If its a Biological Cell, get Degradation Potential and sum it
	 	 	 	if( !( m==0 && n==0 ) && CA[i+m][j+n].isBiologicalCell() )
	 	 	 	 {							 	 	 	 	
	 	 	 	 	sumOfDegradationPotential = sumOfDegradationPotential + CA[i+m][j+n].getDegradationPotential();
	 	 	 	 }
	 	 	 }
	 	 }	 	 
	 	 
	 	 return sumOfDegradationPotential;
	 }
	
	// Write identities and Iteration List into separate files for each Property
	void CellularAutomata::writeConstantsIdentityAndIterationsIntoFile(CellularAutomata CA[][12], int itr) 
	 {
	 	int i;
	 	int j;
	 	int identity;
	 	
	 	// Declare Output stream class to operate on files
	 	ofstream divisionRateFileStream;	
	 	ofstream stiffnessFileStream;
	 	ofstream degradationPotentialFileStream;
	 	ofstream fiberDensityFileStream;
	 	ofstream crossLinkingFileStream;
	 	ofstream ageFileStream;
	 	ofstream typeFileStream;
	 	
		// Open file for each property
		divisionRateFileStream.open ("DivisionRate.txt");
		stiffnessFileStream.open ("Stiffness.txt");
		degradationPotentialFileStream.open ("DegradationPotential.txt");
		fiberDensityFileStream.open ("FiberDensity.txt");
		crossLinkingFileStream.open ("CrossLinking.txt");
		ageFileStream.open ("Age.txt");
		typeFileStream.open ("Type.txt");

		typeFileStream <<"ECMSite "<<ECMSite<<"\nCSC "<<CSC<<"\nTAC "<<TAC<<"\nTDC "<<TDC;
		typeFileStream<<"\nALPHA "<<ALPHA<<"\nBETA "<<BETA<<"\nGAMMA "<<GAMMA<<endl;		
		
		// Write Identity of cells as a matrix which corresponding to cell location
		for( i=1; i<= ROWS; i++ )
	 	 {
	 	 	for ( j=1; j<= COLUMNS; j++ )
	 	 	 {
	 	 	 	identity = CA[i][j].getIdentity();
	 	 	 	
				divisionRateFileStream << identity <<" ";
	 	 	 	stiffnessFileStream << identity <<" ";
	 	 	 	degradationPotentialFileStream << identity <<" ";
	 	 	 	fiberDensityFileStream << identity <<" ";
				crossLinkingFileStream<< identity <<" ";
				ageFileStream<< identity <<" ";
				typeFileStream<< identity <<" ";
	 	 	 }
			
			divisionRateFileStream << endl;
			stiffnessFileStream << endl;
			degradationPotentialFileStream << endl;
			fiberDensityFileStream << endl;
			crossLinkingFileStream << endl;
			ageFileStream << endl;
			typeFileStream << endl;
	 	 }	 	 
	 	
		divisionRateFileStream << endl;
		stiffnessFileStream << endl;
		degradationPotentialFileStream << endl;
		fiberDensityFileStream << endl;
		crossLinkingFileStream << endl;
		ageFileStream << endl;
		typeFileStream << endl;
		
		// written time iterations into file
	 	for( i = 1; i<=itr; i++ ) 
	 	 {
	 	 	divisionRateFileStream << i <<" ";
	 	 	stiffnessFileStream << i <<" ";
	 	 	degradationPotentialFileStream << i <<" ";
	 	 	fiberDensityFileStream << i <<" ";
	 	 	crossLinkingFileStream << i <<" ";
			ageFileStream << i <<" ";
			typeFileStream << i <<" ";
	 	 }
	 	 
		divisionRateFileStream << endl;
		stiffnessFileStream << endl;
		degradationPotentialFileStream << endl;
		fiberDensityFileStream << endl;
		crossLinkingFileStream << endl;
		ageFileStream << endl;
		typeFileStream << endl;
	 	
	 	// Close file
		divisionRateFileStream.close();		
		stiffnessFileStream.close();		
		degradationPotentialFileStream.close();		
		fiberDensityFileStream.close();
		crossLinkingFileStream.close();
		ageFileStream.close();
		typeFileStream.close();
	 }
	 
	// write results of Cellular Automata  into files for cell property 	
	void CellularAutomata::writeResultsToFile(CellularAutomata CA[][12], int itr, int x, int y)
	 {
	 	int i;
	 	int j;
	 	
	 	// Declare Output stream class to operate on files
	 	ofstream divisionRateFileStream;	
	 	ofstream stiffnessFileStream;
	 	ofstream degradationPotentialFileStream;
	 	ofstream fiberDensityFileStream;
		ofstream crossLinkingFileStream;
	 	ofstream ageFileStream;
	 	ofstream typeFileStream;
	 	
		// Open file for each property 	
		divisionRateFileStream.open ("DivisionRate.txt", ios::app);		
		stiffnessFileStream.open ("Stiffness.txt", ios::app);		
		degradationPotentialFileStream.open ("DegradationPotential.txt", ios::app);		
		fiberDensityFileStream.open ("FiberDensity.txt", ios::app);
		crossLinkingFileStream.open ("CrossLinking.txt", ios::app);
		ageFileStream.open ("Age.txt", ios::app);
		typeFileStream.open ("Type.txt", ios::app);
				
		divisionRateFileStream << endl;
		stiffnessFileStream << endl;
		degradationPotentialFileStream << endl;
		fiberDensityFileStream << endl; 
		crossLinkingFileStream << endl;
		ageFileStream << endl;
		typeFileStream << endl;
		
		
		divisionRateFileStream << " ( " <<x <<" , " << y <<" )\n";
		stiffnessFileStream <<  " ( " <<x <<" , " << y <<" )\n";
		degradationPotentialFileStream <<  " ( " <<x <<" , " << y <<" )\n";
		fiberDensityFileStream <<  " ( " <<x <<" , " << y <<" )\n";
		crossLinkingFileStream <<  " ( " <<x <<" , " << y <<" )\n";
		ageFileStream <<  " ( " <<x <<" , " << y <<" )\n";
		typeFileStream <<  " ( " <<x <<" , " << y <<" )\n";
									
		// Get Division Rate , Stiffness , Degradation Potential , Fiber Density , Cross Linking , Age and Type
		// for each cell and write it into respective files
		for( i=1; i<= ROWS; i++ )
	 	 {
	 	 	for ( j=1; j<= COLUMNS; j++ )
	 	 	 {
	 	 	 	divisionRateFileStream << CA[i][j].getDivisionRate()<<" ";
	 	 	 	stiffnessFileStream << CA[i][j].getStiffness()<<" ";
	 	 	 	degradationPotentialFileStream << CA[i][j].getDegradationPotential()<<" ";
	 	 	 	fiberDensityFileStream << CA[i][j].getFiberDensity()<<" ";
				crossLinkingFileStream << CA[i][j].getCrossLinking() <<" ";
				ageFileStream << CA[i][j].getAge() <<" ";
				typeFileStream << CA[i][j].getType() <<" ";
	 	 	 }
	 	 	
			divisionRateFileStream << endl;
			stiffnessFileStream << endl;
			degradationPotentialFileStream << endl;
			fiberDensityFileStream << endl; 
			crossLinkingFileStream << endl;
			ageFileStream << endl;
			typeFileStream << endl;			
	 	 }	 	 
	 	
	 	// Close file
		divisionRateFileStream.close();		
		stiffnessFileStream.close();		
		degradationPotentialFileStream.close();		
		fiberDensityFileStream.close();
		crossLinkingFileStream.close();
		ageFileStream.close();
		typeFileStream.close();		
	 }

	// Increment age of All Biological Cells by a unit
	void CellularAutomata::incrementAge()
	 {
 	   this -> setAge( CA[i][j].getAge() + 1 );	 	
	 }
	 
	 // Update state / Division of Transient Amplifying Cell to Terminally Differentiated Cells or Transient Amplifying Cell
	 // condition to cell age , BETA and availability of free neighbour
	 void CellularAutomata::updateStateOfTransientAmplifyingCell( CellularAutomata CA [][12], int i , int j )
	  {
	  	int totalNumberOfESInNeighbourhood;
	  	
	  	if( this->getType() == TAC )		// Is (i,j)th cell a Transient Amplifying Cell
	  	 {
	  	 	if( this->getAge() >= BETA )	// If Biological Cell type is TAC and Age is greater than or equal to BETA
	  	 	 {
	  	 	 	this->setType(TDC);		// Set the Biological Cell type to Terminally Differentiated Cell
	  	 	 }
	  	 	else
			 {
			 	// If Biological Cell type is TAC and Age is less than BETA
			 	
			 	// Check for free cells in neighbourhood - check if any ECM Site in Neighbourhood
			 	
			 	totalNumberOfESInNeighbourhood = this -> numberOfESInNeighbourhood( CA, i, j );			 				 	
			 	
			 	if( totalNumberOfESInNeighbourhood )	// if free space exists
			 	 {
			 	 	// Set Biological Set type to TAC and age to 0
			 	 	
			 	 	this -> selectInRamdomOutOfFreeNeighbourhoodToSetToTAC( CA , i, j );
			 	 }
			 	
			 } 
	  	 }
	  }	  	  
	 
	  //Select in Random one Free cell in Neighbourhood of (i,j)th TAC, and set it to TAC and age to 0
	  void CellularAutomata::selectInRamdomOutOfFreeNeighbourhoodToSetToTAC( CellularAutomata CA [][12], int i , int j )
	   {
	  	int m;
	   	int n;
	   	
	   	int freeCellNotFound = 1;
		int tries = TRIES;
	   	
	   	while( freeCellNotFound && tries != 0 )
	   	 {
	   	 	m = rand() % 3 - 1;
			n = rand() % 3 - 1;
	   	 	
			if( !( m==0 && n==0 ) && CA[i+m][j+n].isECMSite() )
	 	 	 {							 	 	 	 	
				CA[i+m][j+n].setType(TAC);
			   	CA[i+m][j+n].setAge(0);
			   	
			   	freeCellNotFound = 0;
	 	 	 }
			tries--;
	   	 }
	   }
	   
	 // Update state of Terminally Differentiated Cell to ECM Site, condition to cell age and GAMMA
	 void CellularAutomata::updateStateOfTerminallyDifferentiatedCell( )
	  {
	  	if( this -> getType() == TDC )			//If Biological Cell type is Terminally Differentiated Cell 
	  	 {
	  	 	if( this -> getAge() >= GAMMA )		// And if Age is greater than GAMMA
	  	 	 {
	  	 	 	//Set cell type as ECM Site, fiber density as 0 , cross linking as 0
	  	 	 	
	  	 		this -> resetECMSiteProperties();
	  	 	 }
	  	 }
	  }
	  	  
	 // Update state / Division of Cancer Stem Cell to Transient Amplifying Cell or Cancer Stem Cell
	 // condition to ALPHA and availability of free neighbour
	 void CellularAutomata::updateStateOfCancerStemCell( CellularAutomata CA[][12], int i, int j )
	  {	  	
	  	int totalNumberOfESInNeighbourhood;	  	

	  	if( this -> getType() ==  CSC)
	  	 {  	 	 	
  	 	 	totalNumberOfESInNeighbourhood = this -> numberOfESInNeighbourhood( CA, i, j );
		 	
		 	if( totalNumberOfES )	// if free space exists
		 	 {
		 	 	// Set Biological Set type to TAC and age to 0
		 	 	
		 	 	this -> selectInRamdomOutOfFreeNeighbourhoodToUpdateToTACOrCSC( CA , i, j );
		 	 }
	  	 }
	  }

	  //Select in Random one Free cell in Neighbourhood of (i,j)th TAC, and set it to TAC and age to 0
	  void CellularAutomata::selectInRamdomOutOfFreeNeighbourhoodToUpdateToTACOrCSC( CellularAutomata CA [][12], int i , int j )
	   {
	  	int m;
	   	int n;
	   	double alp;
	   	
	   	int freeCellNotFound = 1;
		int tries = TRIES;
	   	
	   	alp =  rand()/ (double) RAND_MAX ;		// Generate random number between (0,1)

		// limit number of tries
	   	
	   	while( freeCellNotFound && tries !=0 )
	   	 {
	   	 	m = rand() % 3 - 1;
			n = rand() % 3 - 1;
	   	 	
			if( !( m==0 && n==0 ) && CA[i+m][j+n].isECMSite() )
	 	 	 {
	 	 	 	if( alp <= ALPHA)
	 	 	 	 {
	 	 	 	 	CA[i+m][j+n].setType(TAC);
					CA[i+m][j+n].setAge(0);
	 	 	 	 }
	 	 	 	else
				 {
				 	CA[i+m][j+n].setType(CSC);
					CA[i+m][j+n].setAge(0);
				 }   
			   	
			   	freeCellNotFound = 0;
	 	 	 }

			tries--;	 	 	 
	   	 }
	   }	  	 
