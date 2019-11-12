#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	long long n;
	cin >> n;

	if (n == 1) cout << 1;
	else if (n % 2 == 1) cout << 0;
	else {
		while (n >= 2) {
			if (n == 2) {
				cout << 1;
				return 0;
			}
			else if(n % 2 == 1) {
				cout << 0;
				return 0;
			}
			n /= 2;
		}
		cout << 0;
	}

	return 0;
}