#include <iostream>
using namespace std;

int main() {
	int n, k, a[10];
	int temp = 0, cnt=0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = n-1; i >= 0; i--) {
		if (k > a[i]) {
			while (1) {
				if (temp+a[i] > k) break;
				temp = temp + a[i];
				cnt++;
			}
		}
		if (temp == k) break;
	}
	cout << cnt;
}
