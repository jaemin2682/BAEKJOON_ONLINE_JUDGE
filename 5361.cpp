#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		double a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		printf("$%.2f\n", a * 350.34 + b * 230.90 + c * 190.55 + d * 125.30 + e * 180.90);
	}

	return 0;
}