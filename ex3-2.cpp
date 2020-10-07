#include <iostream>
#include <vector>
#include <thread>

	
 	using namespace std;
  //declaration des variables globales
 	thread t1,t2,t3;
 	int res = 0 ; 
 	vector<int> T={1,2,7,4,5,2,3,4,2,10,5,15};

				
   	void local(int a,int b){
			
			int t=0;
			while(a <= b)
			{
				t = t + T[a];
				a++;
			}
			res = res + t;

		}
		//Function qui divise le tableau sur deux sous-tableau chaque sous-table liée avec un threads
	void calcule ()
		{
			// le premier thread prend un sous tableau à partir de l'indice 0 jusqu'a 3
			t1=thread(local,0,3);
			// le deuxieme thread prend le deuxieme sous tableau à partir de l'indice 4 jusqu'a 7 
			t2=thread(local,4,7);
				// le toixieme thread prend le toixieme sous tableau à partir de l'indice 8 jusqu'a 11 
			t3=thread(local,8,11);
			t1.join();
			t2.join();
			t3.join();
		
		}
		


int main(){

	calcule ();
	std::cout <<"Somme du Table QST 2 : "<<res<<endl;
	return 0;
		}


