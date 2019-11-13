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
	long long fibo[68];
	fibo[0] = 1;
	fibo[1] = 1;
	fibo[2] = 2;
	fibo[3] = 4;
	for (int i = 4; i <= 67; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2] + fibo[i - 3] + fibo[i - 4];
	}
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		cout << fibo[n] << endl;
	}
	return 0;
}