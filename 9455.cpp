#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <set>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		bool box[101][101];
		int index[101];
		int sum = 0;

		memset(box, false, sizeof(box));
		memset(index, false, sizeof(index));

		int m, n;
		cin >> m >> n;
		for (int a = 1; a <= m; a++) {
			for (int b = 1; b <= n; b++) {
				cin >> box[a][b];
				if (box[a][b]) index[b]++;
			}
		}

		for (int a = 1; a <= m; a++) {
			for (int b = 1; b <= n; b++) {
				if (box[a][b]) {
					sum += m - a - index[b] + 1;
					index[b]--;
				}
			}
		}

		cout << sum << endl;
		
	}
	return 0;
}