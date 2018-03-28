/* INFO */

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
//using namespace std; for my poor boi michi

class pfd { // class to implement Perfect Fib Distrution
public:
	std::vector<int> oTrois = { 1, 0, 0 };  // order 3 and order 4,
	std::vector<int> oQuatro = { 1, 0, 0, 0 }; // will be vectors to make it easier, actually we can just use arrays...
	int ee[15] = { 76, 97, 45, 108, 105, 45, 108, 117, 45, 108, 101, 45, 108, 111, 46 };
	int fSize;
	int dRecords = 0;
	int tmpSize = 1;
	//DONE
	void pfd_order_three() {
		std::cout << " PFD of order 3\n";
		std::cout << "   |f|   |f1| |f2| |f3|\n";
		std::cout << " --------------------------\n";
		if (fSize == 1) // base case 
			display_order_line(3);
		else
			while (tmpSize <= fSize) { // less than or equal to for lets say size inputed is actually in table
				display_order_line(3);
				get_next_order(3); // next version is already here so if file size is not in table, next lvl is already calculated even though we stop the loop
				if (tmpSize == fSize || tmpSize > fSize) { //first boolean -  check to make sure we dont go to next order if exists in table
					display_order_line(3);				   // second boolean - check to make sure we dont exit loop before printing pdf order
					break;								  // dont like the break, maybe other way???
				}
			}
		if (dRecords > 0) // te-he
			std::cout << "Use <" << oTrois[0] << "-" << oTrois[1] << "-" << oTrois[2] << "> distribution with " << dRecords << " dummy records\n";
		else
			std::cout << "Use <" << oTrois[0] << "-" << oTrois[1] << "-" << oTrois[2] << "> distribution\n";

		dRecords = 0; // reset for order 4
		tmpSize = 1;
	}
	//DONE
	void pfd_order_four() {
		std::cout << " PFD of order 4\n";
		std::cout << "   |f|   |f1| |f2| |f3| |f4|\n";
		std::cout << " --------------------------\n";
		if (fSize == 1) // base case 
			display_order_line(3);
		else
			while (tmpSize <= fSize) { // less than or equal to for lets say size inputed is actually in table
				display_order_line(4);
				get_next_order(4); // next version is already here so if file size is not in table, next lvl is already calculated even though we stop the loop
				if (tmpSize == fSize || tmpSize > fSize) { //first boolean -  check to make sure we dont go to next order if exists in table
					display_order_line(4);				   // second boolean - check to make sure we dont exit loop before printing pdf order
					break;								  // dont like the break, maybe other way???
				}
			}
		if (dRecords > 0) // te-he
			std::cout << "Use <" << oQuatro[0] << "-" << oQuatro[1] << "-" << oQuatro[2] << "-" << oQuatro[3] << "> distribution with " << dRecords << " dummy records\n";
		else
			std::cout << "Use <" << oQuatro[0] << "-" << oQuatro[1] << "-" << oQuatro[2] << "-" << oQuatro[3] << "> distribution\n";

		dRecords = 0; // reset 
		tmpSize = 1;
	}
	//DONE
	void get_next_order(int order_flag) {
		if (order_flag == 3) {
			int f1 = oTrois[0]; // a
			int f2 = oTrois[1]; // b
			int f3 = oTrois[2]; // c

			oTrois[0] = f1 + f2; // a + b
			oTrois[1] = f1 + f3; // a+c
			oTrois[2] = f1; // a
			tmpSize = oTrois[0] + oTrois[1] + oTrois[2];
			dRecords = tmpSize - fSize;
		}
		else if (order_flag == 4) { // UPDATE
			int f1 = oQuatro[0]; // a
			int f2 = oQuatro[1]; // b
			int f3 = oQuatro[2]; // c
			int f4 = oQuatro[3]; //
			oQuatro[0] = f1 + f2; // a + b
			oQuatro[1] = f1 + f3; // a + c
			oQuatro[2] = f1 + f4; // a + d
			oQuatro[3] = f1;
			tmpSize = oQuatro[0] + oQuatro[1] + oQuatro[2] + oQuatro[3];
			dRecords = tmpSize - fSize;
		}
	}
	//DONE
	void display_order_line(int option_flag) {
		if (option_flag == 3) { // if order 3 or order 4, allows for use for displaying when we get the order and how we distribute
			std::cout << std::setw(5) << tmpSize
					  << std::setw(5) << oTrois[0]
					  << std::setw(5) << oTrois[1]
					  << std::setw(5) << oTrois[2] << std::endl;
		}
		else if( option_flag == 4) {
			std::cout << std::setw(5) << tmpSize
					  << std::setw(5) << oQuatro[0]
					  << std::setw(5) << oQuatro[1]
					  << std::setw(5) << oQuatro[2]
					  << std::setw(5) << oQuatro[3] << std::endl;
		}
	}
	//WIP
	void sort_distro() {} // will be used to get each step of sorting for order 3 and 4, will be helper function in pfd_order_*
	// DONE
	void set_file_size(int amt) {
		fSize = amt;
	}

	void eee() { // run it ....
		for (int i = 0; i < 15; i++) {
			std::cout << char(ee[i]);
		}
	}

};


int main() {
	pfd perf;
	int brows; // there is meaning here
			   // in loop
	std::cout << "Enter the file size: "; // prompt user and assume valid input
	std::cin >> brows;
	// display orders
	perf.set_file_size(brows);
	perf.pfd_order_three();
	perf.pfd_order_four();
	return 0;
}
