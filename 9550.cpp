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
		int n, k, sum = 0;
		cin >> n >> k;
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
			sum += num / k;
		}
		cout << sum << endl;
	}
	return 0;
}