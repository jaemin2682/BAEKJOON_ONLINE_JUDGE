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
	int n;
	double cre;
	cin >> n;
	for (int i = 0; i < n; i++) {
		double num;
		cin >> num;
		if (i == 0) cre = num;
		else {
			double gcdval = gcd(cre, num);
			cout << cre / gcdval << "/" << num / gcdval << endl;
		}
	}
	

	return 0;
}