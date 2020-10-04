
#include <mutex>
#include <thread>
#include <iostream>
using namespace std;

	 mutex m;
     bool notif = false;
    

int main()
{
    m.lock();
        thread paire([&]() {
        for (int i = 0; i <= 1000; i++) {
            	if(i%2!=0){
             
		cout << "Nombre impaire "<< i << '\n';
		}

  m.unlock();
            notif = true;

        }

    });

    m.lock();
    thread impaire([&]() {
        for (int i = 0; i < 1000; i++) {
          if(i%2==0){
			
			cout << "Nombre paire "<< i << '\n';
		}
		  m.unlock();
            notif = true;


        }
    });
    paire.join();
   impaire.join();

}


