#include <iostream>
#include <string>
#include <list>

void printList(std::string, std::list<int>);
void insertionSort(std::list<int>);

int main(){
    int temp;
    std::list<int> ll_int;
    std::list<int> sorted_ll_int;
    std::cout << "Enter some positive integer numbers with -1 at the end: "; // 89 45 68 90 29 34 17 -1
    while(std::cin >> temp){
        if(temp == -1) break;
        ll_int.push_back(temp);
    }

    printList("Original linked list: ", ll_int);

    return 0;
}

void insertionSort(std::list<int> ll){ // not correct fix
    for (auto it = ll.begin(); it != ll.end(); ++it){
        auto min = it;
        for(auto itt = ++it; itt != ll.end(); ++itt){
            if(*itt < *min) min = itt;
        }
        auto temp = min;

    }
}

void printList(std::string msg, std::list<int> ll){
    std::cout << "\n\t" <<msg;
    for (auto it = ll.begin(); it != ll.end(); ++it){
        std::cout << *it << " -> ";
    }
    std::cout << "NULL" << std::endl;
}


