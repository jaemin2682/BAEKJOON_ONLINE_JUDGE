#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int cntblank = n - 1;
	int cntstar = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < cntblank; j++) cout << ' ';
		for (int j = 0; j < cntstar; j++) cout << '*';
		cout << endl;
		cntblank--;
		cntstar++;
	}
	cntblank = 1;
	cntstar = n - 1;
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < cntblank; j++) cout << ' ';
		for (int j = 0; j < cntstar; j++) cout << '*';
		cntblank++;
		cntstar--;
		cout << endl;
	}


	return 0;
}

