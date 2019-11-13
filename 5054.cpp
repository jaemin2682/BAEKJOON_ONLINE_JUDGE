#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <set>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		vector<int> list(n);
		for (int j = 0; j < n; j++) cin >> list[j];
		sort(list.begin(), list.end());
		int sum = 0;
		for (int j = 0; j < n - 1; j++)
			sum = sum + list[j + 1] - list[j];
		sum += list[n - 1] - list[0];
		cout << sum << endl;
	}

	return 0;
}