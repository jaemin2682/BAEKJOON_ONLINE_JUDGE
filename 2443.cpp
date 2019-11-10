#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int cnt = 1, cnt1 = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < cnt1; j++) cout << ' ';
		for (int j = 0; j < 2 * n - cnt; j++) cout << '*';
		cout << endl;
		cnt += 2;
		cnt1++;
	}

	return 0;
}