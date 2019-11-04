#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, x;
	vector<int> num;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		num.push_back(number);
	}

	for (int i = 0; i < n; i++) {
		if (x > num[i]) cout << num[i] << " ";
	}

	return 0;
}