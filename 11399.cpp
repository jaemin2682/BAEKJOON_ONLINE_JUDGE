#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, p[1001], res=0;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i];
	sort(p+1, p + n + 1);

	for (int i = 1; i <= n; i++) {
		res += p[i] * (n - i + 1);
	}

	cout << res;
}
