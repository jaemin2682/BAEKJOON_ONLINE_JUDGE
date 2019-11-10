#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	int n, ans=0;
	cin >> n;
	vector<int> list(n);
	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}

	sort(list.begin(), list.end());
	do {
		int sum = 0;
		for (int i = 0; i < n - 1 ; i++) {
			sum += abs(list[i] - list[i + 1]);
		}
		ans = max(ans, sum);

	} while (next_permutation(list.begin(), list.end()));

	cout << ans;

	return 0;
}

