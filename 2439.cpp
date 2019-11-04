#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n-i; j++) {
			cout << " ";
		}
		for (int j = i; j > 0 ; j--) {
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}