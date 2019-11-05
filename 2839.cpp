#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int main() {
	int N, cnt, res=50000;
	cin >> N;
	for (int i = N / 5 + 1; i >= 0; i--) { //i´Â 4~0
		int store = N;
		cnt = 0;
		store -= 5 * i;
		if (store == 0) {
			res = i;
			break;
		}
		else if (store < 3) continue;
		else if (store % 3 == 0) {
			cnt += i + store / 3;
			res = min(res, cnt);
		}
	}
	if (res == 50000) cout << -1;
	else cout << res;
	return 0;
}