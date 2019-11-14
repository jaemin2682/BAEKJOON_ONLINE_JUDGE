#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <queue>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		vector<pair<int, string>> list;
		for (int j = 0; j < p; j++) {
			string str;
			int cost;
			cin >> cost >> str;
			list.push_back({ cost, str });
		}
		sort(list.begin(), list.end(), greater<pair<int, string>>());
		cout << list[0].second << endl;
	}
	return 0;
}