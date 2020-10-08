#include <thread>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Matrice
{
    public:
    vector <vector<int>> elemsMatrice;
    
    int n = 3;

  
    void newMatrice(){
        for (int i=0; i<n; i++) {
			vector<int> MatriceCol; 
			for (int j=0; j<n; j++) {
			 MatriceCol.push_back(0);
			}
			 elemsMatrice.push_back(MatriceCol);
		}
    }
    
    //Remplissage
    void Remplissage(){
        cout<<"value n \n";
		cin >> n;
		cout<<" \n";
		
		//remplissage
		for (int i = 0; i < n; i++) {
		  vector<int> MatriceCol;		
		  for (int j = 0; j < n; j++) {
		  	cout<< "entrer valeur dans element ["<< i <<"]["<< j <<"] = ";
		  	int m;
		  	cin  >> m;
		    MatriceCol.push_back(m);
		  }
			cout<<"\n";
		  elemsMatrice.push_back(MatriceCol);
		}
    }
    
    //Affichage
    void  Affichage(){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout <<  "[" << i << "]" << "[" << j << "] = "<<elemsMatrice[i][j] << " ";
            }
            cout <<endl;
        }
    }
    
    void produitMatricesSeq(Matrice *m1,Matrice *m2){
        
          for (int i=0;i<n;i++)
        	{
		        for (int j=0;j<n;j++)
		        {
		        	for (int k=0;k<n;k++)
			        {
			    	elemsMatrice[i][j]=m1->elemsMatrice[i][k]*m2->elemsMatrice[k][j]+elemsMatrice[i][j];
		        	}
		        }
	        }
        cout << "resultat de la methode sequentielle: " << endl;
        Affichage();
        cout << endl;

    }
    
    // produit element [i][j]
     void Pelementij(int i,int j,Matrice *m1,Matrice *m2)
    {
        for (int k=0;k<n;k++){
            elemsMatrice[i][j]=m1->elemsMatrice[i][k]*m2->elemsMatrice[k][j]+elemsMatrice[i][j];
        }
    }

//fonction avec version  par  valeur 
     void produitparValeur(Matrice *mt1,Matrice *mt2){
         thread t[16];
         int c=0;
            for (int i=0;i<n;i++){
		        for (int j=0;j<n;j++){
		        	t[c]= std::thread(&Matrice::Pelementij,this,i,j,mt1,mt2);
                    t[c].join();
                    c++;
		        }
	        }

        cout << "resultat de la version valeur " << endl;
        Affichage();
        cout << endl;

    }
    
    void block(int i,Matrice *mt1,Matrice *mt2)
    {
        for (int j=0;j<n;j++){
            for (int k=0;k<n;k++){
			    	
			    elemsMatrice[i][j]=mt1->elemsMatrice[i][k]*mt2->elemsMatrice[k][j]+elemsMatrice[i][j];
		        
                }
            }
    }
    //fonction avec version  par  block
    void Produitmatricesarblock(Matrice *mt1,Matrice *mt2)
    {
        thread t[4];
         int c=0;

		        for (int i=0;i<n;i++)
		        {
		        	t[c]= std::thread(&Matrice::block,this,i,mt1,mt2);
                    t[c].join();
                    c++;
		        }

         cout << "resultat de la version Block" << endl;
        Affichage();
        cout << endl;
    }


};

int main(){

    Matrice mat1; 
    mat1.Remplissage();
    
    
    Matrice mat2;
    mat2.Remplissage();
    
    Matrice mat3;
    mat3.newMatrice();
    
    Matrice mat4;
    mat4.newMatrice();
    
    Matrice mat5;
    mat5.newMatrice();
    
    
    mat3.produitMatricesSeq(&mat1,&mat2);
  

    mat4.produitparValeur(&mat1,&mat2);
   

    mat5.Produitmatricesarblock(&mat1,&mat2);

	return 0 ;
}

