#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <set>

using namespace std;

int main() {
	int n, k;
	cin >> n;
	char jiyoung[100][100];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> jiyoung[i][j];
	cin >> k;

	if (k == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n / 2; j++) {
				int temp = jiyoung[i][j];
				jiyoung[i][j] = jiyoung[i][n - j - 1];
				jiyoung[i][n - j - 1] = temp;
			}
		}
	}
	else if (k == 3) {
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n; j++) {
				int temp = jiyoung[i][j];
				jiyoung[i][j] = jiyoung[n - i - 1][j];
				jiyoung[n - i - 1][j] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << jiyoung[i][j];
		}
		cout << endl;
	}

	return 0;
}