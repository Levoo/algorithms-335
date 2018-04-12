#include <iostream>
#include <ctime>
#include <random>
using namespace std; //mario?

int main(){
    int end = 9;
    //int a[10] = {25, 10, 22, 8, 17, 10, 13, 11, 6, 28};  // test
    int a[10];
    std::cout << "The origanal array is:\n\t";
    std::srand(time(0)); // seed so we get random number every time we call
    for (int i = 0; i < 10; i++){ // gen and store the rand numbers 
        a[i] = std::rand() % 30 + 1;
        std::cout << a[i] << " "; 
    }
    std::cout << "\nThis is the array after a rearangment\n\t";
    for (int i = 0; i < 5; i++){ // get odds 
        if (a[i] % 2 == 1 && a[i] != 0){
            std::cout << a[i] << " ";
        }else if (a[end] % 2 == 1 && a[end] != 0){
            std::cout << a[end] << " ";
        }
        end--;
    }
    end = 9; // reset the end
    for (int i = 0; i < 5; i++){ // get evens 
        if (a[i] % 2 == 0 && a[i] != 0){
            std::cout << a[i] << " ";
        }else if (a[end] % 2 == 0 && a[end] != 0){
            std::cout << a[end] << " ";
        }
        end--;
    }
    std::cout << "\n";
    return 0;
}