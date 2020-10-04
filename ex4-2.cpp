
#include <mutex>
#include <thread>
#include <iostream>
#include <chrono>
using namespace std;

int main()
{

    mutex m;

    bool notified = false;
        thread paire([&]() {
        for (int i = 0; i <= 1000; i++) {
         this_thread::sleep_for(chrono::seconds(1));
         m.lock();
 
            	if(i%2!=0){
             
		cout << "impaire "<< i << '\n';
		
		}

  m.unlock();
            notified = true;

        }
    });

    m.lock();
    thread impaire([&]() {
        for (int i = 0; i < 1000; i++) {
        this_thread::sleep_for(chrono::seconds(1));
         m.unlock();
       
          if(i%2==0){
			
			cout << "paire "<< i << '\n';
		}
		 
            notified = true;

        }

    });
    paire.join();
   impaire.join();

}


