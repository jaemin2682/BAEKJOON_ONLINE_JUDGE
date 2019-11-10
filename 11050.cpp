#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

double arr[11];

int fact(int n) {
	if (n == 1 || n==0) return 1;
	return fact(n - 1) * n;
}

int main() {
	int n, k;
	double ans = 1;
	cin >> n >> k;
	
	for (int i = 0; i <= 10; i++) {
		arr[i] = fact(i);
	}

	ans = arr[n] / (arr[k]*(arr[n-k]));
	cout << ans;

	return 0;
}

