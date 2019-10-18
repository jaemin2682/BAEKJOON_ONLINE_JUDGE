#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int r, c, res;
string map[20];
vector<pair<int, int>> v = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

void dfs(int x, int y, set<int> pre, int cnt) {
	pre.insert(map[x][y]);
	for (int i = 0; i < 4; i++) {
		int nx = x + v[i].first;
		int ny = y + v[i].second;
		if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
			if (pre.find(map[nx][ny]) == pre.end()) {
				dfs(nx, ny, pre, cnt + 1);
			}
		}
	}
	res = max(res, cnt);
}
int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> map[i];
	}
	set<int> pre;

	dfs(0, 0, pre, 1);	

	cout << res;

	return 0;
}