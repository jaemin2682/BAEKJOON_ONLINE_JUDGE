#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>


using namespace std;

long long fib[45 + 1];

int main() {
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i <= 45; i++) fib[i] = fib[i - 1] + fib[i - 2];

	int n;
	cin >> n;
	cout << fib[n];

	return 0;
}


