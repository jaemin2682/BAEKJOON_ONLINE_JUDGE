#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, m, num;
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		int visit[10001] = { 0, };
		vector<pair<int, int>> order;
		vector<int> v;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> num;
				if (!visit[num]) v.push_back(num);
				visit[num]++;
			}
		}

		for (int j = 0; j < v.size(); j++) {
			order.push_back({ visit[v[j]], v[j] });
		}

		sort(order.begin(), order.end(), greater<pair<int, int>>());
		int second_score = order[1].first;

		for (int i = order.size()-1; i >= 0; i--) {
			if (order[i].first == second_score) cout << order[i].second << " ";
		}
		cout << endl;
	}

	return 0;
}