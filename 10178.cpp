#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int candy, brother;
		cin >> candy >> brother;
		int val = candy / brother;
		int mod = candy - val * brother;
		cout << "You get " << val << " piece(s) and your dad gets " << mod << " piece(s)." << endl;
	}

	return 0;
}