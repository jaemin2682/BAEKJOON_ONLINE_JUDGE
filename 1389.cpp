#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int n, m, cnt, sum;
vector<vector<int>> v(101);
vector<int> arr;
bool visit[101];

void bfs(int start, int point) {
	queue<int> q;
	q.push(start);
	visit[start] = true;
	while (!q.empty()) {
		int size = q.size();
		cnt++;
		for (int j = 0; j < size; j++) {
			int ft = q.front();
			q.pop();
			for (int i = 0; i < v[ft].size(); i++) {
				int next = v[ft][i];
				if (!visit[next]) {
					visit[next] = true;
					q.push(next);
				}
				if (next == point) {
					sum += cnt;
					return;
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	v.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		sum = 0;
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				cnt = 0;
				bfs(i, j);
				memset(visit, false, sizeof(visit));
			}
		}
		arr.push_back(sum);
	}
	int mini = 5001;
	int j;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] < mini) {
			mini = arr[i];
			j = i;
		}
		else if (arr[i] == mini) {
			if (j >= i) {
				j = i;
			}
		}
	}
	cout << j+1;

	return 0;
}