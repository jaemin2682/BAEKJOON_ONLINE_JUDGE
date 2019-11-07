#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int main() {
	int n, m, a, sum, res=0;
	cin >> n >> m;
	vector<int> list;
	for (int i = 0; i < n; i++) {
		cin >> a;
		list.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			for (int k = j+1; k < n; k++) {
				sum = list[i] + list[j] + list[k];
				if (sum == m) {
					cout << sum;
					return 0;
				}
				else if (sum < m) {
					if (m - res > m - sum) {
						res = sum;
					}
				}
			}
		}
	}
	cout << res;

	return 0;
}

