#include <iostream>
#include <cmath>
using namespace std;


int main() {
	unsigned int x, y, BOOL;
	int iterator = 0;
	char arr[100], arr1[100], arr2[100];
	// Entering the A array;
	cout << "Enter the number of terms in first array: " << endl;
	cin >> x;
	for (int i = 0; i < x; i++) {
		cin >> arr[i];
		bool uniq = true;
		for (int k = 0; k < i; k++) {
			if (arr[i] == arr[k]) {
				uniq = false;
			}
		}
		if (uniq == false) {
			cout << "The elemnent should be unique!" << endl;
			exit(0);

		}
		
	}
	cout << "The U array: ";
	for (int j = 0; j < x; j++) {
		cout << "{"<< arr[j] <<"}" << " ";
	}
	//Entering the B array;
	cout << "\nNow, enter the number of terms in second array: " << endl;
	cin >> y;
	if (y <= x) {

		for (int i = 0; i < y; i++) {
			cin >> arr1[i];
			bool uniq = true;
			for (int k = 0; k < i; k++) {
				if (arr1[i] == arr1[k]) {
					uniq = false;
				}
			}
			if (uniq == false) {
				cout << "The elemnent should be unique!" << endl;
				exit(0);

			}
		}
		cout << "The A array: ";

		for (int j = 0; j < y; j++) {
			cout << "{" << arr1[j] << "}" << " ";
		}
		//Calculating A - B;
		for (int i = 0; i < x; i++) {
			bool isInclude = false;
			for (int j = 0; j < y; j++) {
				if (arr1[j] == arr[i]) {
					isInclude = true;
					break;
				}
			}
			if (!isInclude) {
				arr2[iterator] = arr[i];
				iterator++;
			}

		}

		cout << "\nU-A = ";
		for (int s = 0; s < iterator; s++) {

			cout << "{" << arr2[s] << "}" << " ";

		}
		//Calculating a boolean of U-A.
		BOOL = pow(2, iterator);
		cout << "\nBoolean of U-A = " << BOOL << endl;
		system("pause");
	}
	else {
		cout << "The number of elements in second array should be equal or less than in first array!" << endl;
	}
	return 0;
}