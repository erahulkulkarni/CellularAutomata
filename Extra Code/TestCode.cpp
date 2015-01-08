	void printCellularAutomataDivisionRate( CellularAutomata[][12] );	
	
	void printCellularAutomataStiffness( CellularAutomata[][12] );
	
	void printCellularAutomataDegradationPotential( CellularAutomata[][12] );
	
	void printCellularAutomataFiberDensity(CellularAutomata[][12]);
	
	void printCellularAutomata( );
	 
	void CellularAutomata::printCellularAutomataDivisionRate( CellularAutomata CA[][12] )
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
					cout<<"es"<<"        ";
				 } 
	 	 	 }
	 	 	cout<<endl; 
	 	 }
	 } 

	void CellularAutomata::printCellularAutomataStiffness( CellularAutomata CA[][12] )
	 {	
	 	int i;
	 	int j;
	 	
	 	cout<<endl;
	 	cout.precision(4);
	 	
	 	for( i=1; i<=CA[0][0].getRows(); i++ )	 	
	 	 {
	 	 	for( j=1; j<=CA[0][0].getColumns(); j++ )
	 	 	 {	 	 	 	
	 	 	 	if( CA[i][j].isBiologicalCell() )	 	 	 	
	 	 	 	 {
	 	 	 	 	cout<<"bc"<<CA[i][j].getStiffness()<<"  ";
	 	 	 	 }
	 	 	 	else
				 {				 	
					cout<<"es"<<"      ";
				 } 
	 	 	 }
	 	 	cout<<endl; 
	 	 }
	 } 

	void CellularAutomata::printCellularAutomataDegradationPotential( CellularAutomata CA[][12] )
	 {	
	 	int i;
	 	int j;
	 	
	 	cout<<endl;
	 	cout.precision(4);
	 	
	 	for( i=1; i<=CA[0][0].getRows(); i++ )	 	
	 	 {
	 	 	for( j=1; j<=CA[0][0].getColumns(); j++ )
	 	 	 {	 	 	 	
	 	 	 	if( CA[i][j].isBiologicalCell() )	 	 	 	
	 	 	 	 {
	 	 	 	 	cout<<"bc"<<CA[i][j].getDegradationPotential()<<"  ";
	 	 	 	 }
	 	 	 	else
				 {				 	
					cout<<"es"<<"      ";
				 } 
	 	 	 }
	 	 	cout<<endl; 
	 	 }
	 } 

	void CellularAutomata::printCellularAutomataFiberDensity( CellularAutomata CA[][12] )
	 {	
	 	int i;
	 	int j;
	 	
	 	cout<<endl;
	 	cout.precision(4);
	 	
	 	for( i=1; i<=CA[0][0].getRows(); i++ )	 	
	 	 {
	 	 	for( j=1; j<=CA[0][0].getColumns(); j++ )
	 	 	 {	 	 	 	
	 	 	 	if( CA[i][j].isECMSite() )	 	 	 	
	 	 	 	 {
	 	 	 	 	cout<<"es"<<CA[i][j].getFiberDensity()<<"  ";
	 	 	 	 }
	 	 	 	else
				 {				 	
					cout<<"bc"<<"   ";
				 } 
	 	 	 }
	 	 	cout<<endl; 
	 	 }
	 } 


	void CellularAutomata::printCellularAutomata( )
	 {
	 	cout<<"\n The content of Comptational Cell is : \n";
	 	
	 	cout<<"\n Identity - "<<this->getIdentity();
	 	
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


	 	 	 	 	//cout<<"\n [i+m]"<<i+m<<"\t[j+n]"<<j+n;
	 	 	 	 	
					//cout<<"\n CA[i+m][j+n].isBiologicalCell() - "<<CA[i+m][j+n].isBiologicalCell();
	 	 	 	 	
	 	 	 	 	//cout<<"\n CA[i+m][j+n].getDegradationPotential() - "<<CA[i+m][j+n].getDegradationPotential();

	 	 //cout<<"\n Summation Of Degradation Potential of BC In Neighbourhood - "<< sumOfDegradationPotential;
	 	 

	 	 	 	 	//cout<<"\n [i+m]"<<i+m<<"\t[j+n]"<<j+n;
	 	 	 	 	
					//cout<<"\n CA[i+m][j+n].isECMSite() - "<<CA[i+m][j+n].isECMSite();
	 	 	 	 	
	 	 	 	 	//cout<<"\n CA[i+m][j+n].getFiberDensity() - "<<CA[i+m][j+n].getFiberDensity();
	 	 
	 	 //cout<<"\n Summation Of Fiber Density Of ES In Neighbourhood - " <<sumOfFiberDensityOfES;


	 	 	 	 	//cout<<"\n [i+m]"<<i+m<<"\t[j+n]"<<j+n;
	 	 	 	 	
					//cout<<"\n CA[i+m][j+n].isECMSite() - "<<CA[i+m][j+n].isECMSite();
	 	 	 	 	
	 	 	 	 	//cout<<"\n CA[i+m][j+n].getCrossLinking() - "<<CA[i+m][j+n].getCrossLinking();
	 	 	 	 	
	 	 //cout<<"\n Sum Of Cross Linking in Neighbourhood - " <<sumOfCrossLinking;
		  

	 	
		//cout<<"\n Number Of ES in Neighbourhood - " <<tes;
	 	

 	 	 	

			//cout<<"\n Number Of Biological Cell In Neighbourhood - "<<tbc; 	 	 	

 	 	 	

				//cout<<"\n Earlier Fiber Density "<<this->getFiberDensity();
				
				
			 	//cout<<"\n New Fiber Density "<<this->getFiberDensity();
			 	
			 	
 	 	 	//cout<<"\n Biological cell -";
			   
		 	//cout<<"\n New Degradation Potential - "<<newDegradationPotential<<" and set value - "<<this->getDegradationPotential();
			 


 	 	 	//cout<<"\n Biological cell -";
			   
				//cout<<"\n Average Cross Linking - " <<averageCrossLinking;
				
				
				 	 	 	//cout<<"\n Biological cell -";
