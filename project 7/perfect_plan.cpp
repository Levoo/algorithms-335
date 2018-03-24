/* INFO */

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
//using namespace std; for my poor boi michi

class pfd { // class to implement Perfect Fib Distrution
	public:
		std::vector<int> oTrois = {1, 0, 0};  // order 3 and order 4,
		std::vector<int> oQuatro = {1, 0, 0, 0}; // will be vectors to make it easier, actually we can just use arrays...
		int ee[15] = { 76, 97, 45, 108, 105, 45, 108, 117, 45, 108, 101, 45, 108, 111, 46 };
		int fSize;
		int nextSize;
		int tmpSize = 1;
		bool inTable = false;
		//wip
		void pfd_order_three() {
			std::cout << " PFD of order 3\n";
			std::cout << "   |f|   |f1| |f2| |f3|\n";
			std::cout << " --------------------------\n";
			if (fSize == 1) // base case 
				display_order_3_line();
			else 
				while (tmpSize <= fSize) { // less than or equal to for lets say size inputed is actually in table
					display_order_3_line();
					get_next_order_three(); // next version is already here so if file size is not in table, next lvl is already calculated even though we stop the loop
					if (tmpSize == fSize || tmpSize > fSize) { //first boolean -  check to make sure we dont go to next order if exists in table
						display_order_3_line();				   // second boolean - check to make sure we dont exit loop before printing pdf order
						break;								  // dont like the break, maybe other way???
					}
				}
			

			std::cout << "DEBUG\n";
			display_order_3_line();
		}
		
		void get_next_order_three() {
			
			int f1 = oTrois[0]; // a
			int f2 = oTrois[1]; // b
			int f3 = oTrois[2]; // c
	
			oTrois[0] = f1 + f2; // a + b
			oTrois[1] = f1 + f3;
			oTrois[2] = f1; // can wemake this look more d@nk ???
			tmpSize = oTrois[0] + oTrois[1] + oTrois[2];
		}

		void display_order_3_line() {
			std::cout << std::setw(5) << tmpSize
				<< std::setw(5) << oTrois[0]
				<< std::setw(5) << oTrois[1]
				<< std::setw(5) << oTrois[2] << std::endl;
		}
		//wip
		void pfd_order_four() {

		}
		//wip
		void get_order_4_distro() { 

		}
		
		void set_file_size(int amt) {
			fSize = amt;
		}

		void eee() {
			for (int i = 0; i < 15; i++) {
				std::cout << char(ee[i]);
			}
		}

};


int main(){
	pfd perf;
	int brows; // there is meaning here
	// in loop
	std::cout << "Enter the file size: "; // prompt user and assume valid input
	std::cin >> brows;
	
	perf.set_file_size(brows);
	perf.pfd_order_three();
    return 0;
}

