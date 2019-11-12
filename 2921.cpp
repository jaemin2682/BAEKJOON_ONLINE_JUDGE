#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int sum = 0;
	int num = 1;
	while (num <= n) {
		for (int j = 0; j <= num; j++) {
			sum += num + j;
		}
		num++;
	}
	cout << sum;

	return 0;
}