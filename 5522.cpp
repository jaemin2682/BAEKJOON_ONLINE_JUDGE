#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		int num;
		cin >> num;
		sum += num;
	}
	cout << sum;

	return 0;
}