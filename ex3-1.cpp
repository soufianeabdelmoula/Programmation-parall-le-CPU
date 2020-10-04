#include <thread>
#include <mutex>
#include <iostream>
#include <vector>
using namespace std;
class Tableau{
		vector<int> T={1,2,3,4,5,6,7,8,9,7,8,9,6,32,132,5,4,79,6,3,17,3,5,3,7,3,7,3,7,3,83,53,45};
		mutex m;
		int somme=0;
		
		public:

		void first(){
			
			for(int i = 0; i < T.size(); i++)
			{
				somme+=T[i];				
			}
			
			cout<<"Premiere methode : "<<somme<<endl;
		};

		void calcul_par_var_local(int a,int b){
			
			int s=0;
			for(a;a<=b;a++)
			{
				s+=T[a];
			}
			somme+=s;

		}
		void second()
		{
			thread t1,t2,t3;
			t1=thread(&Tableau::calcul_par_var_local,this,0,10);
			t2=thread(&Tableau::calcul_par_var_local,this,11,21);
			t3=thread(&Tableau::calcul_par_var_local,this,22,32);
			t1.join();
			t2.join();
			t3.join();
			cout <<"Deuxieme methode : "<<somme<<endl;
		}
		void calcul_par_var_partage(int a,int b){
			
			
			m.lock();
			for(a;a<=b;a++)
			{
				somme+=T[a];
			}
			m.unlock();
			

		}
		void third()
		{
			thread t1,t2,t3;
			t1=thread(&Tableau::calcul_par_var_local,this,0,10);
			t2=thread(&Tableau::calcul_par_var_local,this,11,21);
			t3=thread(&Tableau::calcul_par_var_local,this,22,32);
			t1.join();
			t2.join();
			t3.join();
			cout <<"Troisieme methode : "<< somme<< endl;

		}


};
int main() {
	Tableau t1;
	Tableau t2;
	Tableau t3;
		
	t1.first();
	t2.second();
	t3.third();
	return 0;
}
