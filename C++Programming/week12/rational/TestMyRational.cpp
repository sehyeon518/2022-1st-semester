#include <fstream>
#include <cstdlib>
#include "MyRational.h"
#include <algorithm>

using namespace std;

void testSimpleCase();
void testDataFromFile();
bool cmp(myRational left, myRational right);

int main(){
	testSimpleCase();
	testDataFromFile();
}

void testSimpleCase(){
	myRational frac1(2), frac2(3, 2), frac3(6, 4), frac4(12, 8), frac5, frac6, frac7;
	cout << frac1 << " " << frac2 << " " << frac3 << " " << frac4 << " " << frac5 << endl;
	cout << frac1.getNumerator() << " " << frac1.getDenominator() << endl;

	// Check arithmetic operators
	cout << frac1 * frac2 << " " << frac1 + frac3 << " " << frac2 - frac1 << " " << frac3 / frac2 << endl;

	// Check comparison operators
	cout << (frac1 < frac2) << " ";
	cout << (frac1 <= frac2) << " ";
	cout << (frac1 > frac2) << " ";
	cout << (frac1 >= frac2) << " ";
	cout << (frac1 == frac2) << " ";
	cout << (frac1 != frac2) << " ";

	cout << (frac2 < frac3) << " ";
	cout << (frac2 <= frac3) << " ";
	cout << (frac2 > frac3) << " ";
	cout << (frac2 >= frac3) << " ";
	cout << (frac2 == frac3) << " ";
	cout << (frac2 != frac3) << endl;

	cout << (frac6 = frac3) << " ";
	cout << (frac6 += frac3) << " ";
	cout << (frac6 -= frac3) << " ";
	cout << (frac6 *= frac3) << " ";
	cout << (frac6 /= frac3) << endl;
	cout << -frac6 << endl;

	frac6 = (++frac4) + 2;
	frac7 = 2 + (frac4++);
	cout << frac4 << " " << frac6 << " " << frac7 << endl;

	frac6 = (--frac4) - 2;
	frac7 = 2 - (frac4--);
	cout << frac4 << " " << frac6 << " " << frac7 << endl;

	cout << 2 * frac3 << " " << frac3 * 2 << " " << 2 / frac3 << " " << frac3 / 2 << endl;
}

void testDataFromFile(){
	ifstream inStream;
	int numTestCases;
	inStream.open("input.txt");

	if (inStream.fail()){
		cerr << "Input file opening failed.\n";
		exit(1);
	}

	inStream >> numTestCases;
	for (int i = 0; i < numTestCases; i++){
		int cnt;
		inStream >> cnt;

		myRational* arr = new myRational[cnt];
		for (int j = 0; j < cnt; j++) {
			inStream >> arr[j];
		}

		sort(arr, arr + cnt, cmp);
		for (int j = 0; j < cnt; j++) {
			cout << arr[j] << " ";
		}
		cout << "\n";

		delete[] arr;
	}

	inStream.close();
}

bool cmp(myRational left, myRational right) {
	return left < right;
}
