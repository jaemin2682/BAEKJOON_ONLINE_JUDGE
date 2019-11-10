#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	int sum, num, calcul = 0;
	cin >> sum;
	for (int i = 0; i < 9; i++) {
		cin >> num;
		calcul += num;
	}
	cout << sum - calcul;

	return 0;
}

