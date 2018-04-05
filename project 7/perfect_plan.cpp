/* INFO */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <iomanip>
//using namespace std; for my poor boi michi

#define ORDER_THREE_F 3
#define ORDER_FOUR_F 4

class pfd { // class to implement Perfect Fib Distrution, should it be a class??
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
			display_order_line(ORDER_THREE_F);
		else
			while (tmpSize <= fSize) { // less than or equal to for lets say size inputed is actually in table
				display_order_line(ORDER_THREE_F);
				get_next_order(ORDER_THREE_F); // next version is already here so if file size is not in table, next lvl is already calculated even though we stop the loop
				if (tmpSize == fSize || tmpSize > fSize) { //first boolean -  check to make sure we dont go to next order if exists in table
					display_order_line(ORDER_THREE_F);				   // second boolean - check to make sure we dont exit loop before printing pdf order
					break;								  // dont like the break, maybe other way???
				}
			}
		if (dRecords > 0) // te-he
			std::cout << "Use <" << oTrois[0] << "-" << oTrois[1] << "-" << oTrois[2] << "> distribution with " << dRecords << " dummy records\n";
		else
			std::cout << "Use <" << oTrois[0] << "-" << oTrois[1] << "-" << oTrois[2] << "> distribution\n";


		//-----------------------------
		std::cout << "   |f|   |f1| |f2| |f3|\n";
		std::cout << " --------------------------\n";
		int count = 0;
		std::cout << std::setw(5) << tmpSize
					  << std::setw(5) << "0"
					  << std::setw(5) << "0"
					  << std::setw(5) << "0" << std::endl;
		tmpSize = 0;
		while ((tmpSize+oTrois[0] + oTrois[1] + oTrois[2]) != 1) {
			display_order_line(ORDER_THREE_F);
			sort_distro(ORDER_THREE_F);
		}
			display_order_line(ORDER_THREE_F);
		dRecords = 0; // reset for order 4
		tmpSize = 1;
	}
	//DONE
	void pfd_order_four() {
		std::cout << " PFD of order 4\n";
		std::cout << "   |f|   |f1| |f2| |f3| |f4|\n";
		std::cout << " --------------------------\n";
		if (fSize == 1) // base case 
			display_order_line(ORDER_FOUR_F);
		else
			while (tmpSize <= fSize) { // less than or equal to for lets say size inputed is actually in table
				display_order_line(ORDER_FOUR_F);
				get_next_order(ORDER_FOUR_F); // next version is already here so if file size is not in table, next lvl is already calculated even though we stop the loop
				if (tmpSize == fSize || tmpSize > fSize) { //first boolean -  check to make sure we dont go to next order if exists in table
					display_order_line(ORDER_FOUR_F);				   // second boolean - check to make sure we dont exit loop before printing pdf order
					break;								  // dont like the break, maybe other way???
				}
			}
		if (dRecords > 0) // te-he
			std::cout << "Use <" << oQuatro[0] << "-" << oQuatro[1] << "-" << oQuatro[2] << "-" << oQuatro[3] << "> distribution with " << dRecords << " dummy records\n";
		else
			std::cout << "Use <" << oQuatro[0] << "-" << oQuatro[1] << "-" << oQuatro[2] << "-" << oQuatro[3] << "> distribution\n";

				//-----------------------------
		std::cout << "   |f|   |f1| |f2| |f3| |f4|\n";
		std::cout << " --------------------------\n";
		int count = 0;
		std::cout << std::setw(5) << tmpSize
					  << std::setw(5) << "0"
					  << std::setw(5) << "0"
					  << std::setw(5) << "0"
					  << std::setw(5) << "0" << std::endl;
		tmpSize = 0;
		while ((tmpSize+oQuatro[0] + oQuatro[1] + oQuatro[2]+ oQuatro[3]) != 1) {
			display_order_line(ORDER_FOUR_F);
			sort_distro(ORDER_FOUR_F);
		}
			display_order_line(ORDER_FOUR_F);
		dRecords = 0; // reset for order 4
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
	void absitbby(){
		tmpSize = abs(tmpSize);
		oTrois[0] = abs(oTrois[0]);
		oTrois[1] = abs(oTrois[1]);
		oTrois[2] = abs(oTrois[2]);
		oQuatro[0] = abs(oQuatro[0]);

		oQuatro[0] = abs(oQuatro[0]);
		oQuatro[1] = abs(oQuatro[1]);
		oQuatro[2] = abs(oQuatro[2]);
		oQuatro[3] = abs(oQuatro[3]);
	}
	//WIP
	void sort_distro(int order_flag) {
		// find min then use that to sub, if answer is -min cast to +
		if (order_flag == ORDER_THREE_F) {
			int min = min_val(ORDER_THREE_F);
			tmpSize -= min;
			oTrois[0] -= min;
			oTrois[1] -= min;
			oTrois[2] -= min;
			absitbby();
		}
		else if (order_flag == ORDER_FOUR_F) {
			int min = min_val(ORDER_FOUR_F);
			tmpSize -= min;
			oQuatro[0] -= min;
			oQuatro[1] -= min;
			oQuatro[2] -= min;
			oQuatro[3] -= min;
			absitbby();
		}
	} // will be used to get each step of sorting for order 3 and 4, will be helper function in pfd_order_*
	// DONE
	void set_file_size(int amt) {
		fSize = amt;
	}

	int min_val(int order_flag) {
		int min = tmpSize; // assume first element is mil
		if (order_flag == ORDER_THREE_F) {

			for (int i = 0; i < oTrois.size(); i++) {
				if ((oTrois[i] < min && oTrois[i] != 0) || min == 0)
					min = oTrois[i];
			}
			return min;
		}
		else if(order_flag == ORDER_FOUR_F){
			for (int i = 0; i < oQuatro.size(); i++) {
				if ((oQuatro[i] < min && oQuatro[i] != 0) || min == 0)
					min = oQuatro[i];
			}
			return min;
		}
		else
			return 0;
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
