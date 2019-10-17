#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int m, n, h, cnt=0;
int map[101][101][101];
bool visit[101][101][101];
queue<vector<int>> q;
vector<vector<int>> v = { {1,0,0}, {0,1,0}, {0,0,1}, {-1,0,0}, {0,-1,0}, {0,0,-1} };

void bfs() {
	
	while (!q.empty()) {
		int size = q.size();
		cnt++;
		for (int a = 0; a < size; a++) {
			int dz = q.front()[0];
			int dy = q.front()[1];
			int dx = q.front()[2];
			
			q.pop();
			for (int i = 0; i < 6; i++) {
				int nz = dz + v[i][0];
				int ny = dy + v[i][1];
				int nx = dx + v[i][2];
				if (nz > 0 && nz <= h && ny > 0 && ny <= n && nx > 0 && nx <= m) {
					if (!visit[nz][ny][nx] && map[nz][ny][nx] == 0) {
						q.push({ nz, ny, nx });
						visit[nz][ny][nx] = true;
					}
				}
			}
		}
		
	}
}

int main() {
	bool zero = false;
	cin >> m >> n >> h;
	for (int z = 1; z <= h; z++) {
		for (int y = 1; y <= n; y++) {
			for (int x = 1; x <= m; x++) {
				cin >> map[z][y][x];
				if (map[z][y][x] == 1) {
					q.push({ z, y, x });
					visit[z][y][x] = 1;
				}
				if (map[z][y][x] == 0) {
					zero = true;
				}
				if (map[z][y][x] == -1) {
					visit[z][y][x] = 1;
				}
			}
		}
	}

	bfs();
	bool che = false;
	for (int z = 1; z <= h; z++) {
		for (int y = 1; y <= n; y++) {
			for (int x = 1; x <= m; x++) {
				if (visit[z][y][x] == 0) {
					che = true;
				}
			}
		}
	}
	

	if (!zero) cout << 0;
	else if (che) cout << -1;
	else cout << cnt-1;

	return 0;
}