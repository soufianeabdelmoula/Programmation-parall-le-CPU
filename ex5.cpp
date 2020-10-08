#include <iostream>      
#include <thread>         
#include <mutex>
#include <condition_variable>
#include <unistd.h>

//Reference https://fr.cppreference.com/w/cpp/thread/condition_variable

 	using namespace std;
 	bool done = false;
    bool notified = false;
 	mutex mtx;
	condition_variable cond_var;


	int eau=0;
	 void thread_1(){
			while(true)
			{
					eau++;
		 cout << " la  quantité  d’eau  du  barrage est : " << eau << '\n';
		sleep(1);
				if(eau>=4)
				{
					notified = true;
					//pour aréter jusqu'a 5 et affiche que c'est le 
				 cond_var.notify_one();
				}
			}
   done = true;
	}

	void thread_2(){
			while(true)
			{
				
				std::unique_lock<std::mutex> lock(mtx);
                cond_var.wait(lock);
				eau=0;
				cout << "lachement du vanne : "<< eau << " "<<endl;
						
			}
notified = false;
	}
int main() 
{
 	thread t1(thread_1);
  	thread t2(thread_2);
	t1.join();
	t2.join();
	
  return 0;
}
