#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;
char map[50][50];

int main() {
	int n, m;
	vector<int> list;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			int uncor = 0;
			int uncor1 = 0;
			for (int x = 0; x < 8; x++) {
				for (int y = 0; y < 8; y++) {

					if (((i + x) % 2 == 0 && (j + y) % 2 == 0) || ((i + x) % 2 == 1 && (j + y) % 2 == 1)) 	//¦¦||ȦȦ
						if (map[i + x][j + y] == 'B') uncor++;
						else uncor1++;
					else
						if (map[i + x][j + y] == 'W') uncor++;
						else uncor1++;

				}
			}
			int res = min(uncor, uncor1);
			list.push_back(res);
		}
	}

	sort(list.begin(), list.end());
	cout << list[0];

	return 0;
}

