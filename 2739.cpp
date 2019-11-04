#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int num;
	cin >> num;
	for (int i = 1; i < 10; i++) {
		cout << num << " * " << i << " = " << num * i << endl;
	}

	return 0;
}