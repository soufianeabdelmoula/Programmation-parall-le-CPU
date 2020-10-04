#include <iostream>
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
}


