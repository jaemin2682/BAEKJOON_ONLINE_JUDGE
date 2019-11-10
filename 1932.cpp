#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;
int tri[501][501];
int sum[501][501];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= i; j++) 
			cin >> tri[i][j];
	
	sum[1][1] = tri[1][1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) sum[i][j] = tri[i][j] + sum[i - 1][j];
			else if (j == i) sum[i][j] = tri[i][j] + sum[i - 1][j - 1];
			else {
				if (sum[i - 1][j] >= sum[i - 1][j - 1]) {
					sum[i][j] = tri[i][j] + sum[i - 1][j];
				}
				else {
					sum[i][j] = tri[i][j] + sum[i - 1][j - 1];
				}
			}
		}
	}
	int maxval = 0;
	for (int i = 1; i <= n; i++) {
		maxval = max(maxval, sum[n][i]);
	}
	cout << maxval;

	return 0;
}