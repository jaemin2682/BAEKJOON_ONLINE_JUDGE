#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		vector<int> first;
		vector<int> second;
		int n, m, num;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> num;
			first.push_back(num);
		}
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> num;
			second.push_back(num);
		}
		int minval = 1000001;
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < m; b++) {
				minval = min(minval, abs(first[a] - second[b]));
			}
		}
		cout << minval << endl;
	}

	return 0;
}

