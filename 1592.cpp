#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <queue>

using namespace std;

int main() {
	int N, M, L;
	cin >> N >> M >> L;
	vector<int> friends(N + 1);
	int baller = 1, cnt = 1;
	friends[1] = 1;
	while (1) {
		if (friends[baller] % 2 == 1) {
			baller = baller + L;
			if (baller > N) baller -= N;
			friends[baller]++;
			cnt++;
			if (friends[baller] == M) break;
		}
		else {
			baller = baller - L;
			if (baller < 1) baller += N;
			friends[baller]++;
			cnt++;
			if (friends[baller] == M) break;
		}
	}
	cout << cnt - 1;
	return 0;
}