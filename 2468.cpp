#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int n, maxi = 1, mini = 100, cnt;
int map[101][101];
bool visit[101][101];
vector<pair<int, int>> v = { {0,1}, {0,-1},{1,0},{-1,0} };
vector<int> answer;

void dfs(int start, int end, int height) {
	for (int i = 0; i < 4; i++) {
		int nx = start + v[i].first;
		int ny = end + v[i].second;
		if (nx > 0 && nx <= n && ny > 0 && ny <= n && !visit[nx][ny] && map[nx][ny] > height) {
			visit[nx][ny] = true;
			dfs(nx, ny, height);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			maxi = max(maxi, map[i][j]);
			mini = min(mini, map[i][j]);
		}
	}

	for (int i = mini; i < maxi; i++) {
		cnt = 0;
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				if (!visit[a][b] && map[a][b] > i) {
					visit[a][b] = true;
					dfs(a, b, i);
					cnt++;
				}
			}
		}
		answer.push_back(cnt);
		memset(visit, false, sizeof(visit));
	}
	int ans = 1;
	for (int i = 0; i < answer.size(); i++) {
		ans = max(ans, answer[i]);
	}
	
	cout << ans;

	return 0;
}