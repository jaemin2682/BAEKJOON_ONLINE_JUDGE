#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int gcd(int a, int b) {
	if (a < b) swap(a, b);
	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main() {
	while (1) {
		int first, second;
		cin >> first >> second;
		if (first == 0 && second == 0) return 0;

		if (second%first == 0) cout << "factor" << endl;
		else if (first%second == 0) cout << "multiple" << endl;
		else cout << "neither" << endl;
	}

	return 0;
}