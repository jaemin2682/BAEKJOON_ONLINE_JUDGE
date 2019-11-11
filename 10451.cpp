#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <stack>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, cnt = 0;
		cin >> n;
		int arr[1001];
		for (int j = 1; j <= n; j++)
			cin >> arr[j];
		bool check[1001];
		memset(check, false, sizeof(check));
		for (int j = 1; j <= n; j++) {
			if (!check[j]) {
				int index = j;
				check[index] = true;
				do {
					index = arr[index];
					check[index] = true;
				} while (index != j);
				cnt++;
			}
		}
		cout << cnt << endl;

	}

	return 0;
}