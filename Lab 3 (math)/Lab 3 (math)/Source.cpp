#include <iostream>

using namespace std;


void arrayInput(int* arr, int n);
void arrayOutput(int* arr, int n);
void array2dOutput(int** arr, int n, int m);
void relation(int** arr, int n, int m);

int main() {
	int n, m;
	cout << "Enter the number of elements in first array: ";
	cin >> n;
	int* firstArray = new int[n]; 
	cout << "Enter the first array: " << endl;
	arrayInput(firstArray, n);
	cout << "The first array: " << endl;
	arrayOutput(firstArray, n);
	cout << "Enter the number of elements in second array: ";
	cin >> m;
	int* secondArray = new int[m];
	cout << "Enter the second array: " << endl;
	arrayInput(secondArray, m);
	cout << "The second array: " << endl;
	arrayOutput(secondArray, m);
	int** R = new int* [n];
	for (int i = 0; i < n; i++) {
		R[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (firstArray[i] < 3 * secondArray[j]) {
				R[i][j] = 1;
			}
			else {
				R[i][j] = 0;
			}
		}
	}
	cout << endl;
	cout << "The relation(a < 3b): " << endl;
	array2dOutput(R, n, m);
	relation(R, n, m);


	delete[]firstArray;
	delete[]secondArray;
	for (int i = 0; i < n; i++) {
		delete[]R[i];
	}
	delete[] R;
	system("pause");
	return 0;

}



void arrayInput(int* arr, int n) {
	for (int i = 0; i < n; i++) {
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
}

void arrayOutput(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void array2dOutput(int** arr, int n, int m) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

}
void relation(int** arr, int n, int m) {
	int s = 0, k = 0;
	bool equal = true;
	bool trans = false;
	bool antitrans = false;
	for (int i = 0; i < n; i++) {
		//Рефлексивність
		if (arr[i][i] == 1) {
			s++;
		}
		for (int j = 0; j < m; j++) {
			//Симетричність
			if (i >= j) {
				if (arr[i][j] == arr[j][i] && arr[i][j] == 1 && arr[j][i] == 1 && i != j) {
					k++;
				}
				else if (arr[i][j] != arr[j][i] && equal == true) {
					equal = false;
				}
			}
			//Транзитивність
			for (int q = 0; q < n; q++) {
				if (i >= j) {
					if (arr[i][j] == arr[j][k] == arr[i][k] == 1) {
						trans = true;
					}
					else if (arr[i][j] == arr[j][k] == 1 && arr[i][j] == arr[j][k] != arr[i][k])
					{
						antitrans = true;
					}
				}
			}
		}
	}
	if (s == m) {
		cout << "Matrix is reflexive" << endl;
		}
	else if (s > 0 && s != m) {
		cout << "Matrix is irreflexive" << endl;
	}
	else {
		cout << "Matrix is antireflexive" << endl;
	}

	if (k > 0 && equal == true) {
		cout << "Matrix is symmetrical" << endl;
	}
	else if (k > 0 && equal == false) {
		cout << "Matrix is asymmetrical" << endl;
	}
	else {
		cout << "Matrix is antisymmetrical" << endl;
	}

	if (trans == true && antitrans == false) {
		cout << "Matrix is transitive" << endl;
	}
	else if (trans == true && antitrans == true)
	{
		cout << "Matrix is intransitive" << endl;
	}
	else if (trans == false && antitrans == true)
	{
		cout << "Matrix is antitransitive" << endl;
	}
}
