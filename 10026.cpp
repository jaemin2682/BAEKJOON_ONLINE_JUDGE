#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int n;
int cnt = 0;
char map[101][101];

int visit[101][101];
queue<pair<int, int>> q;
vector<pair<int, int>> v = { {1,0}, {-1,0}, {0,1}, {0,-1} };

void bfs() {
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			if(!visit[a][b]) {
				q.push({ a,b });
				cnt++;
				visit[a][b] = cnt;
				while (!q.empty()) {
					int dx = q.front().first;
					int dy = q.front().second;
					q.pop();
					for (int i = 0; i < 4; i++) {
						int nx = dx + v[i].first;
						int ny = dy + v[i].second;
						if (dx > 0 && dx <= n && dy > 0 && dy <= n && !visit[nx][ny] && map[dx][dy] == map[nx][ny]) {
							q.push({ nx, ny });
							visit[nx][ny] = cnt;
						}
					}
				}
			}
		}
	}
}


int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	bfs();

	cout << cnt << " ";

	memset(visit, 0, sizeof(visit));
	cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if(map[i][j] == 'R')  map[i][j] = 'G';
		}
	}
	bfs();
	cout << cnt;

	return 0;
}