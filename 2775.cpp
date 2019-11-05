#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <memory.h>

using namespace std;

int visit[15][15];

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int k, n;
		cin >> k >> n;
		memset(visit, false, 15 * 15);
		for (int j = 1; j <= n; j++) {
			visit[0][j] = j;
		}
		for (int j = 1; j <= k; j++) {
			visit[j][1] = 1;
		}

		for (int j = 1; j <= k; j++) {
			for (int a = 2; a <= n; a++) {
				visit[j][a] = visit[j - 1][a] + visit[j][a - 1];
			}
		}

		cout << visit[k][n] << endl;
	}


	/*
	
	1 3 6
	1 2 3
	*/



	return 0;
}
