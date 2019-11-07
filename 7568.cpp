#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;
int num[51];

int main() {
	int n, x, y;
	cin >> n;
	vector<pair<int, int>> list;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		list.push_back({ x, y });
		num[i]++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			else if (list[i].first < list[j].first && list[i].second < list[j].second) {
				num[i]++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << num[i] << " ";
	}

	return 0;
}

