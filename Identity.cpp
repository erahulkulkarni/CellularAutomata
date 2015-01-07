#include<iostream>

using namespace std;

class Identity
 {
 	private:
	 int id;
	 static int identity;
 	
 	public:
 	 Identity()
 	  {
 	  	id = identity++;
 	  }
 	 int getId()
 	  {
 	  	return(id);
 	  }
 	 void setId(int id)
 	  {
 	  	this->id = id;
 	  }
 };
 
int Identity::identity=1;
int main()
 {
 	Identity I[2][2];
 	
 	for( int i=0; i<2; i++ )
 	 {
 	 	for( int j=0; j<2; j++ )
 	 	 {
 	 	 	cout<<"\t"<<I[i][j].getId();
 	 	 }
 	 }
 	return(0);
 }
