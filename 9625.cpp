#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int fibo[46];

int main() {
	int k;
	cin >> k;
	fibo[0] = 0;
	fibo[1] = 1;
	for (int i = 2; i <= 45; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	cout << fibo[k - 1] << " " << fibo[k];
	
	return 0;
}