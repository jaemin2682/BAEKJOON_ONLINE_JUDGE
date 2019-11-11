#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <stack>

using namespace std;

int arr[301][301];

int main() {
	int n, m, k;
	cin >> n >> m;
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= m; b++) {
			cin >> arr[a][b];
		}
	}
	cin >> k;
	int i, j, x, y;
	for (int c = 0; c < k; c++) {
		cin >> i >> j >> x >> y;
		int sum = 0;
		for (int posx = i; posx <= x; posx++) {
			for (int posy = j; posy <= y; posy++) {
				sum += arr[posx][posy];
			}
		}
		cout << sum << endl;
	}

	return 0;
}