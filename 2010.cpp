#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <set>

using namespace std;

int main() {
	int n;
	cin >> n;
	int num = 1;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		num += - 1 + input;
	}
	cout << num;

	return 0;
}