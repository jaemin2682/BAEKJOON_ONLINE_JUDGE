#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

char map[201][21];

int main() {
	int n;
	string str;
	while (1) {
		cin >> n;
		if (n == 0) break;
		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			if ((i % (n * 2)) < n) {
				map[i/n][i % n] = str[i];
			}
			else
			{
				map[i / n][n - 1 - i % n] = str[i];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < str.size() / n; j++) {
				cout << map[j][i];
			}
		}
		cout << endl;
	}

	return 0;
}

