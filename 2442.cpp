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
		for (int j = 0; j < cntblank; j++) cout << " ";
		for (int j = 0; j < cntstar; j++) cout << "*";
		cntblank--;
		cntstar += 2;
		cout << endl;
	}
	return 0;
}