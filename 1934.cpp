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
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		cout << num1*num2 / gcd(num1, num2) << endl;
	}

	return 0;
}