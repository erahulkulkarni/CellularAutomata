#include<iostream>

using namespace std;

class CellularAutomata
 {
 	private:
	//class variables  	 	

	static int rows;
 	static int columns; 
 	
 	public:
 	static int getRows();
	   	
	static void setRows(int);

	static int getColumns();
	   	
	static void setColumns(int);
 	 	
 };
 
 int CellularAutomata::rows=0;
 int CellularAutomata::columns=0;
 
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
 
 int main()
  {
  	CellularAutomata CA[10];
  	
  	cout<<CA[0].getRows()<<CA[0].getColumns()<<endl;
  	
  	CA[0].setRows(100);
	CA[0].setColumns(100);
	
	cout<<CA[0].getRows()<<CA[0].getColumns();
  	
  	return(0);
  }
