#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	while (1) {
		int n;
		cin >> n;
		if (n == 0) break;
		int sum = 0;
		for (int i = 1; i < n; i++) {
			if (n%i == 0) sum += i;
		}
		cout << n << " ";
		if (n == sum) cout << "PERFECT";
		else if (n > sum) cout << "DEFICIENT";
		else cout << "ABUNDANT";
		cout << endl;
	}
	return 0;
}

