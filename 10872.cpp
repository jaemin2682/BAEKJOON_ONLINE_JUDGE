#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	int sum = 1;

	if (n == 0) cout << 1;
	else {
		while (n != 0) {
			sum *= n;
			n--;
		}
		cout << sum;
	}
	return 0;
}

