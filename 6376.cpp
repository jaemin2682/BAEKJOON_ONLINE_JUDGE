#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

double sum;

double factorial(int n) {
	if (n <= 1) return 1/sum;
	else {
		sum *= n;
		return factorial(n - 1);
	}
}

int main() {
	cout << "n e" << endl;
	cout << "- -----------" << endl;
	int e;
	double num = 0;
	cout.precision(9);
	for (int i = 0; i < 10; i++) {
		sum = 1;
		num += factorial(i);
		if (i < 3) cout << i << " " << num << endl;
		else cout << fixed <<  i << " " << num << endl;
	}
	return 0;
}