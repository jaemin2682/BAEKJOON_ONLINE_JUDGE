#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <queue>

using namespace std;

int main() {
	int rec[101], value = 1;
	for (int i = 1; i <= 100; i++) {
		rec[i] = value;
		value += (i + 1)*(i + 1);
	}

	while (1) {
		int num;
		cin >> num;
		if (num == 0) break;
		cout << rec[num] << endl;
	}
	return 0;
}