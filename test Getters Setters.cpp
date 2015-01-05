	 	
 	cout<<"\n Before Explicit Initialization ";
	CA[6][6].printCellularAutomata();
	
	type = 10;
	stiffness = 10.5;
	divisionRate = 10.5;
	size = 11;
	contractility = 10.5;
	invasiveness = 10.5;
	degradationPotential = 10.5;
	sensingRadius = 11;
	fiberDensity = 15;
	crossLinking = 10.5;

    CA[6][6].setBiologicalCellProperties(type, stiffness, divisionRate, size,	contractility, invasiveness, degradationPotential, sensingRadius);    
    
 	cout<<"\n After Explicit Initialization ";
	CA[6][6].printCellularAutomata();
	
	CA[6][6].setECMSiteProperties( type, fiberDensity, crossLinking );
	
	CA[6][6].printCellularAutomata();
	
	cout<<"\n After Re Initialization ";		
	
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
 	
 	CA[6][6].setBiologicalCellProperties(type, stiffness, divisionRate, size,	contractility, invasiveness, degradationPotential, sensingRadius);
 	
 	CA[6][6].printCellularAutomata();
 	
 	CA[6][6].setECMSiteProperties( type, fiberDensity, crossLinking );
 	
 	CA[6][6].printCellularAutomata();

