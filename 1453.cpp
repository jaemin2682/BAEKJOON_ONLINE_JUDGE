#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	int n, cnt = 0;
	bool arr[101];
	memset(arr, 0, sizeof(arr));
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (arr[num]) cnt++;
		else arr[num] = true;
	}
	cout << cnt;

	return 0;
}