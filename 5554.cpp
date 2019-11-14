#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <queue>

using namespace std;

int main() {
	int num, sum = 0;
	for (int i = 0; i < 4; i++) {
		cin >> num;
		sum += num;
	}
	cout << sum / 60 << endl << sum % 60;

	return 0;
}