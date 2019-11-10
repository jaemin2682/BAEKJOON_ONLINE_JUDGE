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
	int num1, num2;
	cin >> num1 >> num2;
	int gcdval = gcd(num1, num2);
	cout << gcdval << endl << (num1*num2) / gcdval;
	

	return 0;
}


