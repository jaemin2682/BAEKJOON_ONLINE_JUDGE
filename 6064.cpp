#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <memory.h>

using namespace std;

int lcm(int x, int y) {
	if (x < y) swap(x, y);
	int a = x * y;
	while (y != 0) {
		int temp = x % y;
		x = y;
		y = temp;
	}
	return a / x;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int m, n, x, y, cnt=0;
		cin >> m >> n >> x >> y;
		int varlcm = lcm(m, n);
		
		while (1) {
			if (x > varlcm || (x - 1) % n + 1 == y) break;
			x += m;
		}
		if (x > varlcm) cout << -1 << endl;
		else cout << x << endl;

	}
	
	return 0;
}

