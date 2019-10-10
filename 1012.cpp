#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <memory.h>

using namespace std;
bool visit[51][51];
int map[51][51];
vector<pair<int, int>> dxy = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };


int main() {
	int t;
	cin >> t;
	for (int re = 0; re < t; re++) {
		int m, n, k;
		int a, b;
		queue<pair<int, int>> q;

		cin >> m >> n >> k;
		for (int i = 1; i <= k; i++) {
			cin >> a >> b;
			map[b + 1][a + 1] = 1;
		}
		int cnt = 0;

		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				if (map[j][k] && !visit[j][k]) {
					visit[j][k] = true;

					q.push({ j, k });
					cnt++;
					map[j][k] = cnt;
					while (!q.empty()) {
						int dx = q.front().first;
						int dy = q.front().second;
						q.pop();
						for (int i = 0; i < 4; i++) {
							int nx = dx + dxy[i].first;
							int ny = dy + dxy[i].second;
							if (!visit[nx][ny] && map[nx][ny] && nx > 0 && nx <= 50 && ny > 0 && ny <= 50) {
								q.push({ nx, ny });
								visit[nx][ny] = true;
								map[nx][ny] = cnt;
							}
						}

					}
				}
			}
		}
		cout << cnt << endl;

		memset(visit, false, sizeof(visit));
		memset(map, 0, sizeof(map));

	}

	return 0;
}