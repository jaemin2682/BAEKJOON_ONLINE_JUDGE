#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int main() {
	int n, res, ans=1000001;
	string str;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		res = i;
		str = to_string(i);
		for (int j = 0; j < str.size(); j++) {
			res += str[j] - 48;
		}
		if (res == n) {
			ans = min(ans, i);
		}
	}

	if (ans == 1000001) cout << 0;
	else cout << ans;

	return 0;
}

