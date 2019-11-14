#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <queue>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int hist;
		cin >> hist;
		for (int j = 0; j < hist; j++) cout << "=";
		cout << endl;
	}

	return 0;
}