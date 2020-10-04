/*#include <iostream>
#include <thread>

using namespace std;

void affiche() {
std::cout<<"Hello World from soufiane!"<< std::endl;}

int main() {
std::thread th1(affiche); // creation du thread th1
th1.join(); // main theard wait for th1 to finish
std::thread th2(affiche); // creation du thread th2
th2.join();
return 0;
}*/


#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <chrono>
using namespace std;

int main()
{

    mutex m;
    condition_variable cond_var;
    bool notified = false;
    
    
    
        thread paire([&]() {
        for (int i = 0; i <= 20; i++) {
         this_thread::sleep_for(chrono::seconds(1));
            unique_lock<std::mutex> lock(m);
            	if(i%2!=0){
             
		cout << "impaire "<< i << '\n';
			//std::cout << n << '\n';
		}


            notified = true;
            cond_var.notify_one();
           // std::this_thread::sleep_for(std::chrono::seconds(1));

        }

       // done = true;
        cond_var.notify_one();
    });


    thread impaire([&]() {
        for (int i = 0; i < 20; i++) {
        this_thread::sleep_for(chrono::seconds(1));
           unique_lock<std::mutex> lock(m);
          if(i%2==0){
			
			cout << "paire "<< i << '\n';
		}
            //std::cout << "paire " << i*2 << '\n';

            notified = true;
            cond_var.notify_one();
           // std::this_thread::sleep_for(std::chrono::seconds(2));

        }


        //cond_var.notify_one();
    });



    paire.join();
   impaire.join();

}

