#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <queue>

using namespace std;

int main() {
	int C, K, P, ans = 0;
	cin >> C >> K >> P;
	for (int i = 1; i <= C; i++) {
		ans += K * i + P * i*i;
	}
	cout << ans;
	return 0;
}