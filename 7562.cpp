#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int n, a, b, cnt;
vector<int> l;
vector<pair<int, int>> now;
vector<pair<int, int>> point;
int map[301][301];
bool visit[301][301];	// ¹Ø : +, À§ : -, ¿À¸¥:+, ¿Þ:-
vector<pair<int, int>> dxy = { {-2, 1}, {-1,2}, {1, 2}, {2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1} };

void bfs(int index) {
	queue<pair<int, int>> q;
	visit[now[index].first][now[index].second] = true;
	q.push({ now[index].first, now[index].second });
	if (now[index].first == point[index].first && now[index].second == point[index].second) {
		return;
	}
	while (!q.empty()) {
		int size = q.size();
		cnt++;
		for (int j = 0; j < size; j++) {
			int dx = q.front().first;
			int dy = q.front().second;
			q.pop();
			for (int i = 0; i < 8; i++) {
				int nx = dx + dxy[i].first;
				int ny = dy + dxy[i].second;
				if (!visit[nx][ny] && nx >= 0 && nx < l[index] && ny >= 0 && ny < l[index]) {
					visit[nx][ny] = true;
					q.push({ nx, ny });
					if (nx == point[index].first && ny == point[index].second) {
						return;
					}
				}
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		l.push_back(a);
		cin >> a >> b;
		now.push_back({ a, b });
		cin >> a >> b;
		point.push_back({ a, b });
	}

	for (int i = 0; i < n; i++) {
		cnt = 0;
		bfs(i);
		cout << cnt << endl;
		memset(visit, false, sizeof(visit));
	}

	return 0;
}