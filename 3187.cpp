#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char map[251][251];
bool visit[251][251];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int main()
{
    int r, c, wolfNum=0, sheepNum=0;
    cin >> r >> c;
    queue<pair<int, int>> q;

    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            cin >> map[i][j];

    for (int a = 1; a <= r; a++) {
        for (int b = 1; b <= c; b++) {
            if (!visit[a][b] && (map[a][b] == 'v' || map[a][b] == 'k')) {
                int sheep = 0, wolf = 0;
                if (map[a][b] == 'v')
                    wolf++;
                else if (map[a][b] == 'k')
                    sheep++;
                visit[a][b] = true;
                q.push({a, b});
                while (!q.empty()) {
                    int dx = q.front().first;
                    int dy = q.front().second;
                    q.pop();
                    for (int i = 0; i < 4; i++)
                    {
                        int nx = dx + d[i].first;
                        int ny = dy + d[i].second;
                        if (!visit[nx][ny] && nx > 0 && nx <= r && ny > 0 && ny <= c &&
                            map[nx][ny] != '#')
                        {
                            q.push({nx, ny});
                            visit[nx][ny] = true;
                            if (map[nx][ny] == 'v')
                                wolf++;
                            else if (map[nx][ny] == 'k')
                                sheep++;
                        }
                    }
                }
                if(sheep > wolf) wolf=0;
                else sheep = 0;
                wolfNum += wolf;
                sheepNum += sheep;
            }
        }
    }
    cout << sheepNum << " " << wolfNum;

    return 0;
}