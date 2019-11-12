#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	int n, score1 = 100, score2 = 100;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b) score2 -= a;
		else if (a < b) score1 -= b;
	}
	cout << score1 << endl << score2;

	return 0;
}