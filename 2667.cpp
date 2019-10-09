	#include <vector>
	#include <iostream>
	#include <queue>
	#include <algorithm>
	#include <string>

	using namespace std;

	int map[26][26];
	bool visit[26][26];

	int main() {

		int n;
		vector<pair<int, int>> dxy = { {1,0}, {-1,0}, {0,-1}, {0,1} };
		string temp;
		vector<string> store;
		vector<int> answer;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			store.push_back(temp);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				map[i][j] = store[i-1][j-1] - '0';
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j] && !visit[i][j]) {
					int num = 1;
					cnt++;
					map[i][j] = cnt;
					queue<pair<int, int>> q;
					q.push({ i,j });
					visit[i][j] = true;
					while (!q.empty()) {
						int dx = q.front().first;
						int dy = q.front().second;
						q.pop();
						for (int k = 0; k < 4; k++) {	
							int nx = dx + dxy[k].first;
							int ny = dy + dxy[k].second;
							if (map[nx][ny] && !visit[nx][ny] && nx > 0 && nx <= n && ny > 0 && ny <= n) {
									visit[nx][ny] = true;
									num++;
									map[nx][ny] = cnt;
									q.push({ nx, ny });
							}
						}
					}
					answer.push_back(num);
				}
				else visit[i][j] = true;
			}
		}
		sort(answer.begin(), answer.end());
		cout << cnt << endl;
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << endl;
		}

		return 0;
	}