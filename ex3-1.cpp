#include <iostream>
#include <vector>

	using namespace std;
		int somme = 0 ; 
		vector<int> T={11,32,73,84,54};

class Table{	

	public :
		
		void sequentielle(){
			
			for(int i = 0; i < T.size(); i++)
			{
				somme= somme + T[i];				
			}
			
		};	
	
};

	int main(){
		Table tab1;
		tab1.sequentielle();
		std::cout<<"La somme du tableau est  : "<<somme<<endl;
	//return 0;
	}
