#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <queue>

using namespace std;

int main() {
	int n, cnt=0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		if (num != i) cnt++;
	}
	cout << cnt;

	return 0;
}