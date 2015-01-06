#include<windows.h>

// class of Cellular Automata - containing properties of Biological Cell and ECM Sites

// problem - rows and columns as static
// update possible / not with them as private

// Check linking options in Dev C++ 
// In function definition - undefined reference to static variable , linker error -o

// generate state function

using namespace std;

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

	static int getRows();
	   	
	static void setRows(int);

	static int getColumns();
	   	
	static void setColumns(int);

	 
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

	void setProperties(CellularAutomata[][12], int , float , float , int , float , float , float , float, int , float );
	
	// set user defined values to Biological Cell 	
 	
 	void setBiologicalCellProperties( int , float , float , int , float , float , float , float );
 	
 	// set user user defined values to ECM Site
 	void setECMSiteProperties( int , int , float );
	
	// Generic function to set properties of Computational Cell	
	void update(CellularAutomata[][12] );
	
	void updateDivisionRate(CellularAutomata[][12],int,int);
	
	// function to set properties of Computational Cell	- now as BiologicalCell
	void updateBiologicalCellProperties();
	
	// function to set properties of Computational Cell	- now as ECM Site
	void updateECMSiteProperties();
	
	void printCellularAutomata( CellularAutomata[][12] );
	
	void printCellularAutomata( );
		 
 };

// This is required so the compiler has a place for the static variable

 int CellularAutomata::rows=0;
 int CellularAutomata::columns=0; 
 
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

// type, stiffness, divisionRate, size,	contractility, invasiveness, degradationPotential, sensingRadius
	 	 	 	 	// type, fiberDensity, crossLinking 
	CellularAutomata::CellularAutomata( int type, float stiffness, float divisionRate, int size, float contractility, float invasiveness, float degradationPotential, float sensingRadius , int fiberDensity, float crossLinking)
 	 {
 	 	this->type = type;
 	 	
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

	CellularAutomata::CellularAutomata( int type, float stiffness, float divisionRate, int size, float contractility, float invasiveness, float degradationPotential, float sensingRadius)
 	 {
 	 	this->type = type;
 	 	
		this->stiffness = stiffness;
		this->divisionRate = divisionRate;
		this->size = size;
		this->contractility = contractility;
		this->invasiveness = invasiveness;
		this->degradationPotential = degradationPotential;
		
		this->sensingRadius = sensingRadius; 	 
	 }  
 	
	CellularAutomata::CellularAutomata( int type, int fiberDensity, float crossLinking)
 	 {
 	 	this->type = type; 	 	
				
		this->fiberDensity = fiberDensity;
		this->crossLinking = crossLinking;
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

	void CellularAutomata::update( CellularAutomata CA[][12] )
	 {
	 	int i;
	 	int j;
	 	
	 	// neighbours straight forward for inner cells than the boundary cell	 	
	 	// for boundary cell - neighbours be toroid using modulus to find neighbours if cell in first row, column or last row, column
	 	
	 	// Assuming the padding case of cellular automata
	 	
	 	// initial check cell m = -1 or -2 . .  depends on sensing radius
	 	// assumption of sensing radius = 1
	 	
	 	//cout<<"\n In Update Function - ";
	 	
	 	for( i=1; i<= CA[0][0].getRows() ; i++ )
	 	 {
	 	 	for( j=1; j<=CA[0][0].getColumns(); j++ )
	 	 	 {
	 	 	 	
	 	 	 	CA[i][j].updateDivisionRate(CA,i,j);
				   	 	 	 		 	 	 	
		 	}
	 	 }	 				 		 		 	
	 	
	 }

	void CellularAutomata::setProperties( CellularAutomata CA[][12] , int type, float stiffness, float divisionRate, int size, float contractility, float invasiveness, float degradationPotential, float sensingRadius , int fiberDensity, float crossLinking )
	 {
	 	int i;
	 	int j;
	 	
	 	for( i=1; i<= CA[0][0].getRows(); i++ )
	 	 {
	 	 	for ( j=1; j<= CA[0][0].getColumns(); j++ )
	 	 	 {
	 	 	 	// user / pre  defined values , and parameter list
	 	 	 	
	 	 	 	if( CA[i][j].isBiologicalCell() )
	 	 	 	 {
	 	 	 	 	// parameter list
	 	 	 	 	// type, stiffness, divisionRate, size,	contractility, invasiveness, degradationPotential, sensingRadius
	 	 	 	 	type = 1;
	 	 	 	 	CA[i][j].setBiologicalCellProperties(type, stiffness, divisionRate, size,	contractility, invasiveness, degradationPotential, sensingRadius);	 	 	 	 	
	 	 	 	 }
	 	 	 	else
	 	 	 	 {
	 	 	 	 	// parameter list
	 	 	 	 	// type, fiberDensity, crossLinking
	 	 	 	 	type = 0;
	 	 	 	 	CA[i][j].setECMSiteProperties(type, fiberDensity, crossLinking);	 	 	 	 	
	 	 	 	 }
	 	 	 }
	 	 }
	 
	 }	 	
 	void CellularAutomata::setBiologicalCellProperties( int type, float stiffness, float divisionRate, int size, float contractility, float invasiveness, float degradationPotential, float sensingRadius )
 	 {
 	 	this->type = type;
 	 	
		this->stiffness = stiffness;
		this->divisionRate = divisionRate;
		this->size = size;
		this->contractility = contractility;
		this->invasiveness = invasiveness;
		this->degradationPotential = degradationPotential;
		
		this->sensingRadius = sensingRadius;
 	 }
 	 	
 	void CellularAutomata::setECMSiteProperties( int type, int fiberDensity, float crossLinking )
 	 {
 	 	this->type = type;
 	 					
		this->fiberDensity = fiberDensity;
		this->crossLinking = crossLinking;
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
	 
	void CellularAutomata::printCellularAutomata( CellularAutomata CA[][12] )
	 {	
	 	int i;
	 	int j;
	 	
	 	cout<<endl;
	 	cout.precision(2);
	 	
	 	for( i=1; i<=CA[0][0].getRows(); i++ )	 	
	 	 {
	 	 	for( j=1; j<=CA[0][0].getColumns(); j++ )
	 	 	 {	 	 	 	
	 	 	 	if( CA[i][j].isBiologicalCell() )	 	 	 	
	 	 	 	 {
	 	 	 	 	cout<<"bc"<<CA[i][j].getDivisionRate()<<"  ";
	 	 	 	 }
	 	 	 	else
				 {				 	
					cout<<"es      ";
				 } 
	 	 	 }
	 	 	cout<<endl; 
	 	 }
	 } 

	void CellularAutomata::printCellularAutomata( )
	 {
	 	cout<<"\n The content of Comptational Cell is : \n";
	 	
	 	cout<<"\n Type - "<<this->getType();	 	 	
	 	
	 	cout<<"\n Stifness - "<<this->getStiffness();
	 	
	 	cout<<"\n Divison Rate - " << this->getDivisionRate();
	 	
	 	cout<<"\n Size - " << this->getSize();
	
	 	cout<<"\n Contractility - "<< this->getContractility();
	 	
	 	cout<<"\n Invasiveness - "<<this->getInvasiveness();
	 	
	 	cout<<"\n Degradation Potential - "<<this->getDegradationPotential();
	 	
	 	cout<<"\n Sensing Radius - "<<this->getSensingRadius();
	 	
	 	cout<<"\n Fiber Density - "<<this->getFiberDensity();
	 	
	 	cout<<"\n Cross Linking - "<<this->getCrossLinking();
	 }

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
	
	void CellularAutomata::updateDivisionRate( CellularAutomata CA[][12], int i, int j ) 
	 {
	 	int tes = 0;
	 	
	 	int m;
	 	int n;
	 	
	 	if( this->isBiologicalCell() )
	 	 	 	 {
	 	 	 	 	//cout<<"\n Biological cell -";
	 	 	 	 	
					tes = 0;
					
				 	for( m=-1; m<2; m++ ) 
				 	 {
				 	 	for( n=-1; n<2; n++ )
				 	 	 {				 	 	 					 	 	 	
				 	 	 	if( !( m==0 && n==0 ) && CA[i+m][j+n].isECMSite() )
				 	 	 	 {
				 	 	 	 	tes ++;
				 	 	 	 }
				 	 	 }
				 	 }

				 	this->setDivisionRate( (float) tes / ( (float) (tes + 1) ) );
	 	 	 	 	
	 	 	 	 }
	 	
	 }
