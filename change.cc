#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

// selection sort function
void selectionSort(int arr[], int size) {
	int temp, pos;
	int length = size;
	for (int i = 0; i < size - 1; ++i) {
		pos = i;
		for (int j = i + 1; j < size ; ++j) {
			if (arr[j] < arr[pos])
				pos = j;
		}
		temp = arr[pos];
		arr[pos] = arr[i];
		arr[i] = temp;
	}
}

// main func
int main (int numArgs, char *arg[]) {
	// size of the array without the total amount
	int size = numArgs - 2;

	// program needs at least 2 command parameters.
	if (numArgs - 1 < 2) {
		cout << "Usage: change [denominations] [amount]" << endl;
		return 1;
	}
	
	// making the parameters into int arrays
	int intArgs[10];
	for (int i = 1; i < numArgs; ++i) {
		stringstream ss(arg[i]);
		int x;
		ss >> x;
		intArgs[i - 1] = x;
	}

	// getting the total amount of money
	int totalAmt = intArgs[numArgs - 2];

	// sorting the list of denominations	
	selectionSort(intArgs, size);	

	// possible?
	bool poss = false;
	int totalCpy = totalAmt;
	for (int i = size - 1; i >= 0; --i) {
		totalCpy = totalCpy %  intArgs[i];
		if (totalCpy == 0) {
			poss = true;
			break;
		}
	}
	
	//if possible
	if (poss) {
		for (int i = size - 1; i >= 0; --i) {
			int num = totalAmt / intArgs[i];
			totalAmt -= num * intArgs[i];
			if (num != 0) 
				cout << num << " x " << intArgs[i] << endl;
		}
	}
	//not possible
	else {
		cout << "Impossible" << endl;
	}
	return 0;
}


