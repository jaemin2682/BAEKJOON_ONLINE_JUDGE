#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int n, one, two, m, x, y, cnt=0;
vector<vector<int>> relation(101);
bool visit[101];
bool check;

void bfs(int start) {
	queue<int> q;
	visit[start] = true;
	q.push(start);
	while (!q.empty()) {
		cnt++;
		int size = q.size();
		for (int j = 0; j < size; j++) {
			int ft = q.front();
			q.pop();
			for (int i = 0; i < relation[ft].size(); i++) {
				int next = relation[ft][i];
				if (!visit[next]) {
					q.push(next);
					visit[next] = true;
					if (next == two) {
						check = true;
						return;
					}
				}
			}
		}
	}
}

int main() {
	cin >> n;
	cin >> one >> two;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		relation[x].push_back(y);
		relation[y].push_back(x);
	}
	relation.resize(n + 1);

	bfs(one);

	if (!check) cout << -1;
	else  cout << cnt;
	return 0;
}