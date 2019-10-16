#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, maxi=0;
int map[9][9];
vector<pair<int, int>> dxy = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

void bfs() {
	int tem[9][9];
	queue<pair<int, int>> q;

	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= m; b++) {
			tem[a][b] = map[a][b];
		}
	}

	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= m; b++) {
			if (tem[a][b] == 2) q.push({ a, b });
		}
	}
	while (!q.empty()) {
		int dx = q.front().first;
		int dy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = dx + dxy[i].first;
			int ny = dy + dxy[i].second;
			if (tem[nx][ny] == 0 && nx > 0 && nx <= 8 && ny > 0 && ny <= 8) {
				tem[nx][ny] = 2;
				q.push({ nx, ny });
			}
		}
	}

	int count = 0;
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= m; b++) {
			if (tem[a][b] == 0) count++;
		}
	}
	maxi = max(maxi, count);
}


void wall(int cnt) {
	
	if (cnt == 0) {
		bfs();
		
		return;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				wall(cnt-1);
				map[i][j] = 0;
			}
		}
	}
}


int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}

	wall(3);

	cout << maxi;

	return 0;
}