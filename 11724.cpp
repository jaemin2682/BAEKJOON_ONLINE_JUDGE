#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <memory.h>

using namespace std;

vector<vector<int>> map(1001);
bool visit[1001];
int n, m;

void dfs(int start) {
	visit[start] = true;
	for (int i = 0; i < map[start].size(); i++) {
		int next = map[start][i];
		if (!visit[next]) {
			dfs(next);
		}
	}
}

int main() {
	cin >> n >> m;
	
	int a, b;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			cnt++;
			dfs(i);
		}
	}

	cout << cnt;

	return 0;
}