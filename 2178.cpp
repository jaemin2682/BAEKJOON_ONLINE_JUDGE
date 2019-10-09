#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;
int n, m;
int map[101][101];
bool visit[101][101];
vector<pair<int, int>> dxy = { {1, 0}, {-1, 0}, {0, 1}, {0,-1} };

void bfs(int start) {	//1
	int cnt = 1;
	queue<pair<int, int>> q;
	q.push({ start, start });
	visit[start][start] = true;
	
	while (!q.empty()) {
		int size = q.size();
		for (int j = 0; j < size; j++) {
			int dx = q.front().first;
			int dy = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = dx + dxy[i].first;
				int ny = dy + dxy[i].second;
				if (!visit[nx][ny] && nx > 0 && nx <= n && ny > 0 && ny <= m && map[nx][ny]) {
					visit[nx][ny] = true;
					q.push({ nx, ny });
				}
				if (nx == n && ny == m) {
					cout << cnt+1;
					return;
				}
			}
		}
		cnt++;
	}
}


int main() {
	
	string a;
	cin >> n >> m;
	vector<string> temp;
	for (int i = 0; i < n; i++) {
		cin >> a;
		temp.push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			map[i][j] = temp[i-1][j-1] - '0';
		}
	}

	bfs(1);

	return 0;
}