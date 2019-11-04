#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, sum=0;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		sum += i;
	}
	cout << sum;

	return 0;
}