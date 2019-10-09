#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;
vector<vector<int>> map(1001);
bool visit[1001];

void bfs(int start) {
	queue<int> q;
	memset(visit, false, sizeof(visit));
	q.push(start);
	visit[start] = true;
	cout << start << " ";
	while (!q.empty()) {
		int ft = q.front();
		q.pop();
		for (int i = 0; i < map[ft].size(); i++) {
			int nv = map[ft][i];
			if (!visit[nv]) {
				visit[nv] = true;
				cout << nv << " ";
				q.push(nv);
			}
		}
	}
}


void dfs(int start) {
	for (int i = 0; i < map[start].size(); i++) {
		if (!visit[map[start][i]]) {
			visit[map[start][i]] = true;
			cout << map[start][i] << " ";
			dfs(map[start][i]);
		}
	}
}

int main() {
	int n, m, v, a, b;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		sort(map[i].begin(), map[i].end());
	}
	visit[v] = true;
	cout << v << " ";
	dfs(v);
	cout << endl;
	bfs(v);

	return 0;
}