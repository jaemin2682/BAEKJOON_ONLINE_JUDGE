#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;
int m, n;
int map[1001][1001];
bool visit[1001][1001];
vector<pair<int, int>> dxy = { {0,1}, {0,-1}, {1,0}, {-1,0} };
queue<pair<int, int>> q;

int main() {
	cin >> m >> n;
	bool check0 = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i + 1][j + 1];
			if (map[i + 1][j + 1] == 1) {
				q.push({ i + 1, j + 1 });
				visit[i + 1][j + 1];
			}
			if (map[i + 1][j + 1] == 0) check0 = true;
		}
	}

	if (!check0) {
		cout << 0;
		return 0;
	}


	int cnt = 1;
	while (!q.empty()) {
		int size = q.size();
		for (int a = 0; a < size; a++) {
			int dx = q.front().first;
			int dy = q.front().second;
			q.pop();
			for (int k = 0; k < 4; k++) {
				int nx = dx + dxy[k].first;
				int ny = dy + dxy[k].second;
				if (!visit[nx][ny] && map[nx][ny] == 0 && nx > 0 && nx <= n && ny > 0 && ny <= m) {	//map 1도 포함해야할수도..
					visit[nx][ny] = true;
					map[nx][ny] = cnt;
					q.push({ nx, ny });
				}
				else if (visit[nx][ny] && map[nx][ny] > cnt && nx > 0 && nx <= n && ny > 0 && ny <= m) {
					map[nx][ny] = cnt;
					q.push({ nx, ny });
				}
			}
		}
		cnt++;
	}

	int maxval = 0;
	bool check = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i + 1][j + 1] == 0) check = true;
			maxval = max(map[i + 1][j + 1], maxval);
		}
	}





	if (check) cout << -1;
	else cout << maxval;

	return 0;
}