#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool map[251][251];

vector<pair<int, int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

int main()
{
    int m, n, cnt=0;
    queue<pair<int, int>> q;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> map[i][j];

    for (int a = 1; a <= m; a++) {
        for (int b = 1; b <= n; b++) {
            if (map[a][b]) {
                map[a][b] = 0;
                q.push({a, b});
                while (!q.empty()) {
                    int dx = q.front().first;
                    int dy = q.front().second;
                    q.pop();
                    for (int i = 0; i < 8; i++) {
                        int nx = dx + d[i].first;
                        int ny = dy + d[i].second;
                        if (map[nx][ny] && nx > 0 && nx <= m && ny > 0 && ny <= n) {
                            q.push({nx, ny});
                            map[nx][ny] = 0;
                        }
                    }
                }
                cnt++;
            }
        }
    }
    cout << cnt;

    return 0;
}