#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int m, n, k;
bool map[100][100];
vector<vector<int>> rec(100);
queue<pair<int, int>> q;
vector<pair<int, int>> v = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
vector<int> answer;

void bfs() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!map[i][j]) {
				q.push({ i, j });
				map[i][j] = true;
				int cnt = 1;
				while (!q.empty()) {
					int dx = q.front().first;
					int dy = q.front().second;
					q.pop();
					for (int a = 0; a < 4; a++) {
						int nx = dx + v[a].first;
						int ny = dy + v[a].second;
						if (!map[nx][ny] && nx >= 0 && nx < m && ny >= 0 && ny < n) {
							map[nx][ny] = true;
							cnt++;
							q.push({ nx, ny });
						}
					}
				}
				answer.push_back(cnt);
			}
		}
	}
}

int main() {
	int a, b, c, d;
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> a >> b >> c >> d;
		int temp = d;
		d = m - b ;
		b = m - temp;
		rec[i].push_back(a);
		rec[i].push_back(b);
		rec[i].push_back(c);
		rec[i].push_back(d);
	}
	rec.resize(k);

	for (int a = 0; a < rec.size(); a++) {
		for (int i = rec[a][0]; i < rec[a][2]; i++) {
			for (int j = rec[a][1]; j < rec[a][3]; j++) {
				map[j][i] = true;
			}
		}
	}

	bfs();
	sort(answer.begin(), answer.end());

	cout << answer.size() << endl;
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}

	return 0;
}