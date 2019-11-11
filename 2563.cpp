#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

bool paper[101][101];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		for(int x=100-b;x>90-b;x--) {
			for (int y = a; y <a+10; y++) {
				paper[x][y] = true;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (paper[i][j]) cnt++;
		}
	}
	cout << cnt;


	return 0;
}