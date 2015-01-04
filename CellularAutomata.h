#include<windows.h>
// problem - rows and columns as static
// update possible / not with them as private

// Check linking options in Dev C++ 
// In function definition - undefined reference to static variable , linker error -o

using namespace std;

class CellularAutomata
 {
 	//class variables  	
 	
/* 	public: 	 		
	//Variables to set dimensions of Cellular Automata
 	// rows for number of rows
 	// columns for number of columns
 	// dimensions - rows * columns number of computational cells
 	// static to create only one copy of varaibles rows and columns
	static int rows;
 	static int columns; 	 	
*/ 	
 	private:
	//Variable to identify if Computational Cell is a Biological Cell or ECM Site
 	// type set to 1 - considered as Biological Cell
 	// type set to 0 - considered as ECM site
 	int type;
 	
 	
 	//Properties of Biological Cell
 	
 	// Stiffness of Biological Cell - (0,1) 
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
 	
 	CellularAutomata( int , float , float , int , float , float , float , float , int , float );
 	
 	// Constructor - assign user defined values to Biological Cell 	
 	CellularAutomata( int , float , float , int , float , float , float , float );
 	
 	// Constructor - assign user defined values to ECM Site
 	CellularAutomata( int , int , float );
	 	
 	//getters and setters	

/*
	static int getRows();
	   	
	static void setRows(int);

	static int getColumns();
	   	
	static void setColumns(int);
*/	
	 
	int getType();
	
	void setType(int );
	
	// type testers
		
	// returns 1 if Computational cell is Biological Cell
	// returns 0 if Computational cell is not Biological Cell
	int isBiologicalCell();
	 
	// returns 1 if Computational cell is ECM Site
	// returns 0 if Computational cell is not ECM Site
 	int isECMSite();
	
	
	//getters and setters	
	
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
	 
	int getCrossLinking();
	
	void setCrossLinking( float  );
	
	// set user defined values to Biological Cell 	
 	
 	void setBiologicalCellProperties( int , float , float , int , float , float , float , float );
 	
 	// set user user defined values to ECM Site
 	void setECMSiteProperties( int , int , float );
	
	// Generic function to set properties of Computational Cell	
	void update(int, int, int[12][12] );
	
	// function to set properties of Computational Cell	- now as BiologicalCell
	void updateBiologicalCellProperties();
	
	// function to set properties of Computational Cell	- now as ECM Site
	void updateECMSiteProperties();
	
	void printCellularAutomata( int, int, int[12][12] , float[12][12] );
		 
 };
 
	CellularAutomata::CellularAutomata()
 	 {
 	 	type = 0;
 	 	
		stiffness = 0.5;
		divisionRate = 0.5;
		size = 1;
		contractility = 0.5;
		invasiveness = 0.5;
		degradationPotential = 0.5;
		
		sensingRadius = 1;
		
		fiberDensity = 5;
		crossLinking = 0.5;
 	 } 
 
	CellularAutomata::CellularAutomata( int t, float stiff, float dr, int size, float c, float i, float dp, float sr , int fd, float cl)
 	 {
 	 	type = t;
 	 	
		stiffness = stiff;
		divisionRate = dr;
		this->size = size;
		contractility = c;
		invasiveness = i;
		degradationPotential = dp;
		
		sensingRadius = sr;
				
		fiberDensity = fd;
		crossLinking = cl;
 	 }   	 

	CellularAutomata::CellularAutomata( int t, float stiff, float dr, int size, float c, float i, float dp, float sr = 1)
 	 {
 	 	type = 1;
 	 	
		stiffness = stiff;
		divisionRate = dr;
		this->size = size;
		contractility = c;
		invasiveness = i;
		degradationPotential = dp;
		
		sensingRadius = sr;
 	 }  
 	
	CellularAutomata::CellularAutomata( int t, int fd, float cl)
 	 {
 	 	type = 0;
 	 	
 	 	fiberDensity = fd;
		crossLinking = cl;
 	 }     	 	 

	 
	int CellularAutomata::getType() 
	 {
	 	return(type);
	 }
	
	void CellularAutomata::setType(int t) 
	 {
	 	type = t;
	 }
		
	int CellularAutomata::isBiologicalCell()
	 {
	 	return( getType() );
	 }
	 	
 	int CellularAutomata::isECMSite()
	 {
	 	return( ! getType() );
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
	 
	int CellularAutomata::getCrossLinking()
	 {
	 	return crossLinking;
	 }
	
	void CellularAutomata::setCrossLinking( float c )
	 {
	 	crossLinking = c;
	 } 	 

	void CellularAutomata::update( int i, int j, int currentState[12][12] )
	 {
	 	int tes = 0;
	 	
	 	int m;
	 	int n;
	 	
	 	// neighbours straight forward for inner cells than the boundary cell	 	
	 	// for boundary cell - neighbours be toroid using modulus to find neighbours if cell in first row, column or last row, column
	 	
	 	// Assuming the padding case of cellular automata
	 	
	 	// initial check cell m = -1 or -2 . .  depends on sensing radius
	 	// assumption of sensing radius = 1
	 	
	 	for( m=-1; m<2; m++ ) 
	 	 {
	 	 	for( n=-1; n<2; n++ )
	 	 	 {
	 	 	 	// this -> isECMSite() will point to same object 
	 	 	 	
	 	 	 	if( !( m==0 && n==0 ) && currentState[i][j] == 0 )
	 	 	 	 {
	 	 	 	 	tes ++;
	 	 	 	 }
	 	 	 }
	 	 }
	 	
	 	this -> setDivisionRate( (float) tes / ( (float) (tes + 1) ) );
	 	
	 }
	 	
 	void CellularAutomata::setBiologicalCellProperties( int t, float stiff, float dr, int size, float c, float i, float dp, float sr )
 	 {
 	 	type = t;
 	 	
		stiffness = stiff;
		divisionRate = dr;
		this->size = size;
		contractility = c;
		invasiveness = i;
		degradationPotential = dp;
		
		sensingRadius = sr;
 	 }
 	 	
 	void CellularAutomata::setECMSiteProperties( int t, int fd, float cl )
 	 {
 	 	type = t;
 	 					
		fiberDensity = fd;
		crossLinking = cl;
 	 }
	
	void CellularAutomata::updateBiologicalCellProperties()
	 {
	 	type = 1;
 	 	
		stiffness = 0.5;
		divisionRate = 0.5;
		size = 1;
		contractility = 0.5;
		invasiveness = 0.5;
		degradationPotential = 0.5;
		
		sensingRadius = 1;

	 }
		
	void CellularAutomata::updateECMSiteProperties()
	 {
	 	type = 0;
 	 			
		fiberDensity = 5;
		crossLinking = 0.5;
	 }
	 
	void CellularAutomata::printCellularAutomata( int rows, int columns, int currentState[12][12]  , float divRate[12][12] )
	 {
	 	char colorString[9]="color 1A";
	 	for( int i=1; i<=rows; i++ )	 	
	 	 {
	 	 	for( int j=1; j<=columns; j++ )
	 	 	 {	 	 	 	
	 	 	 	if( currentState[i][j] == 1 )	 	 	 	    
	 	 	 	 {
	 	 	 	 	//colorString[8] = int (color[i][j] );
	 	 	 	 	
	 	 	 	 	//system(colorString); // the colours are from 1 to 15. 		
	 	 	 	 	cout<<" bc"<<divRate[i][j];
	 	 	 	 }
	 	 	 	else
				 {
				 	colorString[8] = 'A';
					cout<<"   es";
				 } 
	 	 	 }
	 	 	cout<<endl; 
	 	 }
	 } 

/*	
	int CellularAutomata::getRows()
 	 { 	 	
 	 	return rows;
 	 }
	   	
	void CellularAutomata::setRows(int r)
	 {
	 	rows = 5;
	 }
	 
	int CellularAutomata::getColumns()
 	 { 	 	
 	 	return columns;
 	 }
	   	
	void CellularAutomata::setColumns(int c)
	 {
	 	columns = c;
	 }
*/	 
