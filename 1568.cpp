#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <set>

using namespace std;

int main() {
	int n, cnt = 0, k = 1;
	cin >> n;
	while (n > 0) {
		if (n >= k) {
			n -= k;
			k++;			
			cnt++;
		}
		else {
			k = 1;
		}
	}
	cout << cnt;

	return 0;
}